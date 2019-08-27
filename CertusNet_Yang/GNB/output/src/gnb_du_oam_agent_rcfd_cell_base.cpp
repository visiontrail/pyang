/*********************************************************************************
 * Filename: gnb_du_oam_agent_rcfd_cell_base.cpp 
 *
 * Description: This file implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:24
 *
 * YANG file latest revision: 2019-06-20
*********************************************************************************/ 

#include "gnb_du_oam_agent_rcfd_cell_base.h" 

namespace gnb_du 
{
namespace rcfd
{

oam_agent_rcfd_cell_base::oam_agent_rcfd_cell_base(XCONFD_YANGTREE_T* yt)
{
    xconfd_get(nr_pci_, uint16, "nr-pci", yt);
    auto nr_cgi_yt = xconfd_yang_tree_get_node(yt, "nr-cgi");
    read_nr_cgi(nr_cgi_yt);
    auto served_plmns_yt = xconfd_yang_tree_get_node(yt, "served-plmns");
    read_served_plmns(served_plmns_yt);
    xconfd_get(nr_mode_type_, enum, "nr-mode-type", yt);
    xconfd_get(scs_, enum, "scs", yt);
    xconfd_get(slot_format_, uint8, "slot-format", yt);
    xconfd_get(max_ue_per_ul_tti_, uint32, "max-ue-per-ul-tti", yt);
    xconfd_get(max_ue_per_dl_tti_, uint32, "max-ue-per-dl-tti", yt);
    xconfd_get(max_dl_harq_tx_, uint8, "max-dl-harq-tx", yt);
    xconfd_get(max_msg4_harq_tx_, uint32, "max-msg4-harq-tx", yt);
    xconfd_get(cfi_, uint32, "cfi", yt);
    auto preamble_id_range_yt = xconfd_yang_tree_get_node(yt, "preamble-id-range");
    read_preamble_id_range(preamble_id_range_yt);
    xconfd_get_empty_value(cp_ul_extended_ , "cp-ul-extended", yt);
    xconfd_get(dmrs_type_a_pos_, enum, "dmrs-type-a-pos", yt);
    xconfd_get(csi_perd_, uint16, "csi-perd", yt);
    xconfd_get(tac_5gs_, uint32, "tac-5gs", yt);
    xconfd_get_optional_enum(sib2_perd_, SiPerdE, "sib2-perd", yt);
    xconfd_get_optional_enum(sib3_perd_, SiPerdE, "sib3-perd", yt);
    xconfd_get(bcch_pcch_mcs_, uint8, "bcch-pcch-mcs", yt);
    xconfd_get(rar_mcs_, uint8, "rar-mcs", yt);
    xconfd_get(ul_ccch_cqi_, uint8, "ul-ccch-cqi", yt);
    xconfd_get(dl_ccch_cqi_, uint8, "dl-ccch-cqi", yt);
    auto pcch_yt = xconfd_yang_tree_get_node(yt, "pcch");
    read_pcch(pcch_yt);
}

void oam_agent_rcfd_cell_base::read_nr_cgi(XCONFD_YANGTREE_T* yt)
{
    read_grp_plmn_id(yt, nr_cgi_.plmn_id);
    xconfd_get(nr_cgi_.nr_cell_id, uint64, "nr-cell-id", yt);
}

void oam_agent_rcfd_cell_base::read_served_plmns(XCONFD_YANGTREE_T* yt)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, served_plmn_yt)
    {
        auto served_plmn = std::make_shared<ServedPlmn>();
        read_grp_served_plmn(served_plmn_yt, *served_plmn);
        served_plmns_.push_back(served_plmn);
    }
}

void oam_agent_rcfd_cell_base::read_preamble_id_range(XCONFD_YANGTREE_T* yt)
{
    xconfd_get(preamble_id_range_.start, uint16, "start", yt);
    xconfd_get(preamble_id_range_.size, uint16, "size", yt);
}

void oam_agent_rcfd_cell_base::read_pcch(XCONFD_YANGTREE_T* yt)
{
    read_grp_pcch(yt, pcch_);
}

void oam_agent_rcfd_cell_base::read_grp_s_nssai(XCONFD_YANGTREE_T* yt, SNssai& s_nssai)
{
    xconfd_get(s_nssai.sst, uint8, "sst", yt);
    xconfd_get(s_nssai.sd, uint32, "sd", yt);
}

void oam_agent_rcfd_cell_base::read_grp_pcch(XCONFD_YANGTREE_T* yt, Pcch& pcch)
{
    xconfd_get(pcch.default_paging_cycle, enum, "default-paging-cycle", yt);
    xconfd_get(pcch.paging_frame_offset_type, enum, "paging-frame-offset-type", yt);
    xconfd_get(pcch.paging_frame_offset, uint8, "paging-frame-offset", yt);
    xconfd_get(pcch.ns, enum, "ns", yt);
    xconfd_get_empty_value(pcch.f_pdcch_mon_occ_of_po_present, "f-pdcch-mon-occ-of-po-present", yt);
}

void oam_agent_rcfd_cell_base::read_grp_served_plmn(XCONFD_YANGTREE_T* yt, ServedPlmn& served_plmn)
{
    auto s_nssais_yt= xconfd_yang_tree_get_node(yt, "s-nssais");
    read_grp_served_plmn__s_nssais(s_nssais_yt, served_plmn.s_nssais);
    read_grp_plmn_id(yt, served_plmn.plmn_id);
}

void oam_agent_rcfd_cell_base::read_grp_served_plmn__s_nssais(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<SNssai>>& s_nssais)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, s_nssai_yt)
    {
        auto s_nssai = std::make_shared<SNssai>();
        read_grp_s_nssai(s_nssai_yt, *s_nssai);
        s_nssais.push_back(s_nssai);
    }
}


} // namespace rcfd 
} // namespace gnb_du