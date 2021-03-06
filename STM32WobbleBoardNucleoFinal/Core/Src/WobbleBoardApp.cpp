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

#include "gpio.h"

#include <stdio.h> // I know this is a huge library.  Ideally we shouldn't include this but I'm including it due to time constraints.
#include <string> // I know this is a huge library.  Ideally we shouldn't include this but I'm including it due to time constraints.

//#include "tim.h"


#define ALGO_FREQ  100U /* Algorithm frequency 100Hz */
#define ACC_ODR  ((float)ALGO_FREQ) /* Accelerometer output data rate */
#define ACC_FS  4 /* Accelerometer FullScale = <-4g, 4g> */
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
}

void WobbleBoardApp::Init()
{
	// Initialize Virtual COM Port
	BSP_COM_Init(COM1);

	// Initialize Timer
	BSP_IP_TIM_Init();

	// Configure Timer to run with desired algorithm frequency
	DataStreamTimerConfig(ALGO_FREQ);

	InitInertialSensors();

	// Sensor Fusion API initialization function
	MotionFX_manager_init();

	//Enable magnetometer calibration
	MotionFX_manager_MagCal_start(ALGO_PERIOD);

	// Test if calibration data are available
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

	DWTInit();

	// Start receiving messages via DMA
	UART_StartReceiveMsg();

	SensorReadRequest = 1;

	if(Enable6XMotionFusion == 1U)
	{
		Enable6AxisMotionFusion();
	}
	else
	{
		Enable9AxisMotionFusion();
	}

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
//	TMsg msg_dat;
//	TMsg msg_cmd;

//	if (UART_ReceivedMSG((TMsg *)&msg_cmd) == 1)
//	{
//		if (msg_cmd.Data[0] == DEV_ADDR)
//		{
//			HandleCMD((TMsg *)&msg_cmd);
//		}
//	}
//

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
//	int sensorDataTimerCount = __HAL_TIM_GET_COUNTER(&BSP_IP_TIM_Handle);
//	snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n Sensor counter: %d \r\n",
//			sensorDataTimerCount);
//	    printf("%s", DataOut);

	if(!IsInUserCalibrationMode && __HAL_TIM_GET_COUNTER(&BSP_IP_TIM_Handle) == 0)
	{
		SensorReadRequest = 1;
	}

//	int userCalbirationModeTimerCount = __HAL_TIM_GET_COUNTER(&htim15);
//	snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n User Calibration Mode timer counter: %d \r\n",
//			userCalbirationModeTimerCount);
//		printf("%s", DataOut);
	// When the user calibration timer reaches 0 (4 seconds)
	// then stop the user calibration mode
	if(IsInUserCalibrationMode)
	{
		CaptureMotionFXGravityXData();

		if(HAL_GetTick() - UserCalibrationTimerTimestamp  >= USER_CALIBRATION_TIME)
		{
			ExitUserCalibrationMode(false);
		}
	}

	if (SensorReadRequest == 1U)
	{
		SensorReadRequest = 0;

		// Write the sensor motion fusion data to the terminal
		MotionFXDataHandler();

		// Add the header that contains the command
		//InitStreamingHeader(&msg_dat);

		// Message length is taken from last index of msg data
		// in FX_Data Handler and add 4 to that
		//msg_dat.Len = STREAMING_MSG_LENGTH;

		//UART_SendMsg(&msg_dat);
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
//	if (!IsInUserCalibrationMode && htim->Instance == htim3.Instance)
//	{
//		SensorReadRequest = 1;
//	}
//
//	if(IsInUserCalibrationMode && htim->Instance == htim15.Instance)
//	{
//		ExitUserCalibrationMode();
//	}
//}

void WobbleBoardApp::AccelerometerSensorHandler()
{
	BSP_SENSOR_ACC_GetAxes(&AccValue);

	if(MotionDataVerbosityLevel == All)
	{

	//	Serialize_s32(&Msg->Data[3], (int32_t)AccValue.x, 4);
	//	Serialize_s32(&Msg->Data[7], (int32_t)AccValue.y, 4);
	//	Serialize_s32(&Msg->Data[11], (int32_t)AccValue.z, 4);

		snprintf(DataOut, MAX_BUFFER_SIZE, "\r\nAccelerometer Axes X: %d, Y: %d, Z: %d\r\n",
					 (int)AccValue.x, (int)AccValue.y, (int)AccValue.z);
		printf("%s", DataOut);
	}
}

void WobbleBoardApp::GyroSensorHandler()
{
	BSP_SENSOR_GYR_GetAxes(&GyrValue);

	if(MotionDataVerbosityLevel == All)
	{
	//	Serialize_s32(&Msg->Data[15], GyrValue.x, 4);
	//	Serialize_s32(&Msg->Data[19], GyrValue.y, 4);
	//	Serialize_s32(&Msg->Data[23], GyrValue.z, 4);

		snprintf(DataOut, MAX_BUFFER_SIZE, "\r\nGyro Axes X: %d, Y: %d, Z: %d\r\n",
					 (int)GyrValue.x, (int)GyrValue.y, (int)GyrValue.z);
		printf("%s", DataOut);
	}
}

void WobbleBoardApp::MagnetometerSensorHandler()
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

	if(MotionDataVerbosityLevel == All)
	{
	//	Serialize_s32(&Msg->Data[27], MagValue.x, 4);
	//	Serialize_s32(&Msg->Data[31], MagValue.y, 4);
	//	Serialize_s32(&Msg->Data[35], MagValue.z, 4);

		snprintf(DataOut, MAX_BUFFER_SIZE, "\r\nMagnetometer Axes X: %d, Y: %d, Z: %d\r\n",
					 (int)MagValue.x, (int)MagValue.y, (int)MagValue.z);
		printf("%s", DataOut);
	}
}

MFX_output_t * WobbleBoardApp::MotionFXDataHandler()
{
	// Get the 3 motion sensor data
	// and potentially write them to the terminal
	// depending on motion verbosity log level
	AccelerometerSensorHandler();
	GyroSensorHandler();
	MagnetometerSensorHandler();

	MFX_input_t dataIn;
	MFX_input_t* pDataIn = &dataIn;
	MFX_output_t dataOut;
	MFX_output_t* pDataOut = &dataOut;

	/* Convert angular velocity from [mdps] to [dps] */
	dataIn.gyro[0] = (float)GyrValue.x * FROM_MDPS_TO_DPS;
	dataIn.gyro[1] = (float)GyrValue.y * FROM_MDPS_TO_DPS;
	dataIn.gyro[2] = (float)GyrValue.z * FROM_MDPS_TO_DPS;

	/* Convert acceleration from [mg] to [g] */
	dataIn.acc[0] = (float)AccValue.x * FROM_MG_TO_G;
	dataIn.acc[1] = (float)AccValue.y * FROM_MG_TO_G;
	dataIn.acc[2] = (float)AccValue.z * FROM_MG_TO_G;

	/* Convert magnetic field intensity from [mGauss] to [uT / 50] */
	dataIn.mag[0] = (float)MagValue.x * FROM_MGAUSS_TO_UT50;
	dataIn.mag[1] = (float)MagValue.y * FROM_MGAUSS_TO_UT50;
	dataIn.mag[2] = (float)MagValue.z * FROM_MGAUSS_TO_UT50;

	/* Run Sensor Fusion algorithm */
	DWTStart();
	MotionFX_manager_run(pDataIn, pDataOut, MOTION_FX_ENGINE_DELTATIME);
	uint32_t elapsed_time_us = DWTStop();

//	(void)memcpy(&Msg->Data[39], (void *)pDataOut->quaternion, 4U * sizeof(float));
//	(void)memcpy(&Msg->Data[55], (void *)pDataOut->rotation, 3U * sizeof(float));
//	(void)memcpy(&Msg->Data[71], (void *)pDataOut->gravity, 3U * sizeof(float));
//	(void)memcpy(&Msg->Data[83], (void *)pDataOut->linear_acceleration, 3U * sizeof(float));
//
//	(void)memcpy(&Msg->Data[95], (void *) & (pDataOut->heading), sizeof(float));
//	(void)memcpy(&Msg->Data[99], (void *) & (pDataOut->headingErr), sizeof(float));
//
//	Serialize_s32(&Msg->Data[103], (int32_t)elapsed_time_us, 4);

	if(pDataOut != nullptr)
	{
		float motionFXGravityX = pDataOut->gravity[0];
		if(motionFXGravityX < 0.0f)
		{
			motionFXGravityX *= -1.0f;
		}

		// Only transmit the motion FX data if it's more than the deadzone
		if(motionFXGravityX > DeadZoneMotionFXGravityX)
		{
			if(MotionDataVerbosityLevel == All || MotionDataVerbosityLevel == MotionFXOnly)
			{
				snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Quaternion X: %.1f, Y: %.1f, Z: %.1f\r\n",
						pDataOut->quaternion[0], pDataOut->quaternion[1], pDataOut->quaternion[2]);
				printf("%s", DataOut);

				snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Rotation X: %.1f, Y: %.1f, Z: %.1f\r\n",
						pDataOut->rotation[0], pDataOut->rotation[1], pDataOut->rotation[2]);
				printf("%s", DataOut);

				snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Gravity X: %.1f, Y: %.1f, Z: %.1f\r\n",
						pDataOut->gravity[0], pDataOut->gravity[1], pDataOut->gravity[2]);
				printf("%s", DataOut);

				snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Linear Acceleration X: %.1f, Y: %.1f, Z: %.1f\r\n",
						pDataOut->linear_acceleration[0], pDataOut->linear_acceleration[1], pDataOut->linear_acceleration[2]);
				printf("%s", DataOut);

				snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Heading: %.1f\r\n",
						pDataOut->heading);
				printf("%s", DataOut);

				snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Heading Error: %.1f\r\n",
						pDataOut->headingErr);
				printf("%s", DataOut);
			}
			else if(MotionDataVerbosityLevel == MotionFXGravityXOnly)
			{
				snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Gravity X: %.1f, Y: %.1f, Z: %.1f\r\n",
										pDataOut->gravity[0], pDataOut->gravity[1], pDataOut->gravity[2]);
				printf("%s", DataOut);
			}
		}
	}

	return pDataOut;
}

