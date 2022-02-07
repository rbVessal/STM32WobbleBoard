/**
 ******************************************************************************
 * @file    ism330dhcx_settings.h
 * @author  MEMS Application Team
 * @brief   This file contains definitions for the ISM330DHCX settings
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Software License Agreement SLA0077,
 * the â€œLicenseâ€?. You may not use this component except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        www.st.com/sla0077
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ISM330DHCX_SETTINGS_H__
#define __ISM330DHCX_SETTINGS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define ISM330DHCX_ACC_ODR 6667.0f /* ODR = 6667Hz */

#define ISM330DHCX_ACC_FS 16 /* FS = 16g */

#define ISM330DHCX_GYRO_ODR 6667.0f /* ODR = 6667Hz */

#define ISM330DHCX_GYRO_FS 2000 /* FS = 2000dps */

#ifdef __cplusplus
}
#endif

#endif /* __ISM330DHCX_SETTINGS_H__*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
