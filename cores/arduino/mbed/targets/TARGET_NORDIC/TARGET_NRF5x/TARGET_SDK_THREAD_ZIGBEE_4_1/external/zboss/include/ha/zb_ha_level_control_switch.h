/* ZBOSS Zigbee software protocol stack
 *
 * Copyright (c) 2012-2020 DSR Corporation, Denver CO, USA.
 * www.dsr-zboss.com
 * www.dsr-corporation.com
 * All rights reserved.
 *
 * This is unpublished proprietary source code of DSR Corporation
 * The copyright notice does not evidence any actual or intended
 * publication of such source code.
 *
 * ZBOSS is a registered trademark of Data Storage Research LLC d/b/a DSR
 * Corporation
 *
 * Commercial Usage
 * Licensees holding valid DSR Commercial licenses may use
 * this file in accordance with the DSR Commercial License
 * Agreement provided with the Software or, alternatively, in accordance
 * with the terms contained in a written agreement between you and
 * DSR.
 */
/* PURPOSE: Level control switch device definition
*/

#ifndef ZB_HA_LEVEL_CONTROL_SWITCH_H
#define ZB_HA_LEVEL_CONTROL_SWITCH_H 1

#if defined ZB_HA_DEFINE_DEVICE_LEVEL_CONTROL_SWITCH || defined DOXYGEN

/** @cond DOXYGEN_HA_SECTION */

/**
 *  @defgroup ha_level_control_switch Level Control Switch
 *  @ingroup ZB_HA_DEVICES
    @{
    Level Control Switch device has 4 clusters (see spec 7.4.8): \n
        - @ref ZB_ZCL_IDENTIFY \n
        - @ref ZB_ZCL_BASIC \n
        - @ref ZB_ZCL_ON_OFF \n
        - @ref ZB_ZCL_LEVEL_CONTROL

    Sample use Level Control Switch device

    @par Example

    - Declaring clusters:

        @snippet HA_samples/common/zcl_basic_attr_list.h BASIC_CLUSTER_COMMON
        @snippet HA_samples/level_control_switch/sample_zc.c COMMON_DECLARATION

    - Registering device list:

        @snippet HA_samples/level_control_switch/sample_zc.c REGISTER

    - Example of command handler:

        @snippet HA_samples/level_control_switch/sample_zc.c COMMAND_HANDLER
        @snippet HA_samples/level_control_switch/sample_zc.c ZCL_COMMAND_HANDLER

    @par

    @cond ZBOSS_SAMPLES_API_DOC_LINE
    See application/HA_samples/level_control_switch sample
    @endcond
 */

#define ZB_HA_DEVICE_VER_LEVEL_CONTROL_SWITCH 0  /*!< Level Control Switch device version */

#define ZB_HA_LEVEL_CONTROL_SWITCH_IN_CLUSTER_NUM 2  /*!< @internal Level Control Switch IN
                                                       (server) clusters number */
#define ZB_HA_LEVEL_CONTROL_SWITCH_OUT_CLUSTER_NUM 3 /*!< @internal Level Control Switch OUT
                                                       (client) clusters number */

#define ZB_HA_LEVEL_CONTROL_SWITCH_CLUSTER_NUM                                             \
  (ZB_HA_LEVEL_CONTROL_SWITCH_IN_CLUSTER_NUM + ZB_HA_LEVEL_CONTROL_SWITCH_OUT_CLUSTER_NUM)

/*! Number of attribute for reporting on Level Control Switch device */
#define ZB_HA_LEVEL_CONTROL_SWITCH_REPORT_ATTR_COUNT         0

/** @brief Declare cluster list for Level Control Switch device
    @param cluster_list_name - cluster list variable name
    @param basic_attr_list - attribute list for Basic cluster
    @param identify_attr_list - attribute list for Identify cluster
 */
#define ZB_HA_DECLARE_LEVEL_CONTROL_SWITCH_CLUSTER_LIST(  \
    cluster_list_name,                                    \
    basic_attr_list,                                      \
    identify_attr_list)                                   \
