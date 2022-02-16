
#include "iot02a_mems_control.h"

/**
  * @brief  Initializes accelerometer
  * @param  None
  * @retval None
  */
void BSP_SENSOR_ACC_Init(void)
{
	//
  (void)BSP_MOTION_SENSOR_Init(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_ACCELERO);
}

/**
  * @brief  Initializes gyroscope
  * @param  None
  * @retval None
  */
void BSP_SENSOR_GYR_Init(void)
{
  (void)BSP_MOTION_SENSOR_Init(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_GYRO);
}

/**
  * @brief  Initializes magnetometer
  * @param  None
  * @retval None
  */
void BSP_SENSOR_MAG_Init(void)
{
  (void)BSP_MOTION_SENSOR_Init(IIS2MDC_MAGNET_INSTANCE_ID, MOTION_MAGNETO);
}

/**
  * @brief  Enables accelerometer
  * @param  None
  * @retval None
  */
void BSP_SENSOR_ACC_Enable(void)
{
  (void)BSP_MOTION_SENSOR_Enable(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_ACCELERO);
}

/**
  * @brief  Enables gyroscope
  * @param  None
  * @retval None
  */
void BSP_SENSOR_GYR_Enable(void)
{
  (void)BSP_MOTION_SENSOR_Enable(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_GYRO);
}

/**
  * @brief  Enables magnetometer
  * @param  None
  * @retval None
  */
void BSP_SENSOR_MAG_Enable(void)
{
  (void)BSP_MOTION_SENSOR_Enable(IIS2MDC_MAGNET_INSTANCE_ID, MOTION_MAGNETO);
}

/**
  * @brief  Disables accelerometer
  * @param  None
  * @retval None
  */
void BSP_SENSOR_ACC_Disable(void)
{
  (void)BSP_MOTION_SENSOR_Disable(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_ACCELERO);
}

/**
  * @brief  Disables gyroscope
  * @param  None
  * @retval None
  */
void BSP_SENSOR_GYR_Disable(void)
{
  (void)BSP_MOTION_SENSOR_Disable(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_GYRO);
}

/**
  * @brief  Disables magnetometer
  * @param  None
  * @retval None
  */
void BSP_SENSOR_MAG_Disable(void)
{
  (void)BSP_MOTION_SENSOR_Disable(IIS2MDC_MAGNET_INSTANCE_ID, MOTION_MAGNETO);
}

/**
  * @brief  Get accelerometer data
  * @param  Axes pointer to axes data structure
  * @retval None
  */
void BSP_SENSOR_ACC_GetAxes(BSP_MOTION_SENSOR_Axes_t *Axes)
{
  (void)BSP_MOTION_SENSOR_GetAxes(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_ACCELERO, Axes);
}

/**
  * @brief  Get gyroscope data
  * @param  Axes pointer to axes data structure
  * @retval None
  */
void BSP_SENSOR_GYR_GetAxes(BSP_MOTION_SENSOR_Axes_t *Axes)
{
  (void)BSP_MOTION_SENSOR_GetAxes(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_GYRO, Axes);
}

/**
  * @brief  Get magnetometer data
  * @param  Axes pointer to axes data structure
  * @retval None
  */
void BSP_SENSOR_MAG_GetAxes(BSP_MOTION_SENSOR_Axes_t *Axes)
{
  (void)BSP_MOTION_SENSOR_GetAxes(IIS2MDC_MAGNET_INSTANCE_ID, MOTION_MAGNETO, Axes);
}

/**
  * @brief  Set output data rate for accelerometer
  * @param  Odr Output Data Rate value to be set
  * @retval None
  */
void BSP_SENSOR_ACC_SetOutputDataRate(float Odr)
{
  (void)BSP_MOTION_SENSOR_SetOutputDataRate(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_ACCELERO, Odr);
}

/**
  * @brief  Set output data rate for gyroscope
  * @param  Odr Output Data Rate value to be set
  * @retval None
  */
void BSP_SENSOR_GYR_SetOutputDataRate(float Odr)
{
  (void)BSP_MOTION_SENSOR_SetOutputDataRate(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_GYRO, Odr);
}

/**
  * @brief  Set output data rate for magnetometer
  * @param  Odr Output Data Rate value to be set
  * @retval None
  */
void BSP_SENSOR_MAG_SetOutputDataRate(float Odr)
{
  (void)BSP_MOTION_SENSOR_SetOutputDataRate(IIS2MDC_MAGNET_INSTANCE_ID, MOTION_MAGNETO, Odr);
}

/**
  * @brief  Get output data rate for accelerometer
  * @param  Odr Output Data Rate value
  * @retval None
  */
