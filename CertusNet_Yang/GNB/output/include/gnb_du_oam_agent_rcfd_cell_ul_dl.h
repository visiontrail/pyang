/*********************************************************************************
 * Filename: gnb_du_oam_agent_cell_ul_dl.h 
 *
 * Description: This header file contains implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:28
 *
 * YANG file latest revision: 2019-08-23
*********************************************************************************/ 

#ifndef __GNB_DU_OAM_AGENT_CELL_UL_DL__
#define __GNB_DU_OAM_AGENT_CELL_UL_DL__

#include "gnb_du_oam_agent_rcfd_cell_types.h"

namespace gnb_du 
{
namespace rcfd
{

typedef struct structScsSpecCarrier
{
    ScsE scs; 
    OffsetPointACarrierT offset_to_carrier; 
} ScsSpecCarrier;

typedef struct structFreqInfoCmn
{
    uint32_t abs_freq_point_a; 
    ArfcnT abs_arfcn_point_a; 
    ArfcnT nr_arfcn; 
    ChannelBwE channel_bw; 
    std::vector<uint16_t> nr_freq_bands;
    std::vector<std::shared_ptr<ScsSpecCarrier>> scs_spec_carriers;
} FreqInfoCmn;

typedef struct structDlFreq
{
    FreqInfoCmn freq_info_cmn; 
    uint32_t abs_freq_ssb; 
    ArfcnT abs_arfcn_ssb; 
} DlFreq;

typedef struct structUlFreq
{
    FreqInfoCmn freq_info_cmn; 
    uint8_t addtl_spectrum_emi; 
    int8_t p_max; 
    bool freq_shift_7p5khz; 
} UlFreq;

typedef struct structSul
{
    uint32_t max_ue_per_tti; 
    uint8_t ccch_cqi; 
    std::shared_ptr<uint8_t> tar_cqi;
    bool harmonic; 
    bool freq_muted; 
    std::shared_ptr<UlFreq> freq_info; 
} Sul;

class oam_agent_rcfd_cell_ul_dl : public allocator
{
public:
    std::shared_ptr<UlFreq> ul_freq_;
    DlFreq dl_freq_; 
    std::shared_ptr<Sul> sul_;

private:
    void read_ul_freq(XCONFD_YANGTREE_T* yt);
    void read_dl_freq(XCONFD_YANGTREE_T* yt);
    void read_sul(XCONFD_YANGTREE_T* yt);
    void read_grp_freq_info_cmn(XCONFD_YANGTREE_T* yt, FreqInfoCmn& freq_info_cmn);
    void read_grp_freq_info_cmn__scs_spec_carriers(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<ScsSpecCarrier>>& scs_spec_carriers);
    void read_grp_sul(XCONFD_YANGTREE_T* yt, Sul& sul);
    void read_grp_sul__freq_info(XCONFD_YANGTREE_T* yt, std::shared_ptr<UlFreq>& freq_info);
    void read_grp_dl_freq(XCONFD_YANGTREE_T* yt, DlFreq& dl_freq);
    void read_grp_dl_freq__freq_info_cmn(XCONFD_YANGTREE_T* yt, FreqInfoCmn& freq_info_cmn);
    void read_grp_scs_spec_carrier(XCONFD_YANGTREE_T* yt, ScsSpecCarrier& scs_spec_carrier);
    void read_grp_ul_freq(XCONFD_YANGTREE_T* yt, UlFreq& ul_freq);
    void read_grp_ul_freq__freq_info_cmn(XCONFD_YANGTREE_T* yt, FreqInfoCmn& freq_info_cmn);

public:
    oam_agent_rcfd_cell_ul_dl(XCONFD_YANGTREE_T* yt);
    virtual ~oam_agent_rcfd_cell_ul_dl() {}
};

typedef std::shared_ptr<oam_agent_rcfd_cell_ul_dl> rcfd_cell_ul_dl_ptr;

} //end of namespace rcfd
} //end of namespace gnb_du
#endif /* __GNB_DU_OAM_AGENT_CELL_UL_DL__ */