/**
 * @brief  Initialize DWT register for counting clock cycles purpose
 * @param  None
 * @retval None
 */
void WobbleBoardApp::DWTInit()
{
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

	DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk; /* Disable counter */
}

void WobbleBoardApp::DWTStart()
{
	DWT->CYCCNT = 0; /* Clear count of clock cycles */
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk; /* Enable counter */
}

/**
 * @brief  Stop counting clock cycles and calculate elapsed time in [us]
 * @param  None
 * @retval Elapsed time in [us]
 */
uint32_t WobbleBoardApp::DWTStop()
{
	volatile uint32_t cycles_count = 0U;
	uint32_t system_core_clock_mhz = 0U;

	DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk; /* Disable counter */
	cycles_count = DWT->CYCCNT; /* Read count of clock cycles */

	/* Calculate elapsed time in [us] */
	system_core_clock_mhz = SystemCoreClock / 1000000U;
	return cycles_count / system_core_clock_mhz;
}

void WobbleBoardApp::InitStreamingHeader(TMsg* Msg)
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
void WobbleBoardApp::BuildReplyHeader(TMsg *Msg)
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

		Enable6XMotionFusion = Msg->Data[3];

		if (Enable6XMotionFusion == 1U)
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

	//HAL_TIM_Base_Start_IT(&BSP_IP_TIM_Handle);

	// Start the data stream timer
	HAL_TIM_Base_Start(&BSP_IP_TIM_Handle);

	DataLoggerActive = 1;
	SensorsEnabled = 1;
}

