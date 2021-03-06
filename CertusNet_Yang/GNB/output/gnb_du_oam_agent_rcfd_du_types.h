/*
 * filename: gnb_du_oam_agent_rcfd_du_types.h 
 * This header file contains implementation of OAM Agent RConfD Generate by Tools 
*/ 

#ifndef __GNB_DU_OAM_AGENT_RCFD_DU_TYPES_H__
#define __GNB_DU_OAM_AGENT_RCFD_DU_TYPES_H__

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "xconfd_api.h"
#include "gnb_du_common.h"
#include "gnb_du_oam_comm.h"

namespace gnb_du 
{
namespace rcfd
{
typedef enum enumDuModuleIdE
{
    DU_NS_AGENT,
    OAM_AGENT,
    DU_MGR,
    DU_RRM,
    APP_UE,
    F1AP,
    SCTP,
    EGTPU,
    UDP,
    NRUP,
    RRC_CODEC,
    COMMON_CODEC,
    COMMON,
    FAST_PKT
}DuModuleIdE;

typedef enum enumLogLvlE
{
    LL_OFF,
    LL_FATAL,
    LL_ERROR,
    LL_WARN,
    LL_INFO,
    LL_TRACE
}LogLvlE;

typedef enum enumNsAgentTypeE
{
    NS_DISABLED,
    NS_OAM_BASED,
    NS_SLICEMGR_BASED
}NsAgentTypeE;

typedef enum enumIpVersionE
{
    IPV4,
    IPV6
}IpVersionE;

typedef enum enumNgpModuleIdE
{
    NGP,
    MEM,
    BUF,
    STATS,
    TIMER,
    STHREAD,
    CTHREAD,
    SYS,
    EXCP,
    COMM,
    SCTP,
    UDP,
    TCP,
    MSGQ,
    PRIOQ,
    WORKQ,
    PERF,
    HTTP2,
    THR_POOL
}NgpModuleIdE;

typedef struct structIpAddr
{
    IpVersionE ip_version; 
    std::shared_ptr<Ipv4Address> ipv4_addr;
    std::shared_ptr<Ipv6Address> ipv6_addr;
}IpAddr;
void read_grp_ip_addr(XCONFD_YANGTREE_T* yt, IpAddr& ip_addr)
{

    xconfd_get(ip_addr.ip_version, ip-version-e, "ip-version", yt);
    xconfd_get_optional(ip_addr.ipv4_addr, Ipv4Address, ipv4, "ipv4-addr", yt);
    xconfd_get_optional(ip_addr.ipv6_addr, Ipv6Address, ipv6-address, "ipv6-addr", yt);
}
} //end of namespace rcfd
} //end of namespace gnb_du
#endif