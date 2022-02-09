/*******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/**
 * @file command_mapper_int.h
 * @defgroup command_mapper_int ZigPC Command Mapper Internal API
 * @ingroup command_mapper
 * @brief The ZigPC Command Mapper internal API contains interfaces to
 * translate MQTT messages into ZCL frames.
 *
 * @{
 */

#ifndef ZIGPC_COMMAND_MAPPER_INT_H
#define ZIGPC_COMMAND_MAPPER_INT_H

#ifdef __cplusplus
extern "C" {
#endif

// Unify Shared components
#include <sl_status.h>
#include <uic_typedefs.h>

#include "zcl_util.h"
#include "zigpc_common_zigbee.h"

/**
 * @brief Setup DotDot MQTT Command Translator handlers autogenerated in
 * Command Mapper.
 *
 * @return sl_status_t Always returns SL_STATUS_OK.
 */
sl_status_t zigpc_command_mapper_register_dotdot_mqtt_handlers(void);

/**
 * @brief Setup MQTT handlers for processing group-based commands.
 *
 * @return sl_status_t Always returns SL_STATUS_OK.
 */
sl_status_t zigpc_command_mapper_mqtt_bygroup_handlers_init(void);

/**
 * @brief Convert the UNID into EUI64.
 *
 * @param unid          Unify UNID character array
 * @param eui64         Destination Zigbee EUI64 to populate
 * @return sl_status_t  SL_STATUS_OK on success, or  error on failure to
 * convert UNID to EUI64.
 */
sl_status_t zigpc_command_mapper_populate_eui64(const char *unid,
                                                zigbee_eui64_t eui64);
/**
 * @brief Determine if a cluster is serviced by the
 * UNID/Endpoint combination.
 *
 * @param unid        UNID to check
 * @param endpoint_id Endpoint ID to check
 * @param cluster_id  Cluster ID to check
 * @return sl_status_t  SL_STATUS_OK on success, SL_STATUS_NULL_POINTER on
 * invalid unid, SL_STATUS_NOT_FOUND if the UNID/endpoint/cluster combination
 * is not found.
 *
 */
sl_status_t
  zigpc_command_mapper_cluster_support_check(const dotdot_unid_t unid,
                                             zigbee_endpoint_id_t endpoint_id,
                                             zcl_cluster_id_t cluster_id);

/**
 * @brief Send a ZCL unicast command based on the information provided.
 *
 * @param unid              UNID that will be converted into EUI64.
 * @param endpoint          endpoint that will be targeted.
 * @param frame_type        ZCL frame control data to send.
 * @param cluster_id        cluster ID that will be targeted.
 * @param command_id        cluster command ID to be sent.
 * @param command_arg_count Number of ZCL command arguments.
 * @param command_arg_list  list of ZCL command arguments (or NULL if no
 * arguments are supported by the command).
 * @return sl_status_t      SL_STATUS_OK if successfully sent,
 * SL_STATUS_NULL_POINTER on invliad input received, or error otherwise.
 */
sl_status_t zigpc_command_mapper_send_unicast(
  const dotdot_unid_t unid,
  const dotdot_endpoint_id_t endpoint,
  const zigpc_zcl_frame_type_t frame_type,
  const zcl_cluster_id_t cluster_id,
  const zcl_command_id_t command_id,
  const size_t command_arg_count,
  const zigpc_zcl_frame_data_t *const command_arg_list);

/**
 * @brief Process unicast Groups cluster messages.
 *
 * @param eui64             Destination device identifer.
 * @param endpoint          Destination device endpoint.
 * @param cluster_id        Command cluster ID.
 * @param command_id        Command ID.
 * @param command_arg_count Command argument count.
 * @param command_arg_list  Command argument list.
 * @return sl_status_t
 */
sl_status_t zigpc_command_mapper_handle_groups(
  zigbee_eui64_t eui64,
  const dotdot_endpoint_id_t endpoint,
  const zcl_cluster_id_t cluster_id,
  const zcl_command_id_t command_id,
  const size_t command_arg_count,
  const zigpc_zcl_frame_data_t *const command_arg_list);

/**
 * @brief Redirect cluster messages to unicast based on the group members
 * (EUI64/endpoint identifiers) associated with a GroupID. For each group
 * member, this function will call zigpc_command_mapper_send_unicast with
 * the EUI64-based UNID and endpoint information.
 *
 * @param group_id    GroupId to lookup members.
 * @param frame_type  ZCL frame control data to send.
 * @param cluster_id  Cluster ID to send.
 * @param command_id  Command ID to send.
 * @param command_arg_count Command argument count.
 * @param command_arg_list  Command argument list.
 * @return sl_status_t
 */
sl_status_t zigpc_cmdmapper_redirect_to_unicast(
  zigbee_group_id_t group_id,
  zigpc_zcl_frame_type_t frame_type,
  zcl_cluster_id_t cluster_id,
  zcl_command_id_t command_id,
  size_t command_arg_count,
  const zigpc_zcl_frame_data_t *const command_arg_list);

/**
 * @brief Send a ZCL multicast command based on the information provided.
 *
 * @param multicast_id      Multicast ID targeted.
 * @param frame_type        ZCL frame control data to send.
 * @param cluster_id        cluster ID that will be targeted.
 * @param command_id        cluster command ID to be sent.
 * @param command_arg_count Number of ZCL command arguments.
 * @param command_arg_list  list of ZCL command arguments (or NULL if no
 * arguments are supported by the command).
 * @return sl_status_t      SL_STATUS_OK if successfully sent,
 * SL_STATUS_INVALID_RANGE on invalid group id received, or error otherwise.
 */
sl_status_t zigpc_command_mapper_send_multicast(
  const zigbee_group_id_t multicast_id,
  const zigpc_zcl_frame_type_t frame_type,
  const zcl_cluster_id_t cluster_id,
  const zcl_command_id_t command_id,
  const size_t command_arg_count,
  const zigpc_zcl_frame_data_t *const command_arg_list);

/**
 * @brief Setup listeners for ZCL cluster specific commands sent from PAN nodes
 * to the gateway.
 *
 * @return sl_status_t SL_STATUS_OK on successfully registing listeners for all
 * commands supported, error otherwise.
 */
sl_status_t zigpc_command_mapper_setup_gen_cmd_publish_listeners(void);

/**
 * @brief Cleanup listeners for ZCL cluster specific commands sent from PAN nodes
 * to the gateway.
 *
 */
void zigpc_command_mapper_cleanup_gen_cmd_publish_listeners(void);

#ifdef __cplusplus
}
#endif

#endif  //ZIGPC_COMMAND_MAPPER_INT_H

/** @} end command_mapper_int */
