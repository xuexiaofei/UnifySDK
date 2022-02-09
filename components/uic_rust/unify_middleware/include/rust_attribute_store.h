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

#ifndef RUST_ATTRIBUTE_STORE_H
#define RUST_ATTRIBUTE_STORE_H
#include "sl_status.h"

/**
 * @brief Initialize Rust attribute store
 * 
 * @returns SL_STATUS_OK in case of success, any other code in case of error.
 */
sl_status_t rust_attribute_store_init();

#endif