void BSP_SENSOR_ACC_GetOutputDataRate(float *Odr)
{
  (void)BSP_MOTION_SENSOR_GetOutputDataRate(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_ACCELERO, Odr);
}

/**
  * @brief  Get output data rate for gyroscope
  * @param  Odr Output Data Rate value
  * @retval None
  */
void BSP_SENSOR_GYR_GetOutputDataRate(float *Odr)
{
  (void)BSP_MOTION_SENSOR_GetOutputDataRate(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_GYRO, Odr);
}

/**
  * @brief  Get output data rate for magnetometer
  * @param  Odr Output Data Rate value
  * @retval None
  */
void BSP_SENSOR_MAG_GetOutputDataRate(float *Odr)
{
  (void)BSP_MOTION_SENSOR_GetOutputDataRate(IIS2MDC_MAGNET_INSTANCE_ID, MOTION_MAGNETO, Odr);
}

/**
  * @brief  Set full scale for acclerometer
  * @param  Fullscale Fullscale value to be set
  * @retval None
  */
void BSP_SENSOR_ACC_SetFullScale(int32_t Fullscale)
{
  (void)BSP_MOTION_SENSOR_SetFullScale(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_ACCELERO, Fullscale);
}

/**
  * @brief  Set full scale for gyroscope
  * @param  Fullscale Fullscale value to be set
  * @retval None
  */
void BSP_SENSOR_GYR_SetFullScale(int32_t Fullscale)
{
  (void)BSP_MOTION_SENSOR_SetFullScale(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_GYRO, Fullscale);
}

/**
  * @brief  Set full scale for magnetometer
  * @param  Fullscale Fullscale value to be set
  * @retval None
  */
void BSP_SENSOR_MAG_SetFullScale(int32_t Fullscale)
{
  (void)BSP_MOTION_SENSOR_SetFullScale(IIS2MDC_MAGNET_INSTANCE_ID, MOTION_MAGNETO, Fullscale);
}

/**
  * @brief  Get full scale for acclerometer
  * @param  Fullscale Fullscale value
  * @retval None
  */
void BSP_SENSOR_ACC_GetFullScale(int32_t *Fullscale)
{
  (void)BSP_MOTION_SENSOR_GetFullScale(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_ACCELERO, Fullscale);
}

/**
  * @brief  Get full scale for gyroscope
  * @param  Fullscale Fullscale value
  * @retval None
  */
void BSP_SENSOR_GYR_GetFullScale(int32_t *Fullscale)
{
  (void)BSP_MOTION_SENSOR_GetFullScale(ISM330DLC_ACCELGRYO_INSTANCE_ID, MOTION_GYRO, Fullscale);
}

/**
  * @brief  Get full scale for magnetometer
  * @param  Fullscale Fullscale value
  * @retval None
  */
void BSP_SENSOR_MAG_GetFullScale(int32_t *Fullscale)
{
  (void)BSP_MOTION_SENSOR_GetFullScale(IIS2MDC_MAGNET_INSTANCE_ID, MOTION_MAGNETO, Fullscale);
}

/**
  * @brief  Get accelerometer sensor orientation
  * @param  Orientation Pointer to sensor orientation
  * @retval None
  */
void BSP_SENSOR_ACC_GetOrientation(char *Orientation)
{
  Orientation[0] = 'n';
  Orientation[1] = 'w';
  Orientation[2] = 'u';
}

/**
  * @brief  Get gyroscope sensor orientation
  * @param  Orientation Pointer to sensor orientation
  * @retval None
  */
void BSP_SENSOR_GYR_GetOrientation(char *Orientation)
{
  Orientation[0] = 'n';
  Orientation[1] = 'w';
  Orientation[2] = 'u';
}

/**
  * @brief  Get magnetometer sensor orientation
  * @param  Orientation Pointer to sensor orientation
  * @retval None
  */
void BSP_SENSOR_MAG_GetOrientation(char *Orientation)
{
  Orientation[0] = 'n';
  Orientation[1] = 'e';
  Orientation[2] = 'u';
}

// TODO:  See if these functions are supported for the accel/gyro component
// on this board
/**
  * @brief  Reads data from FSM
  * @param  Data pointer where the value is written to
  * @retval None
  */
void BSP_ACC_GYR_Read_FSM_Data(uint8_t *Data)
{
  /* FSM not available on LSM6DSL */
}

/**
  * @brief  Reads data from MLC
  * @param  Data pointer where the value is written to
  * @retval None
  */
void BSP_ACC_GYR_Read_MLC_Data(uint8_t *Data)
{
  /* MLC not available on LSM6DSL */
}
