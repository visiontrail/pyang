/********************************************************************************* 
 * Filename: gnb_du_oam_agent_rcfd_du_types.h 
 * Description: This header file contains implementation of OAM Agent RConfD.
 * Generation time: 2019-07-20 14:39:40
*********************************************************************************/ 

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
    DU_OAM_AGENT,
    DU_MGR,
    DU_RRM,
    DU_APP_UE,
    DU_F1AP,
    DU_SCTP,
    DU_EGTPU,
    DU_UDP,
    DU_NRUP,
    DU_RRC_CODEC,
    DU_COMMON_CODEC,
    DU_COMMON,
    DU_FAST_PKT
} DuModuleIdE;

typedef enum enumLogLvlE
{
    LL_OFF,
    LL_FATAL,
    LL_ERROR,
    LL_WARN,
    LL_INFO,
    LL_TRACE
} LogLvlE;

typedef enum enumNsAgentTypeE
{
    NS_DISABLED,
    NS_OAM_BASED,
    NS_SLICEMGR_BASED
} NsAgentTypeE;

typedef enum enumIpVersionE
{
    IPV4,
    IPV6
} IpVersionE;

typedef enum enumNgpModuleIdE
{
    NGP,
    NGP_MEM,
    NGP_BUF,
    NGP_STATS,
    NGP_TIMER,
    NGP_STHREAD,
    NGP_CTHREAD,
    NGP_SYS,
    NGP_EXCP,
    NGP_COMM,
    NGP_SCTP,
    NGP_UDP,
    NGP_TCP,
    NGP_MSGQ,
    NGP_PRIOQ,
    NGP_WORKQ,
    NGP_PERF,
    NGP_HTTP2,
    NGP_THR_POOL
} NgpModuleIdE;

typedef struct structIpAddr
{
    IpVersionE ip_version; 
    std::shared_ptr<std::string> ipv4_addr;
    std::shared_ptr<std::string> ipv6_addr;
} IpAddr;
void read_grp_ip_addr(XCONFD_YANGTREE_T* yt, IpAddr& ip_addr)
{
    xconfd_get(ip_addr.ip_version, enum, "ip-version", yt);
    xconfd_get_optional(ip_addr.ipv4_addr, std::string, ipv4, "ipv4-addr", yt);
    xconfd_get_optional(ip_addr.ipv6_addr, std::string, ipv6, "ipv6-addr", yt);
}
typedef struct structIpAddrPort
{
    IpVersionE ip_version; 
    std::shared_ptr<std::string> ipv4_addr;
    std::shared_ptr<std::string> ipv6_addr;
    uint32_t port; 
} IpAddrPort;
void read_grp_ip_addr_port(XCONFD_YANGTREE_T* yt, IpAddrPort& ip_addr_port)
{
    xconfd_get(ip_addr_port.ip_version, enum, "ip-version", yt);
    xconfd_get_optional(ip_addr_port.ipv4_addr, std::string, ipv4, "ipv4-addr", yt);
    xconfd_get_optional(ip_addr_port.ipv6_addr, std::string, ipv6, "ipv6-addr", yt);
    xconfd_get(ip_addr_port.port, uint32, "port", yt);
}
} //end of namespace rcfd
} //end of namespace gnb_du
#endif