void WobbleBoardApp::StopDataStreaming()
{
	DataLoggerActive = 0;
	//HAL_TIM_Base_Stop_IT(&BSP_IP_TIM_Handle);

	// Stop the data stream timer
	HAL_TIM_Base_Stop(&BSP_IP_TIM_Handle);

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

void WobbleBoardApp::DataStreamTimerConfig(uint32_t Freq)
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

void WobbleBoardApp::ToggleUserCalibrationMode()
{
	ShouldStartUserCalibrationMode = !ShouldStartUserCalibrationMode;

	if(ShouldStartUserCalibrationMode)
	{
		EnterUserCalibrationMode();
	}
	else
	{
		ExitUserCalibrationMode(true);
	}
}

void WobbleBoardApp::CaptureMotionFXGravityXData()
{
	MFX_output_t* pMotionFXData = MotionFXDataHandler();
	if(pMotionFXData != nullptr)
	{
		MotionFXGravityXBuffer[MotionFXDataBufferIndex] = pMotionFXData->gravity[0];

		snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n Captured MotionFusion Gravity X from User: %.1f\r\n",
				pMotionFXData->gravity[0]);
		printf("%s", DataOut);

		MotionFXDataBufferIndex++;

		// Make sure we don't exceed the buffer length and wrap around
		// instead to keep grabbing data
		if(MotionFXDataBufferIndex >= NUMBER_OF_MOTIONFX_DATA_SAMPLES)
		{
			MotionFXDataBufferIndex = 0;
		}
	}
}

