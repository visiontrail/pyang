/*********************************************************************************
 * Filename: gnb_du_oam_agent_cell_bwps.h 
 *
 * Description: This header file contains implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:26
 *
 * YANG file latest revision: 2019-08-23
*********************************************************************************/ 

#ifndef __GNB_DU_OAM_AGENT_CELL_BWPS__
#define __GNB_DU_OAM_AGENT_CELL_BWPS__

#include "gnb_du_oam_agent_rcfd_cell_types.h"

namespace gnb_du 
{
namespace rcfd
{

typedef struct structCsSsCfg
{
    uint8_t avg_aggr_lvl;
    uint8_t max_aggr_lvl;
    uint8_t mon_slot_perd;
} CsSsCfg;

typedef struct structBwpGen
{
    BwpIdT bwp_id; 
    ScsE scs; 
    bool cp_extended; 
    uint16_t start_rb; 
    uint16_t rb_num; 
} BwpGen;

typedef struct structRachGrpb
{
    RaMsg3SizeGrpAE ra_msg3_size_grp_a; 
    uint8_t num_ra_preamble_grp_a; 
} RachGrpb;

typedef struct structRachGen
{
    uint8_t prach_cfg_idx; 
    Msg1FdmE msg1_fdm; 
    uint16_t msg1_freq_start; 
    uint8_t zero_corre_zone; 
    int16_t preamble_rx_tpower; 
    PreambleTransMaxE preamble_trans_max; 
    PowerRampStepE power_ramp_step; 
    RaRspWinE ra_rsp_win; 
} RachGen;

typedef struct structRachCfg
{
    RachGen rach_gen; 
    RachPreambleFormatE preamble_format; 
    uint8_t total_num_ra_preamble; 
    SsbPerRachOccE ssb_per_rach_occ; 
    uint8_t cb_preamble_per_ssb; 
    std::shared_ptr<RachGrpb> rach_grpb; 
    RaContResTmrE ra_cont_res_tmr; 
    PrachRootSeqIdxTypeE prach_root_seq_idx_type; 
    uint16_t prach_root_seq_idx; 
    ScsE msg1_scs; 
    RestrSetE restr_set; 
    bool msg3_tran_precoding; 
    uint8_t max_msg3_trans; 
    uint8_t rsrp_thres_ssb; 
} RachCfg;

typedef struct structDlBwp
{
    BwpGen bwp_gen; 
    CsSsCfg cs_ss_cfg; 
} DlBwp;

typedef struct structUlBwp
{
    BwpGen bwp_gen; 
    uint16_t sr_perd; 
    uint16_t f2_max_payload_len1; 
    uint16_t f2_max_payload_len2; 
    uint16_t cyc_shift_bitmap; 
    std::shared_ptr<RachCfg> rach_cfg; 
} UlBwp;

class oam_agent_rcfd_cell_bwps : public allocator
{
public:
    std::vector<std::shared_ptr<UlBwp>> ul_bwps_;
    std::vector<std::shared_ptr<DlBwp>> dl_bwps_;
    std::vector<std::shared_ptr<UlBwp>> sul_bwps_;

private:
    void read_ul_bwps(XCONFD_YANGTREE_T* yt);
    void read_dl_bwps(XCONFD_YANGTREE_T* yt);
    void read_sul_bwps(XCONFD_YANGTREE_T* yt);
    void read_grp_rach_grpb(XCONFD_YANGTREE_T* yt, RachGrpb& rach_grpb);
    void read_grp_bwp_gen(XCONFD_YANGTREE_T* yt, BwpGen& bwp_gen);
    void read_grp_rach_cfg(XCONFD_YANGTREE_T* yt, RachCfg& rach_cfg);
    void read_grp_rach_cfg__rach_gen(XCONFD_YANGTREE_T* yt, RachGen& rach_gen);
    void read_grp_rach_cfg__rach_grpb(XCONFD_YANGTREE_T* yt, std::shared_ptr<RachGrpb>& rach_grpb);
    void read_grp_rach_gen(XCONFD_YANGTREE_T* yt, RachGen& rach_gen);
    void read_grp_ul_bwp(XCONFD_YANGTREE_T* yt, UlBwp& ul_bwp);
    void read_grp_ul_bwp__rach_cfg(XCONFD_YANGTREE_T* yt, std::shared_ptr<RachCfg>& rach_cfg);
    void read_grp_dl_bwp(XCONFD_YANGTREE_T* yt, DlBwp& dl_bwp);
    void read_grp_dl_bwp__cs_ss_cfg(XCONFD_YANGTREE_T* yt, CsSsCfg& cs_ss_cfg);

public:
    oam_agent_rcfd_cell_bwps(XCONFD_YANGTREE_T* yt);
    virtual ~oam_agent_rcfd_cell_bwps() {}
};

typedef std::shared_ptr<oam_agent_rcfd_cell_bwps> rcfd_cell_bwps_ptr;

} //end of namespace rcfd
} //end of namespace gnb_du
#endif /* __GNB_DU_OAM_AGENT_CELL_BWPS__ */