/*
 * WobbleBoardApp.cpp
 *
 *  Created on: Feb 19, 2022
 *      Author: Beca Vessal
 */

#include "WobbleBoardApp.h"

#include "stm32l4xx_nucleo.h"
#include "stm32l4xx_hal.h"
#include "system_stm32l4xx.h"

#include "serial_cmd.h"
#include "serial_protocol.h"

#include "motion_fx_manager.h"
#include "com.h"
#include "bsp_ip_conf.h"

//#include "tim.h"


#define ALGO_FREQ  100U /* Algorithm frequency 100Hz */
#define ACC_ODR  ((float)ALGO_FREQ)
#define ACC_FS  4 /* FS = <-4g, 4g> */
#define ALGO_PERIOD  (1000U / ALGO_FREQ) /* Algorithm period [ms] */

#define ACCELEROMETER_SENSOR  0x00000010U
#define GYROSCOPE_SENSOR      0x00000020U
#define MAGNETIC_SENSOR       0x00000040U

#define MOTION_FX_ENGINE_DELTATIME  0.01f

#define FROM_MG_TO_G  0.001f
#define FROM_G_TO_MG  1000.0f
#define FROM_MDPS_TO_DPS  0.001f
#define FROM_DPS_TO_MDPS  1000.0f
#define FROM_MGAUSS_TO_UT50  (0.1f/50.0f)
#define FROM_UT50_TO_MGAUSS  500.0f

#define STREAMING_MSG_LENGTH  107

#define DEV_ADDR  50U

WobbleBoardApp::WobbleBoardApp()
{
	// TODO Auto-generated constructor stub

}

void WobbleBoardApp::Init()
{
	/* Initialize Virtual COM Port */
	BSP_COM_Init(COM1);

	/* Initialize Timer */
	BSP_IP_TIM_Init();

	/* Configure Timer to run with desired algorithm frequency */
	TIM_Config(ALGO_FREQ);

	InitInertialSensors();

	// Sensor Fusion API initialization function
	MotionFX_manager_init();

	//Enable magnetometer calibration
	MotionFX_manager_MagCal_start(ALGO_PERIOD);

	/* Test if calibration data are available */
	MFX_MagCal_output_t mag_cal_test;
	MotionFX_MagCal_getParams(&mag_cal_test);

	// If calibration data are available load HI coefficients
	if (mag_cal_test.cal_quality == MFX_MAGCALGOOD)
	{
		float ans_float;
		ans_float = (mag_cal_test.hi_bias[0] * FROM_UT50_TO_MGAUSS);
		MagOffset.x = (int32_t)ans_float;
		ans_float = (mag_cal_test.hi_bias[1] * FROM_UT50_TO_MGAUSS);
		MagOffset.y = (int32_t)ans_float;
		ans_float = (mag_cal_test.hi_bias[2] * FROM_UT50_TO_MGAUSS);
		MagOffset.z = (int32_t)ans_float;

		MagCalStatus = 1;
	}

	DWT_Init();

	// Start receiving messages via DMA
	UART_StartReceiveMsg();

	SensorReadRequest = 1;

	Enable9AxisMotionFusion();

	StartDataStreaming();
}

void WobbleBoardApp::InitInertialSensors()
{
	BSP_SENSOR_ACC_Init();
	BSP_SENSOR_GYR_Init();
	BSP_SENSOR_MAG_Init();

	BSP_SENSOR_ACC_SetOutputDataRate(ACC_ODR);
	BSP_SENSOR_ACC_SetFullScale(ACC_FS);
}

