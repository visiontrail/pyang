/*********************************************************************************
 * Filename: gnb_du_oam_agent_cell_base.h 
 *
 * Description: This header file contains implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:24
 *
 * YANG file latest revision: 2019-06-20
*********************************************************************************/ 

#ifndef __GNB_DU_OAM_AGENT_CELL_BASE__
#define __GNB_DU_OAM_AGENT_CELL_BASE__

#include "gnb_du_oam_agent_rcfd_cell_types.h"

namespace gnb_du 
{
namespace rcfd
{

typedef struct structSNssai
{
    SstT sst; 
    SdT sd; 
} SNssai;

typedef struct structPcch
{
    PagingCycleE default_paging_cycle; 
    PagingFrameOffsetTypeE paging_frame_offset_type; 
    uint8_t paging_frame_offset; 
    NsE ns; 
    bool f_pdcch_mon_occ_of_po_present; 
} Pcch;

typedef struct structPreambleIdRange
{
    uint16_t start;
    uint16_t size;
} PreambleIdRange;

typedef struct structNrCgi
{
    PlmnId plmn_id;
    NrCellIdT nr_cell_id;
} NrCgi;

typedef struct structServedPlmn
{
    PlmnId plmn_id; 
    std::vector<std::shared_ptr<SNssai>> s_nssais;
} ServedPlmn;

class oam_agent_rcfd_cell_base : public allocator
{
public:
    NrPciT nr_pci_; 
    NrCgi nr_cgi_; 
    std::vector<std::shared_ptr<ServedPlmn>> served_plmns_;
    NrModeTypeE nr_mode_type_; 
    ScsE scs_; 
    uint8_t slot_format_; 
    uint32_t max_ue_per_ul_tti_; 
    uint32_t max_ue_per_dl_tti_; 
    uint8_t max_dl_harq_tx_; 
    uint32_t max_msg4_harq_tx_; 
    uint32_t cfi_; 
    PreambleIdRange preamble_id_range_; 
    bool cp_ul_extended_; 
    DmrsTypeAPosE dmrs_type_a_pos_; 
    uint16_t csi_perd_; 
    Tac5GsT tac_5gs_; 
    std::shared_ptr<SiPerdE> sib2_perd_; 
    std::shared_ptr<SiPerdE> sib3_perd_; 
    uint8_t bcch_pcch_mcs_; 
    uint8_t rar_mcs_; 
    uint8_t ul_ccch_cqi_; 
    uint8_t dl_ccch_cqi_; 
    Pcch pcch_; 

private:
    void read_nr_cgi(XCONFD_YANGTREE_T* yt);
    void read_served_plmns(XCONFD_YANGTREE_T* yt);
    void read_preamble_id_range(XCONFD_YANGTREE_T* yt);
    void read_pcch(XCONFD_YANGTREE_T* yt);
    void read_grp_s_nssai(XCONFD_YANGTREE_T* yt, SNssai& s_nssai);
    void read_grp_pcch(XCONFD_YANGTREE_T* yt, Pcch& pcch);
    void read_grp_served_plmn(XCONFD_YANGTREE_T* yt, ServedPlmn& served_plmn);
    void read_grp_served_plmn__s_nssais(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<SNssai>>& s_nssais);

public:
    oam_agent_rcfd_cell_base(XCONFD_YANGTREE_T* yt);
    virtual ~oam_agent_rcfd_cell_base() {}
};

typedef std::shared_ptr<oam_agent_rcfd_cell_base> rcfd_cell_base_ptr;

} //end of namespace rcfd
} //end of namespace gnb_du
#endif /* __GNB_DU_OAM_AGENT_CELL_BASE__ */