/*
 * filename: gnb_du_oam_agent_rcfd_du_ns.cpp 
 * This header file contains implementation of OAM Agent RConfD Generate by Tools 
*/ 

#include "gnb_du_oam_agent_rcfd_du_ns.h" 

namespace gnb_du 
{
namespace rcfd
{

oam_agent_rcfd_du_ns::oam_agent_rcfd_du_ns(XCONFD_YANGTREE_T* yt)
{
    xconfd_get(agent_type_, enum, "agent-type", yt);
    auto local_sm_yt = xconfd_yang_tree_get_node(yt, "local-sm");
    read_local_sm(local_sm_yt, local_sm_);
    auto remote_sm_yt = xconfd_yang_tree_get_node(yt, "remote-sm");
    read_remote_sm(remote_sm_yt, remote_sm_);
    auto nsis_yt = xconfd_yang_tree_get_node(yt, "nsis");
    read_nsis(nsis_yt, nsis_);
}

void oam_agent_rcfd_du_ns::read_local_sm(XCONFD_YANGTREE_T* yt, IpAddrPort& local_sm)
{
    read_grp_ip_addr_port(yt, local_sm);
}

void oam_agent_rcfd_du_ns::read_remote_sm(XCONFD_YANGTREE_T* yt, IpAddrPort& remote_sm)
{
    read_grp_ip_addr_port(yt, remote_sm);
}

void oam_agent_rcfd_du_ns::read_nsis(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<Nsi>>& nsis)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, nsi_yt)
    {
        auto nsi = std::make_shared<Nsi>();
        read_grp_nsi(nsi_yt, *nsi);
        nsis.push_back(nsi);
    }
}

void oam_agent_rcfd_du_ns::read_grp_nsi(XCONFD_YANGTREE_T* yt, Nsi& nsi)
{
    xconfd_get(nsi.nsi_id, uint8, "nsi-id", yt);
    xconfd_yang_tree_get_leaf_list(nsi.cores, uint16, "cores", yt);
    auto cells_yt = xconfd_yang_tree_get_node(yt, "cells");
    read_grp_nsi__cells(cells_yt, nsi.cells);
}

void oam_agent_rcfd_du_ns::read_grp_nsi__cells(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<NsCell>>& cells)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, ns_cell_yt)
    {
        auto ns_cell = std::make_shared<NsCell>();
        read_grp_ns_cell(ns_cell_yt, *ns_cell);
        cells.push_back(ns_cell);
    }
}

void oam_agent_rcfd_du_ns::read_grp_ns_cell(XCONFD_YANGTREE_T* yt, NsCell& ns_cell)
{
    xconfd_get(ns_cell.cell_id, uint8, "cell-id", yt);
    xconfd_get_empty_value(ns_cell.en_res_shared, "en-res-shared", yt);
    xconfd_get(ns_cell.res_id, uint8, "res-id", yt);
    xconfd_get(ns_cell.dl_num_ue_per_tti, uint8, "dl-num-ue-per-tti", yt);
    xconfd_get(ns_cell.ul_num_ue_per_tti, uint8, "ul-num-ue-per-tti", yt);
    xconfd_get(ns_cell.dl_prb, uint16, "dl-prb", yt);
    xconfd_get(ns_cell.ul_prb, uint16, "ul-prb", yt);
    xconfd_get(ns_cell.dl_sla_trgt_rate, uint64, "dl-sla-trgt-rate", yt);
    xconfd_get(ns_cell.ul_sla_trgt_rate, uint64, "ul-sla-trgt-rate", yt);
}

} // namespace rcfd 
} // namespace gnb_du