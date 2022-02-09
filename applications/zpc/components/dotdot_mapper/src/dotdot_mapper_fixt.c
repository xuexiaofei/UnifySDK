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

// Includes from other component
#include "sl_status.h"

// Includes from this component
#include "dotdot_mapper_fixt.h"
#include "basic_cluster_mapper.h"
#include "on_off_cluster_mapper.h"
#include "level_cluster_mapper.h"
#include "thermostat_cluster_mapper.h"
#include "sl_status.h"
#include "door_lock_cluster_mapper.h"
#include "identify_cluster_mapper.h"

sl_status_t dotdot_mapper_init()
{
  // Initializes all clusters individually.
  // Abort and return false if any of them fails.

  // Basic Cluster
  if (!basic_cluster_mapper_init()) {
    return SL_STATUS_FAIL;
  }

  // OnOff Cluster
  if (!on_off_cluster_mapper_init()) {
    return SL_STATUS_FAIL;
  }

  // Level Cluster
  if (!level_cluster_mapper_init()) {
    return SL_STATUS_FAIL;
  }

  // Thermostat Cluster
  if (!thermostat_cluster_mapper_init()) {
    return SL_STATUS_FAIL;
  }

  // DooLock Cluster
  if (!door_lock_cluster_mapper_init()) {
    return SL_STATUS_FAIL;
  }

  // Identify Cluster
  if (!identify_cluster_mapper_init()) {
    return SL_STATUS_FAIL;
  }

  return SL_STATUS_OK;
}

int dotdot_mapper_teardown()
{
  // Basic Cluster
  basic_cluster_mapper_teardown();
  // OnOff Cluster
  on_off_cluster_mapper_teardown();
  // Level Cluster
  level_cluster_mapper_teardown();
  // Thermostat Cluster
  thermostat_cluster_mapper_teardown();
  //DoorLock Cluster
  door_lock_cluster_mapper_teardown();
  return 0;
}
