/*********************************************************************************
 * Filename: gnb_du_oam_agent_rcfd_du_ns.cpp 
 *
 * Description: This file implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:29
 *
 * YANG file latest revision: 2019-07-08
*********************************************************************************/ 

#include "gnb_du_oam_agent_rcfd_du_ns.h" 

namespace gnb_du 
{
namespace rcfd
{

oam_agent_rcfd_du_ns::oam_agent_rcfd_du_ns(XCONFD_YANGTREE_T* yt)
{
    xconfd_get(agent_type_, enum, "agent-type", yt);
    auto local_sm_yt = xconfd_yang_tree_get_node(yt, "local-sm");
    read_local_sm(local_sm_yt);
    auto remote_sm_yt = xconfd_yang_tree_get_node(yt, "remote-sm");
    read_remote_sm(remote_sm_yt);
    auto nsis_yt = xconfd_yang_tree_get_node(yt, "nsis");
    read_nsis(nsis_yt);
}

void oam_agent_rcfd_du_ns::read_local_sm(XCONFD_YANGTREE_T* yt)
{
    read_grp_ip_addr_port(yt, local_sm_);
}

void oam_agent_rcfd_du_ns::read_remote_sm(XCONFD_YANGTREE_T* yt)
{
    read_grp_ip_addr_port(yt, remote_sm_);
}

void oam_agent_rcfd_du_ns::read_nsis(XCONFD_YANGTREE_T* yt)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, nsi_yt)
    {
        auto nsi = std::make_shared<Nsi>();
        read_grp_nsi(nsi_yt, *nsi);
        nsis_.push_back(nsi);
    }
}

void oam_agent_rcfd_du_ns::read_grp_nsi(XCONFD_YANGTREE_T* yt, Nsi& nsi)
{
    xconfd_get(nsi.nsi_id, uint8, "nsi-id", yt);
    xconfd_yang_tree_get_leaf_list(nsi.cores, uint16, "cores", yt);
}


} // namespace rcfd 
} // namespace gnb_du