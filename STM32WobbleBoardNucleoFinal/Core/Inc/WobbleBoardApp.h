/*
 * WobbleBoardApp.h
 *
 *  Created on: Feb 19, 2022
 *      Author: Beca Vessal
 */

#ifndef INC_WOBBLEBOARDAPP_H_
#define INC_WOBBLEBOARDAPP_H_

#include "iks01a2_mems_control.h"
#include "serial_protocol.h"

#define MAX_BUF_SIZE 256

class WobbleBoardApp
{
public:
	WobbleBoardApp();
	void Init();
	void Process();
	//virtual ~WobbleBoardApp();

private:

	uint8_t MagCalStatus = 0;
	MOTION_SENSOR_Axes_t MagOffset;

	MOTION_SENSOR_Axes_t AccValue;
	MOTION_SENSOR_Axes_t GyrValue;
	MOTION_SENSOR_Axes_t MagValue;

	volatile uint32_t TimeStamp = 0;

	volatile uint8_t DataStreamingDest = 1;

	volatile uint32_t SensorsEnabled = 1;
	volatile uint8_t MagCalRequest = 0;
	volatile uint8_t SensorReadRequest = 0;
	uint8_t Enabled6X = 0;
	volatile uint8_t DataLoggerActive = 0;

	char dataOut[MAX_BUF_SIZE];

	// Initialize accelerometer, gyroscope, and magnetometer
	void InitInertialSensors();
	void TIM_Config(uint32_t Freq);

	void Accelero_Sensor_Handler();
	void Gyro_Sensor_Handler();
	void Magneto_Sensor_Handler();

	void FX_Data_Handler();

	void DWT_Init();
	void DWT_Start();
	uint32_t DWT_Stop();

	void Init_Streaming_Header(TMsg* Msg);
	void Build_Reply_Header(TMsg* Msg);
	int HandleCMD(TMsg* Msg);

	void StartDataStreaming();
	void StopDataStreaming();
	void Enable6AxisMotionFusion();
	void Enable9AxisMotionFusion();

	// Callback for when the timer has elapsed
	void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
};

#endif /* INC_WOBBLEBOARDAPP_H_ */
