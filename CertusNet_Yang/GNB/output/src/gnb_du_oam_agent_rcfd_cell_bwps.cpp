/*********************************************************************************
 * Filename: gnb_du_oam_agent_rcfd_cell_bwps.cpp 
 *
 * Description: This file implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:26
 *
 * YANG file latest revision: 2019-08-23
*********************************************************************************/ 

#include "gnb_du_oam_agent_rcfd_cell_bwps.h" 

namespace gnb_du 
{
namespace rcfd
{

oam_agent_rcfd_cell_bwps::oam_agent_rcfd_cell_bwps(XCONFD_YANGTREE_T* yt)
{
    auto ul_bwps_yt = xconfd_yang_tree_get_node(yt, "ul-bwps");
    read_ul_bwps(ul_bwps_yt);
    auto dl_bwps_yt = xconfd_yang_tree_get_node(yt, "dl-bwps");
    read_dl_bwps(dl_bwps_yt);
    auto sul_bwps_yt = xconfd_yang_tree_get_node(yt, "sul-bwps");
    read_sul_bwps(sul_bwps_yt);
}

void oam_agent_rcfd_cell_bwps::read_ul_bwps(XCONFD_YANGTREE_T* yt)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, ul_bwp_yt)
    {
        auto ul_bwp = std::make_shared<UlBwp>();
        read_grp_ul_bwp(ul_bwp_yt, *ul_bwp);
        ul_bwps_.push_back(ul_bwp);
    }
}

void oam_agent_rcfd_cell_bwps::read_dl_bwps(XCONFD_YANGTREE_T* yt)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, dl_bwp_yt)
    {
        auto dl_bwp = std::make_shared<DlBwp>();
        read_grp_dl_bwp(dl_bwp_yt, *dl_bwp);
        dl_bwps_.push_back(dl_bwp);
    }
}

void oam_agent_rcfd_cell_bwps::read_sul_bwps(XCONFD_YANGTREE_T* yt)
{
    XCONFD_YANG_TREE_LIST_FOREACH(yt, ul_bwp_yt)
    {
        auto ul_bwp = std::make_shared<UlBwp>();
        read_grp_ul_bwp(sul_bwp_yt, *ul_bwp);
        sul_bwps_.push_back(ul_bwp);
    }
}

void oam_agent_rcfd_cell_bwps::read_grp_rach_grpb(XCONFD_YANGTREE_T* yt, RachGrpb& rach_grpb)
{
    xconfd_get(rach_grpb.ra_msg3_size_grp_a, enum, "ra-msg3-size-grp-a", yt);
    xconfd_get(rach_grpb.num_ra_preamble_grp_a, uint8, "num-ra-preamble-grp-a", yt);
}

void oam_agent_rcfd_cell_bwps::read_grp_bwp_gen(XCONFD_YANGTREE_T* yt, BwpGen& bwp_gen)
{
    xconfd_get(bwp_gen.bwp_id, uint8, "bwp-id", yt);
    xconfd_get(bwp_gen.scs, enum, "scs", yt);
    xconfd_get_empty_value(bwp_gen.cp_extended, "cp-extended", yt);
    xconfd_get(bwp_gen.start_rb, uint16, "start-rb", yt);
    xconfd_get(bwp_gen.rb_num, uint16, "rb-num", yt);
}

void oam_agent_rcfd_cell_bwps::read_grp_rach_cfg(XCONFD_YANGTREE_T* yt, RachCfg& rach_cfg)
{
    auto rach_gen_yt = xconfd_yang_tree_get_node(yt, "rach-gen");
    read_grp_rach_cfg__rach_gen(rach_gen_yt, rach_cfg.rach_gen);
    xconfd_get(rach_cfg.preamble_format, enum, "preamble-format", yt);
    xconfd_get(rach_cfg.total_num_ra_preamble, uint8, "total-num-ra-preamble", yt);
    xconfd_get(rach_cfg.ssb_per_rach_occ, enum, "ssb-per-rach-occ", yt);
    xconfd_get(rach_cfg.cb_preamble_per_ssb, uint8, "cb-preamble-per-ssb", yt);
    auto rach_grpb_yt = xconfd_yang_tree_get_node(yt, "rach-grpb");
    read_grp_rach_cfg__rach_grpb(rach_grpb_yt, rach_cfg.rach_grpb);
    xconfd_get(rach_cfg.ra_cont_res_tmr, enum, "ra-cont-res-tmr", yt);
    xconfd_get(rach_cfg.prach_root_seq_idx_type, enum, "prach-root-seq-idx-type", yt);
    xconfd_get(rach_cfg.prach_root_seq_idx, uint16, "prach-root-seq-idx", yt);
    xconfd_get(rach_cfg.msg1_scs, enum, "msg1-scs", yt);
    xconfd_get(rach_cfg.restr_set, enum, "restr-set", yt);
    xconfd_get_empty_value(rach_cfg.msg3_tran_precoding, "msg3-tran-precoding", yt);
    xconfd_get(rach_cfg.max_msg3_trans, uint8, "max-msg3-trans", yt);
    xconfd_get(rach_cfg.rsrp_thres_ssb, uint8, "rsrp-thres-ssb", yt);
}

