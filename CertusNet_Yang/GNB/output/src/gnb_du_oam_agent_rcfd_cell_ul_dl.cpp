/*********************************************************************************
 * Filename: gnb_du_oam_agent_rcfd_cell_ul_dl.cpp 
 *
 * Description: This file implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:28
 *
 * YANG file latest revision: 2019-08-23
*********************************************************************************/ 

#include "gnb_du_oam_agent_rcfd_cell_ul_dl.h" 

namespace gnb_du 
{
namespace rcfd
{

oam_agent_rcfd_cell_ul_dl::oam_agent_rcfd_cell_ul_dl(XCONFD_YANGTREE_T* yt)
{
    auto ul_freq_yt = xconfd_yang_tree_get_node(yt, "ul-freq");
    read_ul_freq(ul_freq_yt);
    auto dl_freq_yt = xconfd_yang_tree_get_node(yt, "dl-freq");
    read_dl_freq(dl_freq_yt);
    auto sul_yt = xconfd_yang_tree_get_node(yt, "sul");
    read_sul(sul_yt);
}

void oam_agent_rcfd_cell_ul_dl::read_ul_freq(XCONFD_YANGTREE_T* yt)
{
    if (!yt) return;
    ul_freq_ = std::make_shared<UlFreq>();

    read_grp_ul_freq(yt, *ul_freq_);
}

void oam_agent_rcfd_cell_ul_dl::read_dl_freq(XCONFD_YANGTREE_T* yt)
{
    read_grp_dl_freq(yt, dl_freq_);
}

void oam_agent_rcfd_cell_ul_dl::read_sul(XCONFD_YANGTREE_T* yt)
{
    if (!yt) return;
    sul_ = std::make_shared<Sul>();

    read_grp_sul(yt, *sul_);
}

void oam_agent_rcfd_cell_ul_dl::read_grp_freq_info_cmn(XCONFD_YANGTREE_T* yt, FreqInfoCmn& freq_info_cmn)
{
    xconfd_get(freq_info_cmn.abs_freq_point_a, uint32, "abs-freq-point-a", yt);
    xconfd_get(freq_info_cmn.abs_arfcn_point_a, uint32, "abs-arfcn-point-a", yt);
    xconfd_get(freq_info_cmn.nr_arfcn, uint32, "nr-arfcn", yt);
    xconfd_get(freq_info_cmn.channel_bw, enum, "channel-bw", yt);
    xconfd_yang_tree_get_leaf_list(freq_info_cmn.nr_freq_bands, uint16, "nr-freq-bands", yt);
    auto scs_spec_carriers_yt = xconfd_yang_tree_get_node(yt, "scs-spec-carriers");
    read_grp_freq_info_cmn__scs_spec_carriers(scs_spec_carriers_yt, freq_info_cmn.scs_spec_carriers);
}

void oam_agent_rcfd_cell_ul_dl::read_grp_freq_info_cmn__scs_spec_carriers(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<ScsSpecCarrier>>& scs_spec_carriers)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, scs_spec_carrier_yt)
    {
        auto scs_spec_carrier = std::make_shared<ScsSpecCarrier>();
        read_grp_scs_spec_carrier(scs_spec_carrier_yt, *scs_spec_carrier);
        scs_spec_carriers.push_back(scs_spec_carrier);
    }
}

void oam_agent_rcfd_cell_ul_dl::read_grp_sul(XCONFD_YANGTREE_T* yt, Sul& sul)
{
    xconfd_get(sul.max_ue_per_tti, uint32, "max-ue-per-tti", yt);
    xconfd_get(sul.ccch_cqi, uint8, "ccch-cqi", yt);
    xconfd_get_optional(sul.tar_cqi, uint8_t, uint8, "tar-cqi", yt);
    xconfd_get_empty_value(sul.harmonic, "harmonic", yt);
    xconfd_get_empty_value(sul.freq_muted, "freq-muted", yt);
    auto freq_info_yt = xconfd_yang_tree_get_node(yt, "freq-info");
    read_grp_sul__freq_info(freq_info_yt, sul.freq_info);
}

void oam_agent_rcfd_cell_ul_dl::read_grp_sul__freq_info(XCONFD_YANGTREE_T* yt, std::shared_ptr<UlFreq>& freq_info)
{
    if (!yt) return;
    freq_info = std::make_shared<UlFreq>();

    read_grp_ul_freq(yt, *freq_info);
}

void oam_agent_rcfd_cell_ul_dl::read_grp_dl_freq(XCONFD_YANGTREE_T* yt, DlFreq& dl_freq)
{
    auto freq_info_cmn_yt = xconfd_yang_tree_get_node(yt, "freq-info-cmn");
    read_grp_dl_freq__freq_info_cmn(freq_info_cmn_yt, dl_freq.freq_info_cmn);
    xconfd_get(dl_freq.abs_freq_ssb, uint32, "abs-freq-ssb", yt);
    xconfd_get(dl_freq.abs_arfcn_ssb, uint32, "abs-arfcn-ssb", yt);
}

void oam_agent_rcfd_cell_ul_dl::read_grp_dl_freq__freq_info_cmn(XCONFD_YANGTREE_T* yt, FreqInfoCmn& freq_info_cmn)
{
    read_grp_freq_info_cmn(yt, freq_info_cmn);
}

void oam_agent_rcfd_cell_ul_dl::read_grp_scs_spec_carrier(XCONFD_YANGTREE_T* yt, ScsSpecCarrier& scs_spec_carrier)
{
    xconfd_get(scs_spec_carrier.scs, enum, "scs", yt);
    xconfd_get(scs_spec_carrier.offset_to_carrier, uint16, "offset-to-carrier", yt);
}

void oam_agent_rcfd_cell_ul_dl::read_grp_ul_freq(XCONFD_YANGTREE_T* yt, UlFreq& ul_freq)
{
    auto freq_info_cmn_yt = xconfd_yang_tree_get_node(yt, "freq-info-cmn");
    read_grp_ul_freq__freq_info_cmn(freq_info_cmn_yt, ul_freq.freq_info_cmn);
    xconfd_get(ul_freq.addtl_spectrum_emi, uint8, "addtl-spectrum-emi", yt);
    xconfd_get(ul_freq.p_max, int8, "p-max", yt);
    xconfd_get_empty_value(ul_freq.freq_shift_7p5khz, "freq-shift-7p5khz", yt);
}

void oam_agent_rcfd_cell_ul_dl::read_grp_ul_freq__freq_info_cmn(XCONFD_YANGTREE_T* yt, FreqInfoCmn& freq_info_cmn)
{
    read_grp_freq_info_cmn(yt, freq_info_cmn);
}


} // namespace rcfd 
} // namespace gnb_du