void WobbleBoardApp::Process()
{
	TMsg msg_dat;
	TMsg msg_cmd;

//	if (UART_ReceivedMSG((TMsg *)&msg_cmd) == 1)
//	{
//		if (msg_cmd.Data[0] == DEV_ADDR)
//		{
//			HandleCMD((TMsg *)&msg_cmd);
//		}
//	}
//
//	HandleMSG((TMsg *)&msg_cmd);

	if (MagCalRequest == 1U)
	{
		MagCalRequest = 0;

		/* Reset magnetometer calibration value*/
		MagCalStatus = 0;
		MagOffset.x = 0;
		MagOffset.y = 0;
		MagOffset.z = 0;

		/* Enable magnetometer calibration */
		MotionFX_manager_MagCal_start(ALGO_PERIOD);
	}

	// When the timer counter reaches 0 then read the
	// motion sensor data
	// TODO:  Figure out why the timer elapsed callback wasn't working
	if(__HAL_TIM_GET_COUNTER(&BSP_IP_TIM_Handle) == 0)
	{
		SensorReadRequest = 1;
	}

	if (SensorReadRequest == 1U)
	{
		SensorReadRequest = 0;

		/* Acquire data from enabled sensors and fill Msg stream */
		Accelero_Sensor_Handler(&msg_dat);
		Gyro_Sensor_Handler(&msg_dat);
		Magneto_Sensor_Handler(&msg_dat);

		/* Sensor Fusion specific part */
		FX_Data_Handler(&msg_dat);

		/* Send data stream */
		Init_Streaming_Header(&msg_dat);
		// Message length is taken from last index of msg data
		// in FX_Data Handler and add 4 to that
		msg_dat.Len = STREAMING_MSG_LENGTH;

		UART_SendMsg(&msg_dat);
	}
}

/**
 * @brief  Period elapsed callback
 * @param  htim pointer to a TIM_HandleTypeDef structure that contains
 *              the configuration information for TIM module.
 * @retval None
 */
//void WobbleBoardApp::HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//  if (htim->Instance == htim3.Instance)
//  {
//    SensorReadRequest = 1;
//  }
//}

void WobbleBoardApp::Accelero_Sensor_Handler(TMsg* Msg)
{
	BSP_SENSOR_ACC_GetAxes(&AccValue);

	Serialize_s32(&Msg->Data[3], (int32_t)AccValue.x, 4);
	Serialize_s32(&Msg->Data[7], (int32_t)AccValue.y, 4);
	Serialize_s32(&Msg->Data[11], (int32_t)AccValue.z, 4);
}

void WobbleBoardApp::Gyro_Sensor_Handler(TMsg* Msg)
{
	BSP_SENSOR_GYR_GetAxes(&GyrValue);

	Serialize_s32(&Msg->Data[15], GyrValue.x, 4);
	Serialize_s32(&Msg->Data[19], GyrValue.y, 4);
	Serialize_s32(&Msg->Data[23], GyrValue.z, 4);
}

void WobbleBoardApp::Magneto_Sensor_Handler(TMsg* Msg)
{
	float ans_float;
	MFX_MagCal_input_t mag_data_in;
	MFX_MagCal_output_t mag_data_out;

	BSP_SENSOR_MAG_GetAxes(&MagValue);

	if (MagCalStatus == 0U)
	{
		mag_data_in.mag[0] = (float)MagValue.x * FROM_MGAUSS_TO_UT50;
		mag_data_in.mag[1] = (float)MagValue.y * FROM_MGAUSS_TO_UT50;
		mag_data_in.mag[2] = (float)MagValue.z * FROM_MGAUSS_TO_UT50;

		mag_data_in.time_stamp = (int)TimeStamp;
		TimeStamp += (uint32_t)ALGO_PERIOD;

		MotionFX_manager_MagCal_run(&mag_data_in, &mag_data_out);

		if (mag_data_out.cal_quality == MFX_MAGCALGOOD)
		{
			MagCalStatus = 1;

			ans_float = (mag_data_out.hi_bias[0] * FROM_UT50_TO_MGAUSS);
			MagOffset.x = (int32_t)ans_float;
			ans_float = (mag_data_out.hi_bias[1] * FROM_UT50_TO_MGAUSS);
			MagOffset.y = (int32_t)ans_float;
			ans_float = (mag_data_out.hi_bias[2] * FROM_UT50_TO_MGAUSS);
			MagOffset.z = (int32_t)ans_float;

			/* Disable magnetometer calibration */
			MotionFX_manager_MagCal_stop(ALGO_PERIOD);
		}
	}

	MagValue.x = (int32_t)(MagValue.x - MagOffset.x);
	MagValue.y = (int32_t)(MagValue.y - MagOffset.y);
	MagValue.z = (int32_t)(MagValue.z - MagOffset.z);

	Serialize_s32(&Msg->Data[27], MagValue.x, 4);
	Serialize_s32(&Msg->Data[31], MagValue.y, 4);
	Serialize_s32(&Msg->Data[35], MagValue.z, 4);
}

