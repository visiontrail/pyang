/*********************************************************************************
 * Filename: gnb_du_oam_agent_cell_l1.h 
 *
 * Description: This header file contains implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:27
 *
 * YANG file latest revision: 2019-06-20
*********************************************************************************/ 

#ifndef __GNB_DU_OAM_AGENT_CELL_L1__
#define __GNB_DU_OAM_AGENT_CELL_L1__

#include "gnb_du_oam_agent_rcfd_cell_types.h"

namespace gnb_du 
{
namespace rcfd
{

typedef struct structPlmnIdInfo
{
    std::vector<std::shared_ptr<PlmnId>> plmn_ids;
    NrCellIdT nr_cell_id; 
    uint32_t tac; 
    uint8_t ranac; 
    bool cell_rsrvd_for_operator_use; 
} PlmnIdInfo;

typedef struct structPdcchCfgSib1
{
    CoresetZeroT coreset_zero;
    SsZeroT ss_zero;
} PdcchCfgSib1;

typedef struct structPrach
{
    uint16_t root_seq_idx; 
    uint8_t cfg_idx; 
    uint8_t zero_correlation_zone_cfg; 
    uint8_t freq_offset; 
    ScsE scs; 
    std::shared_ptr<RestrictedSetCfgE> restricted_set;
    uint16_t freq_start; 
    Msg1FdmE fdm; 
    SsbPerRachOccE ssb_per_rach_occ; 
} Prach;

typedef struct structUeTimers
{
    T300E t300; 
    T301E t301; 
    T310E t310; 
    N310E n310; 
    T311E t311; 
    N311E n311; 
    T319E t319; 
} UeTimers;

typedef struct structCellSelInfo
{
    QRxLvlMinT q_rx_lvl_min; 
    QRxLvlMinT q_rx_lvl_min_sul; 
    QQualMinT q_qual_min; 
} CellSelInfo;

typedef struct structMib
{
    ScsCmnE scs_cmn; 
    SsbScOffsetT ssb_sc_offset; 
    CellBarredE cell_barred; 
    IntraFreqReselE intra_freq_resel; 
    PdcchCfgSib1 pdcch_cfg_sib1; 
} Mib;

typedef struct structCellAccessInfo
{
    std::vector<std::shared_ptr<PlmnIdInfo>> plmn_id_infos;
} CellAccessInfo;

typedef struct structSib1
{
    CellSelInfo cell_sel_info; 
    CellAccessInfo cell_access_info; 
    UeTimers ue_timers; 
} Sib1;

class oam_agent_rcfd_cell_l1 : public allocator
{
public:
    uint32_t ul_central_freq_; 
    uint32_t dl_central_freq_; 
    uint32_t ssb_pwr_; 
    uint8_t ssb_prb_offset_; 
    uint8_t ca_lvl_; 
    ScsCarrierK0E ul_carrier_k0_; 
    ScsCarrierK0E dl_carrier_k0_; 
    std::shared_ptr<Prach> prach_;
    Mib mib_; 
    Sib1 sib1_; 

private:
    void read_prach(XCONFD_YANGTREE_T* yt);
    void read_mib(XCONFD_YANGTREE_T* yt);
    void read_sib1(XCONFD_YANGTREE_T* yt);
    void read_grp_cell_access_info(XCONFD_YANGTREE_T* yt, CellAccessInfo& cell_access_info);
    void read_grp_cell_access_info__plmn_id_infos(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<PlmnIdInfo>>& plmn_id_infos);
    void read_grp_plmn_id_info(XCONFD_YANGTREE_T* yt, PlmnIdInfo& plmn_id_info);
    void read_grp_plmn_id_info__plmn_ids(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<PlmnId>>& plmn_ids);
    void read_grp_sib1(XCONFD_YANGTREE_T* yt, Sib1& sib1);
    void read_grp_sib1__cell_sel_info(XCONFD_YANGTREE_T* yt, CellSelInfo& cell_sel_info);
    void read_grp_sib1__cell_access_info(XCONFD_YANGTREE_T* yt, CellAccessInfo& cell_access_info);
    void read_grp_sib1__ue_timers(XCONFD_YANGTREE_T* yt, UeTimers& ue_timers);
    void read_grp_mib(XCONFD_YANGTREE_T* yt, Mib& mib);
    void read_grp_mib__pdcch_cfg_sib1(XCONFD_YANGTREE_T* yt, PdcchCfgSib1& pdcch_cfg_sib1);
    void read_grp_ue_timers(XCONFD_YANGTREE_T* yt, UeTimers& ue_timers);
    void read_grp_cell_sel_info(XCONFD_YANGTREE_T* yt, CellSelInfo& cell_sel_info);
    void read_grp_prach(XCONFD_YANGTREE_T* yt, Prach& prach);

public:
    oam_agent_rcfd_cell_l1(XCONFD_YANGTREE_T* yt);
    virtual ~oam_agent_rcfd_cell_l1() {}
};

typedef std::shared_ptr<oam_agent_rcfd_cell_l1> rcfd_cell_l1_ptr;

} //end of namespace rcfd
} //end of namespace gnb_du
#endif /* __GNB_DU_OAM_AGENT_CELL_L1__ */