// Get the average motion fusion gravity X over a time period
float WobbleBoardApp::CalculateDeadZone()
{
	float accumulatedMotionFXGravityX = 0.0f;
	for(int i = 0; i < NUMBER_OF_MOTIONFX_DATA_SAMPLES; i++)
	{
		float motionFusionGravityX = MotionFXGravityXBuffer[i];

		// It's possible that it could be negative and we want to
		// negate that so they don't cancel each other out
		// when accumulating the gravity X
		if(motionFusionGravityX < 0.0f)
		{
			motionFusionGravityX *= -1.0f;
		}

//		snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Gravity X from User: %.1f\r\n",
//				motionFusionGravityX);
//			printf("%s", DataOut);

		accumulatedMotionFXGravityX += motionFusionGravityX;
	}

	float averageMotionFXGravityX = accumulatedMotionFXGravityX / NUMBER_OF_MOTIONFX_DATA_SAMPLES;
	if(averageMotionFXGravityX < MIN_DEADZONE)
	{
		averageMotionFXGravityX = MIN_DEADZONE;
	}

	snprintf(DataOut, MAX_BUFFER_SIZE, "\r\n MotionFusion Gravity X DeadZone Calculated For User: %.1f\r\n",
			averageMotionFXGravityX);
	printf("%s", DataOut);

	return averageMotionFXGravityX;
}

void WobbleBoardApp::EnterUserCalibrationMode()
{
	std::string printString = "Entered User Calibration Mode\r\n";
	int printStringLength = printString.length();

	char PrintBuffer[printStringLength];
	sprintf(PrintBuffer, printString.c_str());
	HAL_UART_Transmit(&hcom_uart[COM1], (uint8_t *)PrintBuffer, printStringLength, 5000);

	StopDataStreaming();

	// Start the interrupt of timer 15 that is specifically
	// for the user calibration mode timer
	//HAL_TIM_Base_Start_IT(&htim15);

	//UserCalibrationTimerTimestamp = __HAL_TIM_GET_COUNTER(&htim15);

	// Start the user calibration timer
	//HAL_TIM_Base_Start(&htim15);

	// Get the elapsed time since start of program
	// we will use this to compare against the new
	// elapsed time every tick cycle to see if we have passed
	// the user calibration time to end the user calibration mode
	UserCalibrationTimerTimestamp = HAL_GetTick();

	IsInUserCalibrationMode = true;

	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PinState::GPIO_PIN_SET);
}

void WobbleBoardApp::ExitUserCalibrationMode(bool Interrupted)
{
	IsInUserCalibrationMode = false;
	ShouldStartUserCalibrationMode = false;

	MotionFXDataBufferIndex = 0;

	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PinState::GPIO_PIN_RESET);

	if(!Interrupted)
	{
		DeadZoneMotionFXGravityX = CalculateDeadZone();
	}

	// Clear out the MotionFXGravityXBuffer
	for(int i = 0; i < NUMBER_OF_MOTIONFX_DATA_SAMPLES; i++)
	{
		MotionFXGravityXBuffer[i] = 0.0f;
	}

	if(Interrupted)
	{
		std::string printString = "Exited User Calibration Mode: Interrupted - Will Discard User Calibration Data\r\n";
		int printStringLength = printString.length();

		char PrintBuffer[printStringLength];
		sprintf(PrintBuffer, printString.c_str());
		HAL_UART_Transmit(&hcom_uart[COM1], (uint8_t *)PrintBuffer, printStringLength, 5000);
	}
	else
	{
		std::string printString = "Exited User Calibration Mode\r\n";
		int printStringLength = printString.length();

		char PrintBuffer[printStringLength];
		sprintf(PrintBuffer, printString.c_str());
		HAL_UART_Transmit(&hcom_uart[COM1], (uint8_t *)PrintBuffer, printStringLength, 5000);
	}

	// Stop the user calibration timer interrupt mode
	//HAL_TIM_Base_Stop_IT(&htim15);


	// Stop the user calibration timer
	//HAL_TIM_Base_Stop(&htim15);

	// Start streaming out the motion data again
	StartDataStreaming();
}

//WobbleBoardApp::~WobbleBoardApp()
//{
//	// TODO Auto-generated destructor stub
//}

