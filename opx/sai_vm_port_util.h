/************************************************************************
 * LEGALESE:   "Copyright (c) 2015, Dell Inc. All rights reserved."
 *
 * This source code is confidential, proprietary, and contains trade
 * secrets that are the sole property of Dell Inc.
 * Copy and/or distribution of this source code or disassembly or reverse
 * engineering of the resultant object code are strictly forbidden without
 * the written consent of Dell Inc.
 *
 ************************************************************************/
/*
 * @file sai_vm_port_util.h
 *
 * @brief This file contains the data structures and function prototypes for
 *        SAI Port functions in VM environment.
 *************************************************************************/

#ifndef __SAI_VM_PORT_UTIL_H__
#define __SAI_VM_PORT_UTIL_H__

#include "sai_port_common.h"
#include "std_config_node.h"
#include "std_type_defs.h"

#include "saitypes.h"

/**
 * @brief SAI vm port initialization information.
 */
typedef struct _sai_vm_port_init_info_t {

    /** Port creation active or disabled */
    bool                         port_active;

    /** Port default state valid or invalid  */
    bool                         port_valid;

    /** Logical/Local port id to index NPU API's */
    sai_npu_port_id_t            local_port_id;

    /** Physical Port Number */
    sai_npu_port_id_t            phy_port_id;

    /** Group number it is part of in a multi-lane port */
    uint_t                       port_group;

    /** PHY used Internal or External */
    sai_port_phy_t               phy_type;

    /** External PHY address */
    sai_npu_port_id_t            ext_phy_addr;

    /* Breakout modes supported- [sai_port_breakout_mode_type_t] */
    uint_t                       breakout_modes_support;

    /** Port speed in Gbps */
    sai_port_speed_t             port_speed;

    /** Maximum  Lanes support per port */
    uint_t                       max_lanes_per_port;

    /** Bitmap of the active lanes in the port */
    uint64_t                     port_lane_bmap;

} sai_vm_port_init_info_t;

/**
 * VM vendor specific switch init config handler
 */
sai_status_t sai_npu_switch_init_config (sai_switch_id_t switch_id,
                                         std_config_node_t vm_node);

#endif /* __SAI_VM_PORT_UTIL_H__ */
