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

#define MAX_BUFFER_SIZE 256

class WobbleBoardApp
{
public:
	WobbleBoardApp();
	void Init();
	void Process();

	// User Calbiration Mode is a mode in which
	// we calculate the deadzone of when a person is trying to stay still
	// A deadzone is a zone of 0 - whatever the same range of values produced
	// while the person is staying still
	void EnterUserCalibrationMode();
	void ExitUserCalibrationMode();
	void ToggleUserCalibrationMode();

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

	char DataOut[MAX_BUFFER_SIZE];

	bool ShouldStartUserCalibrationMode = false;

	// Initialize accelerometer, gyroscope, and magnetometer
	void InitInertialSensors();
	void DataStreamTimerConfig(uint32_t Freq);

	void AccelerometerSensorHandler();
	void GyroSensorHandler();
	void MagnetometerSensorHandler();

	void MotionFXDataHandler();

	void DWTInit();
	void DWTStart();
	uint32_t DWTStop();

	void InitStreamingHeader(TMsg* Msg);
	void BuildReplyHeader(TMsg* Msg);
	int HandleCMD(TMsg* Msg);

	void StartDataStreaming();
	void StopDataStreaming();
	void Enable6AxisMotionFusion();
	void Enable9AxisMotionFusion();

	void CalculateDeadZone();

	// Callback for when the timer has elapsed
	void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
};

#endif /* INC_WOBBLEBOARDAPP_H_ */
