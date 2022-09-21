/******************************************************************************
 * # License
 * <b>Copyright 2022 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

// This file is generated by ZCL Advanced Platform generator. Please don't edit manually.

#include "dotdot_cluster_id_definitions.h"
#include <string.h>

const char* uic_dotdot_get_cluster_name(dotdot_cluster_id_t cluster_id) {
  switch(cluster_id) {
  case DOTDOT_BASIC_CLUSTER_ID:
    return "Basic";
  case DOTDOT_POWER_CONFIGURATION_CLUSTER_ID:
    return "PowerConfiguration";
  case DOTDOT_DEVICE_TEMPERATURE_CONFIGURATION_CLUSTER_ID:
    return "DeviceTemperatureConfiguration";
  case DOTDOT_IDENTIFY_CLUSTER_ID:
    return "Identify";
  case DOTDOT_GROUPS_CLUSTER_ID:
    return "Groups";
  case DOTDOT_SCENES_CLUSTER_ID:
    return "Scenes";
  case DOTDOT_ON_OFF_CLUSTER_ID:
    return "OnOff";
  case DOTDOT_LEVEL_CLUSTER_ID:
    return "Level";
  case DOTDOT_ALARMS_CLUSTER_ID:
    return "Alarms";
  case DOTDOT_TIME_CLUSTER_ID:
    return "Time";
  case DOTDOT_COMMISSIONING_CLUSTER_ID:
    return "Commissioning";
  case DOTDOT_OTA_UPGRADE_CLUSTER_ID:
    return "OTAUpgrade";
  case DOTDOT_POLL_CONTROL_CLUSTER_ID:
    return "PollControl";
  case DOTDOT_SHADE_CONFIGURATION_CLUSTER_ID:
    return "ShadeConfiguration";
  case DOTDOT_DOOR_LOCK_CLUSTER_ID:
    return "DoorLock";
  case DOTDOT_WINDOW_COVERING_CLUSTER_ID:
    return "WindowCovering";
  case DOTDOT_BARRIER_CONTROL_CLUSTER_ID:
    return "BarrierControl";
  case DOTDOT_PUMP_CONFIGURATION_AND_CONTROL_CLUSTER_ID:
    return "PumpConfigurationAndControl";
  case DOTDOT_THERMOSTAT_CLUSTER_ID:
    return "Thermostat";
  case DOTDOT_FAN_CONTROL_CLUSTER_ID:
    return "FanControl";
  case DOTDOT_DEHUMIDIFICATION_CONTROL_CLUSTER_ID:
    return "DehumidificationControl";
  case DOTDOT_THERMOSTAT_USER_INTERFACE_CONFIGURATION_CLUSTER_ID:
    return "ThermostatUserInterfaceConfiguration";
  case DOTDOT_COLOR_CONTROL_CLUSTER_ID:
    return "ColorControl";
  case DOTDOT_BALLAST_CONFIGURATION_CLUSTER_ID:
    return "BallastConfiguration";
  case DOTDOT_ILLUMINANCE_MEASUREMENT_CLUSTER_ID:
    return "IlluminanceMeasurement";
  case DOTDOT_ILLUMINANCE_LEVEL_SENSING_CLUSTER_ID:
    return "IlluminanceLevelSensing";
  case DOTDOT_TEMPERATURE_MEASUREMENT_CLUSTER_ID:
    return "TemperatureMeasurement";
  case DOTDOT_PRESSURE_MEASUREMENT_CLUSTER_ID:
    return "PressureMeasurement";
  case DOTDOT_FLOW_MEASUREMENT_CLUSTER_ID:
    return "FlowMeasurement";
  case DOTDOT_RELATIVITY_HUMIDITY_CLUSTER_ID:
    return "RelativityHumidity";
  case DOTDOT_OCCUPANCY_SENSING_CLUSTER_ID:
    return "OccupancySensing";
  case DOTDOT_PH_MEASUREMENT_CLUSTER_ID:
    return "PhMeasurement";
  case DOTDOT_ELECTRICAL_CONDUCTIVITY_MEASUREMENT_CLUSTER_ID:
    return "ElectricalConductivityMeasurement";
  case DOTDOT_WIND_SPEED_MEASUREMENT_CLUSTER_ID:
    return "WindSpeedMeasurement";
  case DOTDOT_CARBON_MONOXIDE_CLUSTER_ID:
    return "CarbonMonoxide";
  case DOTDOT_IAS_ZONE_CLUSTER_ID:
    return "IASZone";
  case DOTDOT_IASACE_CLUSTER_ID:
    return "IASACE";
  case DOTDOT_IASWD_CLUSTER_ID:
    return "IASWD";
  case DOTDOT_METERING_CLUSTER_ID:
    return "Metering";
  case DOTDOT_ELECTRICAL_MEASUREMENT_CLUSTER_ID:
    return "ElectricalMeasurement";
  case DOTDOT_DIAGNOSTICS_CLUSTER_ID:
    return "Diagnostics";
  case DOTDOT_TOUCHLINK_COMMISSIONING_CLUSTER_ID:
    return "TouchlinkCommissioning";
  case DOTDOT_PROTOCOL_CONTROLLER_RF_TELEMETRY_CLUSTER_ID:
    return "ProtocolController-RFTelemetry";
  case DOTDOT_STATE_CLUSTER_ID:
    return "State";
  case DOTDOT_BINDING_CLUSTER_ID:
    return "Binding";
  case DOTDOT_SYSTEM_METRICS_CLUSTER_ID:
    return "SystemMetrics";
  case DOTDOT_APPLICATION_MONITORING_CLUSTER_ID:
    return "ApplicationMonitoring";
  case DOTDOT_NAME_AND_LOCATION_CLUSTER_ID:
    return "NameAndLocation";
  case DOTDOT_CONFIGURATION_PARAMETERS_CLUSTER_ID:
    return "ConfigurationParameters";
  case DOTDOT_AOX_LOCATOR_CLUSTER_ID:
    return "AoXLocator";
  case DOTDOT_AOX_POSITION_ESTIMATION_CLUSTER_ID:
    return "AoXPositionEstimation";
  case DOTDOT_PROTOCOL_CONTROLLER_NETWORK_MANAGEMENT_CLUSTER_ID:
    return "ProtocolController-NetworkManagement";
  default:
    return "Unknown";
  }
}

dotdot_cluster_id_t uic_dotdot_get_cluster_id(const char* cluster_name) {
 if (strcmp ("Basic", cluster_name) == 0) {
   return DOTDOT_BASIC_CLUSTER_ID;
 }
 if (strcmp ("PowerConfiguration", cluster_name) == 0) {
   return DOTDOT_POWER_CONFIGURATION_CLUSTER_ID;
 }
 if (strcmp ("DeviceTemperatureConfiguration", cluster_name) == 0) {
   return DOTDOT_DEVICE_TEMPERATURE_CONFIGURATION_CLUSTER_ID;
 }
 if (strcmp ("Identify", cluster_name) == 0) {
   return DOTDOT_IDENTIFY_CLUSTER_ID;
 }
 if (strcmp ("Groups", cluster_name) == 0) {
   return DOTDOT_GROUPS_CLUSTER_ID;
 }
 if (strcmp ("Scenes", cluster_name) == 0) {
   return DOTDOT_SCENES_CLUSTER_ID;
 }
 if (strcmp ("OnOff", cluster_name) == 0) {
   return DOTDOT_ON_OFF_CLUSTER_ID;
 }
 if (strcmp ("Level", cluster_name) == 0) {
   return DOTDOT_LEVEL_CLUSTER_ID;
 }
 if (strcmp ("Alarms", cluster_name) == 0) {
   return DOTDOT_ALARMS_CLUSTER_ID;
 }
 if (strcmp ("Time", cluster_name) == 0) {
   return DOTDOT_TIME_CLUSTER_ID;
 }
 if (strcmp ("Commissioning", cluster_name) == 0) {
   return DOTDOT_COMMISSIONING_CLUSTER_ID;
 }
 if (strcmp ("OTAUpgrade", cluster_name) == 0) {
   return DOTDOT_OTA_UPGRADE_CLUSTER_ID;
 }
 if (strcmp ("PollControl", cluster_name) == 0) {
   return DOTDOT_POLL_CONTROL_CLUSTER_ID;
 }
 if (strcmp ("ShadeConfiguration", cluster_name) == 0) {
   return DOTDOT_SHADE_CONFIGURATION_CLUSTER_ID;
 }
 if (strcmp ("DoorLock", cluster_name) == 0) {
   return DOTDOT_DOOR_LOCK_CLUSTER_ID;
 }
 if (strcmp ("WindowCovering", cluster_name) == 0) {
   return DOTDOT_WINDOW_COVERING_CLUSTER_ID;
 }
 if (strcmp ("BarrierControl", cluster_name) == 0) {
   return DOTDOT_BARRIER_CONTROL_CLUSTER_ID;
 }
 if (strcmp ("PumpConfigurationAndControl", cluster_name) == 0) {
   return DOTDOT_PUMP_CONFIGURATION_AND_CONTROL_CLUSTER_ID;
 }
 if (strcmp ("Thermostat", cluster_name) == 0) {
   return DOTDOT_THERMOSTAT_CLUSTER_ID;
 }
 if (strcmp ("FanControl", cluster_name) == 0) {
   return DOTDOT_FAN_CONTROL_CLUSTER_ID;
 }
 if (strcmp ("DehumidificationControl", cluster_name) == 0) {
   return DOTDOT_DEHUMIDIFICATION_CONTROL_CLUSTER_ID;
 }
 if (strcmp ("ThermostatUserInterfaceConfiguration", cluster_name) == 0) {
   return DOTDOT_THERMOSTAT_USER_INTERFACE_CONFIGURATION_CLUSTER_ID;
 }
 if (strcmp ("ColorControl", cluster_name) == 0) {
   return DOTDOT_COLOR_CONTROL_CLUSTER_ID;
 }
 if (strcmp ("BallastConfiguration", cluster_name) == 0) {
   return DOTDOT_BALLAST_CONFIGURATION_CLUSTER_ID;
 }
 if (strcmp ("IlluminanceMeasurement", cluster_name) == 0) {
   return DOTDOT_ILLUMINANCE_MEASUREMENT_CLUSTER_ID;
 }
 if (strcmp ("IlluminanceLevelSensing", cluster_name) == 0) {
   return DOTDOT_ILLUMINANCE_LEVEL_SENSING_CLUSTER_ID;
 }
 if (strcmp ("TemperatureMeasurement", cluster_name) == 0) {
   return DOTDOT_TEMPERATURE_MEASUREMENT_CLUSTER_ID;
 }
 if (strcmp ("PressureMeasurement", cluster_name) == 0) {
   return DOTDOT_PRESSURE_MEASUREMENT_CLUSTER_ID;
 }
 if (strcmp ("FlowMeasurement", cluster_name) == 0) {
   return DOTDOT_FLOW_MEASUREMENT_CLUSTER_ID;
 }
 if (strcmp ("RelativityHumidity", cluster_name) == 0) {
   return DOTDOT_RELATIVITY_HUMIDITY_CLUSTER_ID;
 }
 if (strcmp ("OccupancySensing", cluster_name) == 0) {
   return DOTDOT_OCCUPANCY_SENSING_CLUSTER_ID;
 }
 if (strcmp ("PhMeasurement", cluster_name) == 0) {
   return DOTDOT_PH_MEASUREMENT_CLUSTER_ID;
 }
 if (strcmp ("ElectricalConductivityMeasurement", cluster_name) == 0) {
   return DOTDOT_ELECTRICAL_CONDUCTIVITY_MEASUREMENT_CLUSTER_ID;
 }
 if (strcmp ("WindSpeedMeasurement", cluster_name) == 0) {
   return DOTDOT_WIND_SPEED_MEASUREMENT_CLUSTER_ID;
 }
 if (strcmp ("CarbonMonoxide", cluster_name) == 0) {
   return DOTDOT_CARBON_MONOXIDE_CLUSTER_ID;
 }
 if (strcmp ("IASZone", cluster_name) == 0) {
   return DOTDOT_IAS_ZONE_CLUSTER_ID;
 }
 if (strcmp ("IASACE", cluster_name) == 0) {
   return DOTDOT_IASACE_CLUSTER_ID;
 }
 if (strcmp ("IASWD", cluster_name) == 0) {
   return DOTDOT_IASWD_CLUSTER_ID;
 }
 if (strcmp ("Metering", cluster_name) == 0) {
   return DOTDOT_METERING_CLUSTER_ID;
 }
 if (strcmp ("ElectricalMeasurement", cluster_name) == 0) {
   return DOTDOT_ELECTRICAL_MEASUREMENT_CLUSTER_ID;
 }
 if (strcmp ("Diagnostics", cluster_name) == 0) {
   return DOTDOT_DIAGNOSTICS_CLUSTER_ID;
 }
 if (strcmp ("TouchlinkCommissioning", cluster_name) == 0) {
   return DOTDOT_TOUCHLINK_COMMISSIONING_CLUSTER_ID;
 }
 if (strcmp ("ProtocolController-RFTelemetry", cluster_name) == 0) {
   return DOTDOT_PROTOCOL_CONTROLLER_RF_TELEMETRY_CLUSTER_ID;
 }
 if (strcmp ("State", cluster_name) == 0) {
   return DOTDOT_STATE_CLUSTER_ID;
 }
 if (strcmp ("Binding", cluster_name) == 0) {
   return DOTDOT_BINDING_CLUSTER_ID;
 }
 if (strcmp ("SystemMetrics", cluster_name) == 0) {
   return DOTDOT_SYSTEM_METRICS_CLUSTER_ID;
 }
 if (strcmp ("ApplicationMonitoring", cluster_name) == 0) {
   return DOTDOT_APPLICATION_MONITORING_CLUSTER_ID;
 }
 if (strcmp ("NameAndLocation", cluster_name) == 0) {
   return DOTDOT_NAME_AND_LOCATION_CLUSTER_ID;
 }
 if (strcmp ("ConfigurationParameters", cluster_name) == 0) {
   return DOTDOT_CONFIGURATION_PARAMETERS_CLUSTER_ID;
 }
 if (strcmp ("AoXLocator", cluster_name) == 0) {
   return DOTDOT_AOX_LOCATOR_CLUSTER_ID;
 }
 if (strcmp ("AoXPositionEstimation", cluster_name) == 0) {
   return DOTDOT_AOX_POSITION_ESTIMATION_CLUSTER_ID;
 }
 if (strcmp ("ProtocolController-NetworkManagement", cluster_name) == 0) {
   return DOTDOT_PROTOCOL_CONTROLLER_NETWORK_MANAGEMENT_CLUSTER_ID;
 }

  // Return an invalid ID if we did not get any match.
  return DOTDOT_INVALID_CLUSTER_ID;
}