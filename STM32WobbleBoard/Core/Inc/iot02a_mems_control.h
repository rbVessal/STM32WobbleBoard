 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MEMS_CONTROL_H
#define MEMS_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "b_u585i_iot02a_motion_sensors.h"

void BSP_SENSOR_ACC_GetOrientation(char *Orientation);
void BSP_SENSOR_GYR_GetOrientation(char *Orientation);
void BSP_SENSOR_MAG_GetOrientation(char *Orientation);

void BSP_SENSOR_ACC_Read_Register(uint8_t Reg, uint8_t *Data);
void BSP_SENSOR_GYR_Read_Register(uint8_t Reg, uint8_t *Data);
void BSP_SENSOR_MAG_Read_Register(uint8_t Reg, uint8_t *Data);

void BSP_SENSOR_ACC_Write_Register(uint8_t Reg, uint8_t Data);
void BSP_SENSOR_GYR_Write_Register(uint8_t Reg, uint8_t Data);
void BSP_SENSOR_MAG_Write_Register(uint8_t Reg, uint8_t Data);

void BSP_SENSOR_ACC_SetDRDYMode(uint8_t Mode);
void BSP_SENSOR_GYR_SetDRDYMode(uint8_t Mode);
void BSP_SENSOR_ACC_SetDRDYInt(uint8_t Enable);
void BSP_SENSOR_GYR_SetDRDYInt(uint8_t Enable);
void BSP_SENSOR_ACC_GetDRDYStatus(uint8_t *Status);

void BSP_ACC_GYR_Read_FSM_Data(uint8_t *Data);
void BSP_ACC_GYR_Read_MLC_Data(uint8_t *Data);

#endif /* MEMS_CONTROL_H */