zb_zcl_cluster_desc_t cluster_list_name[] =               \
{                                                         \
  ZB_ZCL_CLUSTER_DESC(                                    \
    ZB_ZCL_CLUSTER_ID_IDENTIFY,                           \
    ZB_ZCL_ARRAY_SIZE(identify_attr_list, zb_zcl_attr_t), \
    (identify_attr_list),                                 \
    ZB_ZCL_CLUSTER_SERVER_ROLE,                           \
    ZB_ZCL_MANUF_CODE_INVALID                             \
  ),                                                      \
  ZB_ZCL_CLUSTER_DESC(                                    \
    ZB_ZCL_CLUSTER_ID_BASIC,                              \
    ZB_ZCL_ARRAY_SIZE(basic_attr_list, zb_zcl_attr_t),    \
    (basic_attr_list),                                    \
    ZB_ZCL_CLUSTER_SERVER_ROLE,                           \
    ZB_ZCL_MANUF_CODE_INVALID                             \
  ),                                                      \
  ZB_ZCL_CLUSTER_DESC(                                    \
    ZB_ZCL_CLUSTER_ID_ON_OFF,                             \
    0,                                                    \
    NULL,                                                 \
    ZB_ZCL_CLUSTER_CLIENT_ROLE,                           \
    ZB_ZCL_MANUF_CODE_INVALID                             \
  ),                                                      \
  ZB_ZCL_CLUSTER_DESC(                                    \
    ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL,                      \
    0,                                                    \
    NULL,                                                 \
    ZB_ZCL_CLUSTER_CLIENT_ROLE,                           \
    ZB_ZCL_MANUF_CODE_INVALID                             \
  ),                                                      \
  ZB_ZCL_CLUSTER_DESC(                                    \
    ZB_ZCL_CLUSTER_ID_IDENTIFY,                           \
    0,                                                    \
    NULL,                                                 \
    ZB_ZCL_CLUSTER_CLIENT_ROLE,                           \
    ZB_ZCL_MANUF_CODE_INVALID                             \
  )                                                       \
}

/** @brief Declare simple descriptor for Level control switch device
    @param ep_name - endpoint variable name
    @param ep_id - endpoint ID
    @param in_clust_num - number of supported input clusters
    @param out_clust_num - number of supported output clusters
*/
#define ZB_ZCL_DECLARE_LEVEL_CONTROL_SWITCH_SIMPLE_DESC(                      \
  ep_name, ep_id, in_clust_num, out_clust_num)                                \
  ZB_DECLARE_SIMPLE_DESC(in_clust_num, out_clust_num);                        \
  ZB_AF_SIMPLE_DESC_TYPE(in_clust_num, out_clust_num) simple_desc_##ep_name = \
  {                                                                           \
    ep_id,                                                                    \
    ZB_AF_HA_PROFILE_ID,                                                      \
    ZB_HA_LEVEL_CONTROL_SWITCH_DEVICE_ID,                                     \
    ZB_HA_DEVICE_VER_LEVEL_CONTROL_SWITCH,                                    \
    0,                                                                        \
    in_clust_num,                                                             \
    out_clust_num,                                                            \
    {                                                                         \
      ZB_ZCL_CLUSTER_ID_BASIC,                                                \
      ZB_ZCL_CLUSTER_ID_IDENTIFY,                                             \
      ZB_ZCL_CLUSTER_ID_ON_OFF,                                               \
      ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL,                                        \
      ZB_ZCL_CLUSTER_ID_IDENTIFY,                                             \
    }                                                                         \
  }

/** @brief Declare endpoint for Level Control Switch device
    @param ep_name - endpoint variable name
    @param ep_id - endpoint ID
    @param cluster_list - endpoint cluster list
 */
#define ZB_HA_DECLARE_LEVEL_CONTROL_SWITCH_EP(ep_name, ep_id, cluster_list)                     \
  ZB_ZCL_DECLARE_LEVEL_CONTROL_SWITCH_SIMPLE_DESC(ep_name, ep_id,                               \
      ZB_HA_LEVEL_CONTROL_SWITCH_IN_CLUSTER_NUM, ZB_HA_LEVEL_CONTROL_SWITCH_OUT_CLUSTER_NUM);   \
  ZB_AF_DECLARE_ENDPOINT_DESC(ep_name, ep_id, ZB_AF_HA_PROFILE_ID, 0, NULL,                              \
                          ZB_ZCL_ARRAY_SIZE(cluster_list, zb_zcl_cluster_desc_t), cluster_list, \
                          (zb_af_simple_desc_1_1_t*)&simple_desc_##ep_name,                     \
                          0, NULL, /* No reporting ctx */                                       \
                          0, NULL) /* No CVC ctx */


/*!
  @brief Declare application's device context for Level Control Switch device
  @param device_ctx - device context variable
  @param ep_name - endpoint variable name
*/

#define ZB_HA_DECLARE_LEVEL_CONTROL_SWITCH_CTX(device_ctx, ep_name)     \
  ZBOSS_DECLARE_DEVICE_CTX_1_EP(device_ctx, ep_name)

/*! @} */

/** @endcond */ /* DOXYGEN_HA_SECTION */

#endif /* ZB_HA_DEFINE_DEVICE_LEVEL_CONTROL_SWITCH */

#endif /* ZB_HA_LEVEL_CONTROL_SWITCH_H */
