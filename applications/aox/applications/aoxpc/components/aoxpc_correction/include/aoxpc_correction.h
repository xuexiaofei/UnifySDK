/******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

/**
 * @file
 * @brief AoX Protocol Controller angle correction.
 */

#ifndef AOXPC_CORRECTION_H
#define AOXPC_CORRECTION_H

#include "sl_status.h"

/**
 * @brief Initialize AoX Protocol Controller correction messages via MQTT.
 *
 * @return SL_STATUS_OK on success
 */
sl_status_t aoxpc_correction_init(void);

#endif // AOXPC_CORRECTION_H