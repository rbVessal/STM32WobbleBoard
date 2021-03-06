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
#include "motion_fx.h"

enum EMotionDataVerbosityLevels
{
	All,
	MotionFXOnly,
	MotionFXGravityXOnly,
	None
};

#define MAX_BUFFER_SIZE 256
#define NUMBER_OF_MOTIONFX_DATA_SAMPLES 50

class WobbleBoardApp
{
public:
	WobbleBoardApp();
	void Init();
	void Process();

	// User Calibration Mode is a mode in which
	// we calculate the deadzone of when a person is trying to stay still
	// A deadzone is a zone of 0 - whatever the same range of values produced
	// while the person is staying still
	void ToggleUserCalibrationMode();

	//virtual ~WobbleBoardApp();

private:

	const uint16_t USER_CALIBRATION_TIME = 4000;
	const float MIN_DEADZONE = 0.2f;

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
	uint8_t Enable6XMotionFusion = 1;
	volatile uint8_t DataLoggerActive = 0;

	char DataOut[MAX_BUFFER_SIZE];

	bool ShouldStartUserCalibrationMode = false;
	bool IsInUserCalibrationMode = false;

	// We're only interested in the motion fusion gravity X value
	// so only store a circular buffer of that corresponding to the number of samples
	// requested
	float MotionFXGravityXBuffer[NUMBER_OF_MOTIONFX_DATA_SAMPLES];

	EMotionDataVerbosityLevels MotionDataVerbosityLevel = MotionFXGravityXOnly;

	// 16 bit timer value for keeping track of when the motion data should
	// start writing to the terminal
	uint16_t MotionDataTimerTimestamp = 0;

	// 16 bit timer value for keeping track of when the user calibration should end
	int UserCalibrationTimerTimestamp = 0;

	float DeadZoneMotionFXGravityX = MIN_DEADZONE;

	int MotionFXDataBufferIndex = 0;

	// Initialize accelerometer, gyroscope, and magnetometer
	void InitInertialSensors();
	void DataStreamTimerConfig(uint32_t Freq);

	void AccelerometerSensorHandler();
	void GyroSensorHandler();
	void MagnetometerSensorHandler();

	MFX_output_t* MotionFXDataHandler();

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

	void CaptureMotionFXGravityXData();
	float CalculateDeadZone();

	void EnterUserCalibrationMode();
	void ExitUserCalibrationMode(bool Interrupted);

	// Callback for when the timer has elapsed
	//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
};

#endif /* INC_WOBBLEBOARDAPP_H_ */
