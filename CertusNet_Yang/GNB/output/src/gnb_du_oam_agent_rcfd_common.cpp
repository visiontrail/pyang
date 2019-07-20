/*********************************************************************************
 * Filename: gnb_du_oam_agent_rcfd_common.cpp
 * Description: This file implementation of OAM Agent RConfD.
*********************************************************************************/ 

#include "gnb_du_oam_agent_rcfd_du_types.h"
#include "gnb_du_oam_agent_rcfd_cell_types.h"

namespace gnb_du 
{
namespace rcfd
{
void read_grp_plmn_id(XCONFD_YANGTREE_T* yt, PlmnId& plmn_id)
{
    xconfd_get(plmn_id.mcc, string, "mcc", yt);
    xconfd_get(plmn_id.mnc, string, "mnc", yt);
}
void read_grp_plmn_id(XCONFD_YANGTREE_T* yt, PlmnId& plmn_id)
{
    xconfd_get(plmn_id.mcc, string, "mcc", yt);
    xconfd_get(plmn_id.mnc, string, "mnc", yt);
}
void read_grp_ip_addr(XCONFD_YANGTREE_T* yt, IpAddr& ip_addr)
{
    xconfd_get(ip_addr.ip_version, enum, "ip-version", yt);
    xconfd_get_optional(ip_addr.ipv4_addr, std::string, ipv4, "ipv4-addr", yt);
    xconfd_get_optional(ip_addr.ipv6_addr, std::string, ipv6, "ipv6-addr", yt);
}
void read_grp_ip_addr_port(XCONFD_YANGTREE_T* yt, IpAddrPort& ip_addr_port)
{
    xconfd_get(ip_addr_port.ip_version, enum, "ip-version", yt);
    xconfd_get_optional(ip_addr_port.ipv4_addr, std::string, ipv4, "ipv4-addr", yt);
    xconfd_get_optional(ip_addr_port.ipv6_addr, std::string, ipv6, "ipv6-addr", yt);
    xconfd_get(ip_addr_port.port, uint32, "port", yt);
}

}
}