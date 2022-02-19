/**
 ******************************************************************************
 * @file    iks01a2_mems_control.h
 * @author  MEMS Application Team
 * @brief   This file contains the MEMS sensors interface for X-NUCLEO-IKS01A2
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Software License Agreement SLA0077,
 * the “License�?. You may not use this component except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        www.st.com/sla0077
 *
 ******************************************************************************
 */

 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef IKS01A2_MEMS_CONTROL_EX_H
#define IKS01A2_MEMS_CONTROL_EX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../Drivers/BSP/IKS01A2/Include/iks01a2_motion_sensors.h"
#include "../../Drivers/BSP/IKS01A2/Include/iks01a2_motion_sensors_ex.h"
#include "../../Drivers/BSP/IKS01A2/Include/iks01a2_env_sensors.h"
#include "sensor_unicleo_id.h"

#define ACC_GYR_UNICLEO_ID    LSM6DSL_UNICLEO_ID
#define MAG_UNICLEO_ID        LSM303AGR_UNICLEO_ID_MAG
#define HUM_TEMP_UNICLEO_ID   HTS221_UNICLEO_ID
#define PRESS_UNICLEO_ID      LPS22HB_UNICLEO_ID

#define MOTION_SENSOR_Axes_t IKS01A2_MOTION_SENSOR_Axes_t

void BSP_SENSOR_ACC_Init(void);
void BSP_SENSOR_GYR_Init(void);
void BSP_SENSOR_MAG_Init(void);
void BSP_SENSOR_PRESS_Init(void);
void BSP_SENSOR_TEMP_Init(void);
void BSP_SENSOR_HUM_Init(void);

void BSP_SENSOR_ACC_Enable(void);
void BSP_SENSOR_GYR_Enable(void);
void BSP_SENSOR_MAG_Enable(void);
void BSP_SENSOR_PRESS_Enable(void);
void BSP_SENSOR_TEMP_Enable(void);
void BSP_SENSOR_HUM_Enable(void);

void BSP_SENSOR_ACC_Disable(void);
void BSP_SENSOR_GYR_Disable(void);
void BSP_SENSOR_MAG_Disable(void);
void BSP_SENSOR_PRESS_Disable(void);
void BSP_SENSOR_TEMP_Disable(void);
void BSP_SENSOR_HUM_Disable(void);

void BSP_SENSOR_ACC_GetAxes(IKS01A2_MOTION_SENSOR_Axes_t *Axes);
void BSP_SENSOR_GYR_GetAxes(IKS01A2_MOTION_SENSOR_Axes_t *Axes);
void BSP_SENSOR_MAG_GetAxes(IKS01A2_MOTION_SENSOR_Axes_t *Axes);
void BSP_SENSOR_PRESS_GetValue(float *Value);
void BSP_SENSOR_TEMP_GetValue(float *Value);
void BSP_SENSOR_HUM_GetValue(float *Value);

void BSP_SENSOR_ACC_SetOutputDataRate(float Odr);
void BSP_SENSOR_GYR_SetOutputDataRate(float Odr);
void BSP_SENSOR_MAG_SetOutputDataRate(float Odr);
void BSP_SENSOR_PRESS_SetOutputDataRate(float Odr);
void BSP_SENSOR_TEMP_SetOutputDataRate(float Odr);
void BSP_SENSOR_HUM_SetOutputDataRate(float Odr);

void BSP_SENSOR_ACC_GetOutputDataRate(float *Odr);
void BSP_SENSOR_GYR_GetOutputDataRate(float *Odr);
void BSP_SENSOR_MAG_GetOutputDataRate(float *Odr);
void BSP_SENSOR_PRESS_GetOutputDataRate(float *Odr);
void BSP_SENSOR_TEMP_GetOutputDataRate(float *Odr);
void BSP_SENSOR_HUM_GetOutputDataRate(float *Odr);

void BSP_SENSOR_ACC_SetFullScale(int32_t Fullscale);
void BSP_SENSOR_GYR_SetFullScale(int32_t Fullscale);
void BSP_SENSOR_MAG_SetFullScale(int32_t Fullscale);

void BSP_SENSOR_ACC_GetFullScale(int32_t *Fullscale);
void BSP_SENSOR_GYR_GetFullScale(int32_t *Fullscale);
void BSP_SENSOR_MAG_GetFullScale(int32_t *Fullscale);

#endif /* IKS01A2_MEMS_CONTROL_EX_H */