void oam_agent_rcfd_cell_bwps::read_grp_rach_cfg__rach_gen(XCONFD_YANGTREE_T* yt, RachGen& rach_gen)
{
    read_grp_rach_gen(yt, rach_gen);
}

void oam_agent_rcfd_cell_bwps::read_grp_rach_cfg__rach_grpb(XCONFD_YANGTREE_T* yt, std::shared_ptr<RachGrpb>& rach_grpb)
{
    if (!yt) return;
    rach_grpb = std::make_shared<RachGrpb>();

    read_grp_rach_grpb(yt, *rach_grpb);
}

void oam_agent_rcfd_cell_bwps::read_grp_rach_gen(XCONFD_YANGTREE_T* yt, RachGen& rach_gen)
{
    xconfd_get(rach_gen.prach_cfg_idx, uint8, "prach-cfg-idx", yt);
    xconfd_get(rach_gen.msg1_fdm, enum, "msg1-fdm", yt);
    xconfd_get(rach_gen.msg1_freq_start, uint16, "msg1-freq-start", yt);
    xconfd_get(rach_gen.zero_corre_zone, uint8, "zero-corre-zone", yt);
    xconfd_get(rach_gen.preamble_rx_tpower, int16, "preamble-rx-tpower", yt);
    xconfd_get(rach_gen.preamble_trans_max, enum, "preamble-trans-max", yt);
    xconfd_get(rach_gen.power_ramp_step, enum, "power-ramp-step", yt);
    xconfd_get(rach_gen.ra_rsp_win, enum, "ra-rsp-win", yt);
}

void oam_agent_rcfd_cell_bwps::read_grp_ul_bwp(XCONFD_YANGTREE_T* yt, UlBwp& ul_bwp)
{
    xconfd_get(ul_bwp.sr_perd, uint16, "sr-perd", yt);
    xconfd_get(ul_bwp.f2_max_payload_len1, uint16, "f2-max-payload-len1", yt);
    xconfd_get(ul_bwp.f2_max_payload_len2, uint16, "f2-max-payload-len2", yt);
    xconfd_get(ul_bwp.cyc_shift_bitmap, uint16, "cyc-shift-bitmap", yt);
    auto rach_cfg_yt = xconfd_yang_tree_get_node(yt, "rach-cfg");
    read_grp_ul_bwp__rach_cfg(rach_cfg_yt, ul_bwp.rach_cfg);
    read_grp_bwp_gen(yt, ul_bwp.bwp_gen);
}

void oam_agent_rcfd_cell_bwps::read_grp_ul_bwp__rach_cfg(XCONFD_YANGTREE_T* yt, std::shared_ptr<RachCfg>& rach_cfg)
{
    if (!yt) return;
    rach_cfg = std::make_shared<RachCfg>();

    read_grp_rach_cfg(yt, *rach_cfg);
}

void oam_agent_rcfd_cell_bwps::read_grp_dl_bwp(XCONFD_YANGTREE_T* yt, DlBwp& dl_bwp)
{
    auto cs_ss_cfg_yt = xconfd_yang_tree_get_node(yt, "cs-ss-cfg");
    read_grp_dl_bwp__cs_ss_cfg(cs_ss_cfg_yt, dl_bwp.cs_ss_cfg);
    read_grp_bwp_gen(yt, dl_bwp.bwp_gen);
}

void oam_agent_rcfd_cell_bwps::read_grp_dl_bwp__cs_ss_cfg(XCONFD_YANGTREE_T* yt, CsSsCfg& cs_ss_cfg)
{
    xconfd_get(cs_ss_cfg.avg_aggr_lvl, uint8, "avg-aggr-lvl", yt);
    xconfd_get(cs_ss_cfg.max_aggr_lvl, uint8, "max-aggr-lvl", yt);
    xconfd_get(cs_ss_cfg.mon_slot_perd, uint8, "mon-slot-perd", yt);
}


} // namespace rcfd 
} // namespace gnb_du