void WobbleBoardApp::FX_Data_Handler(TMsg* Msg)
{
	uint32_t elapsed_time_us = 0U;
	MFX_input_t data_in;
	MFX_input_t *pdata_in = &data_in;
	MFX_output_t data_out;
	MFX_output_t *pdata_out = &data_out;

	/* Convert angular velocity from [mdps] to [dps] */
	data_in.gyro[0] = (float)GyrValue.x * FROM_MDPS_TO_DPS;
	data_in.gyro[1] = (float)GyrValue.y * FROM_MDPS_TO_DPS;
	data_in.gyro[2] = (float)GyrValue.z * FROM_MDPS_TO_DPS;

	/* Convert acceleration from [mg] to [g] */
	data_in.acc[0] = (float)AccValue.x * FROM_MG_TO_G;
	data_in.acc[1] = (float)AccValue.y * FROM_MG_TO_G;
	data_in.acc[2] = (float)AccValue.z * FROM_MG_TO_G;

	/* Convert magnetic field intensity from [mGauss] to [uT / 50] */
	data_in.mag[0] = (float)MagValue.x * FROM_MGAUSS_TO_UT50;
	data_in.mag[1] = (float)MagValue.y * FROM_MGAUSS_TO_UT50;
	data_in.mag[2] = (float)MagValue.z * FROM_MGAUSS_TO_UT50;

	/* Run Sensor Fusion algorithm */
	DWT_Start();
	MotionFX_manager_run(pdata_in, pdata_out, MOTION_FX_ENGINE_DELTATIME);
	elapsed_time_us = DWT_Stop();

	(void)memcpy(&Msg->Data[39], (void *)pdata_out->quaternion, 4U * sizeof(float));
	(void)memcpy(&Msg->Data[55], (void *)pdata_out->rotation, 3U * sizeof(float));
	(void)memcpy(&Msg->Data[71], (void *)pdata_out->gravity, 3U * sizeof(float));
	(void)memcpy(&Msg->Data[83], (void *)pdata_out->linear_acceleration, 3U * sizeof(float));

	(void)memcpy(&Msg->Data[95], (void *) & (pdata_out->heading), sizeof(float));
	(void)memcpy(&Msg->Data[99], (void *) & (pdata_out->headingErr), sizeof(float));

	Serialize_s32(&Msg->Data[103], (int32_t)elapsed_time_us, 4);
}

/**
 * @brief  Initialize DWT register for counting clock cycles purpose
 * @param  None
 * @retval None
 */
void WobbleBoardApp::DWT_Init()
{
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

	DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk; /* Disable counter */
}

void WobbleBoardApp::DWT_Start()
{
	DWT->CYCCNT = 0; /* Clear count of clock cycles */
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk; /* Enable counter */
}

/**
 * @brief  Stop counting clock cycles and calculate elapsed time in [us]
 * @param  None
 * @retval Elapsed time in [us]
 */
uint32_t WobbleBoardApp::DWT_Stop()
{
	volatile uint32_t cycles_count = 0U;
	uint32_t system_core_clock_mhz = 0U;

	DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk; /* Disable counter */
	cycles_count = DWT->CYCCNT; /* Read count of clock cycles */

	/* Calculate elapsed time in [us] */
	system_core_clock_mhz = SystemCoreClock / 1000000U;
	return cycles_count / system_core_clock_mhz;
}

