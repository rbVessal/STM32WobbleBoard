
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef IOT02A_MEMS_CONTROL_H
#define IOT02A_MEMS_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "b_u585i_iot02a_motion_sensors.h"
#include "sensor_unicleo_id.h"

#define ACC_GYR_UNICLEO_ID    ISM330DLC_UNICLEO_ID
#define MAG_UNICLEO_ID        IIS2MDC_UNICLEO_ID

#define MOTION_SENSOR_Axes_t BSP_MOTION_SENSOR_Axes_t

void BSP_SENSOR_ACC_Init(void);
void BSP_SENSOR_GYR_Init(void);
void BSP_SENSOR_MAG_Init(void);

void BSP_SENSOR_ACC_Enable(void);
void BSP_SENSOR_GYR_Enable(void);
void BSP_SENSOR_MAG_Enable(void);

void BSP_SENSOR_ACC_Disable(void);
void BSP_SENSOR_GYR_Disable(void);
void BSP_SENSOR_MAG_Disable(void);

void BSP_SENSOR_ACC_GetAxes(BSP_MOTION_SENSOR_Axes_t *Axes);
void BSP_SENSOR_GYR_GetAxes(BSP_MOTION_SENSOR_Axes_t *Axes);
void BSP_SENSOR_MAG_GetAxes(BSP_MOTION_SENSOR_Axes_t *Axes);

void BSP_SENSOR_ACC_SetOutputDataRate(float Odr);
void BSP_SENSOR_GYR_SetOutputDataRate(float Odr);
void BSP_SENSOR_MAG_SetOutputDataRate(float Odr);

void BSP_SENSOR_ACC_GetOutputDataRate(float *Odr);
void BSP_SENSOR_GYR_GetOutputDataRate(float *Odr);
void BSP_SENSOR_MAG_GetOutputDataRate(float *Odr);

void BSP_SENSOR_ACC_SetFullScale(int32_t Fullscale);
void BSP_SENSOR_GYR_SetFullScale(int32_t Fullscale);
void BSP_SENSOR_MAG_SetFullScale(int32_t Fullscale);

void BSP_SENSOR_ACC_GetFullScale(int32_t *Fullscale);
void BSP_SENSOR_GYR_GetFullScale(int32_t *Fullscale);
void BSP_SENSOR_MAG_GetFullScale(int32_t *Fullscale);

void BSP_SENSOR_ACC_GetOrientation(char *Orientation);
void BSP_SENSOR_GYR_GetOrientation(char *Orientation);
void BSP_SENSOR_MAG_GetOrientation(char *Orientation);

void BSP_ACC_GYR_Read_FSM_Data(uint8_t *Data);
void BSP_ACC_GYR_Read_MLC_Data(uint8_t *Data);

#endif /* IOT02A_MEMS_CONTROL_H */