void WobbleBoardApp::Init_Streaming_Header(TMsg* Msg)
{
	Msg->Data[0] = DataStreamingDest;
	Msg->Data[1] = DEV_ADDR;
	Msg->Data[2] = CMD_Start_Data_Streaming;
	Msg->Len = 3;
}

/**
 * @brief  Build the reply header
 * @param  Msg the pointer to the message to be built
 * @retval None
 */
void WobbleBoardApp::Build_Reply_Header(TMsg *Msg)
{
  Msg->Data[0] = Msg->Data[1];
  Msg->Data[1] = DEV_ADDR;
  Msg->Data[2] += CMD_Reply_Add;
}

/**
 * @brief  Handle a message
 * @param  Msg the pointer to the message to be handled
 * @retval 1 if the message is correctly handled, 0 otherwise
 */
int WobbleBoardApp::HandleCMD(TMsg* Msg)
{
/*  DestAddr | SouceAddr | CMD | PAYLOAD
 *      1          1        1       N
 */
  int hasHandledMessage = 1;

  if (Msg->Len < 2U)
  {
	return 0;
  }

  if (Msg->Data[0] != DEV_ADDR)
  {
	return 0;
  }

  switch (Msg->Data[2])   /* CMD */
  {
	case CMD_Start_Data_Streaming:
	{
	  if (Msg->Len < 3U)
	  {
		return 0;
	  }

	  StartDataStreaming();

	  break;
	}

	case CMD_Stop_Data_Streaming:
	{
	  if (Msg->Len < 3U)
	  {
		return 0;
	  }

	  StopDataStreaming();

	  break;
	}

	case CMD_ChangeSF:
	{
		if (Msg->Len < 3U)
		{
			return 0;
		}

		Enabled6X = Msg->Data[3];

		if (Enabled6X == 1U)
		{
			Enable6AxisMotionFusion();
		}
		else
		{
			Enable9AxisMotionFusion();
		}

		break;
	}

	default:
	{
		hasHandledMessage = 0;
		break;
	}
  }

  return hasHandledMessage;
}

void WobbleBoardApp::StartDataStreaming()
{
	BSP_SENSOR_ACC_Enable();
	BSP_SENSOR_GYR_Enable();
	BSP_SENSOR_MAG_Enable();

	HAL_TIM_Base_Start_IT(&BSP_IP_TIM_Handle);

	DataLoggerActive = 1;
}

void WobbleBoardApp::StopDataStreaming()
{
	DataLoggerActive = 0;
	HAL_TIM_Base_Stop_IT(&BSP_IP_TIM_Handle);

	/* Disable all sensors */
	BSP_SENSOR_ACC_Disable();
	BSP_SENSOR_GYR_Disable();
	BSP_SENSOR_MAG_Disable();

	SensorsEnabled = 0;
}

void WobbleBoardApp::Enable6AxisMotionFusion()
{
	MotionFX_manager_stop_9X();
	MotionFX_manager_start_6X();
}

void WobbleBoardApp::Enable9AxisMotionFusion()
{
	MotionFX_manager_stop_6X();
	MotionFX_manager_start_9X();
}

void WobbleBoardApp::TIM_Config(uint32_t Freq)
{
  const uint32_t tim_counter_clock = 2000; /* TIM counter clock 2 kHz */
  uint32_t prescaler_value = (uint32_t)((SystemCoreClock / tim_counter_clock) - 1);
  uint32_t period = (tim_counter_clock / Freq) - 1;

  BSP_IP_TIM_Handle.Init.Prescaler = prescaler_value;
  BSP_IP_TIM_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  BSP_IP_TIM_Handle.Init.Period = period;
  BSP_IP_TIM_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  BSP_IP_TIM_Handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&BSP_IP_TIM_Handle) != HAL_OK)
  {
    Error_Handler();
  }
}

//WobbleBoardApp::~WobbleBoardApp()
//{
//	// TODO Auto-generated destructor stub
//}
