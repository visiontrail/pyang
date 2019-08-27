/*********************************************************************************
 * Filename: gnb_du_oam_agent_du_base.h 
 *
 * Description: This header file contains implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:29
 *
 * YANG file latest revision: 2019-07-08
*********************************************************************************/ 

#ifndef __GNB_DU_OAM_AGENT_DU_BASE__
#define __GNB_DU_OAM_AGENT_DU_BASE__

#include "gnb_du_oam_agent_rcfd_du_types.h"

namespace gnb_du 
{
namespace rcfd
{

typedef struct structRlog
{
    std::string rlog_path; 
    std::string rlog_file_name; 
    uint8_t init_log; 
    uint32_t module_mask; 
    uint8_t num_of_rlog_files; 
    uint32_t rlog_file_size_lmt; 
    RlogLvlE rlog_level; 
} Rlog;

typedef struct structEgtpu
{
    IpAddr ip_addr;
    uint32_t teid_min;
    uint32_t teid_max;
} Egtpu;

typedef struct structNgpModuleLog
{
    NgpModuleIdE module_id; 
    LogLvlE log_lvl; 
} NgpModuleLog;

typedef struct structCfgParams
{
    uint16_t num_outbound_streams;
    uint16_t max_inbound_streams;
    uint16_t max_init_attempts;
    uint16_t hb_interval;
    uint16_t max_path_retx;
} CfgParams;

typedef struct structDuModuleLog
{
    DuModuleIdE module_id; 
    LogLvlE log_lvl; 
} DuModuleLog;

typedef struct structUe
{
    uint16_t max_num_ues;
    uint16_t rnti_start;
    uint16_t max_num_rnti;
} Ue;

typedef struct structF1UFlowCtrl
{
    uint16_t max_rlc_sdu_q_size;
    uint16_t rlc_sdu_q_lwr_thr;
    uint16_t rlc_sdu_q_upr_thr;
    uint16_t nrup_flw_ctrl_tmr;
    uint8_t ingress_pkt_read_per_tti;
} F1UFlowCtrl;

typedef struct structShortCycle
{
    uint32_t short_cycle_tm;
    uint32_t short_cycle_tmr;
} ShortCycle;

typedef struct structDrx
{
    std::shared_ptr<uint32_t> drx_on_duration_tmr;
    uint32_t inactivity_tmr; 
    uint8_t drx_rtt_tmr_ul; 
    uint8_t drx_rtt_tmr_dl; 
    uint32_t retx_tmr_ul; 
    uint32_t retx_tmr_dl; 
    uint32_t long_cycle; 
    uint32_t drx_cycle_start_offset; 
    std::shared_ptr<ShortCycle> short_cycle; 
    uint32_t drx_slot_offset; 
} Drx;

typedef struct structLog
{
    std::string file_name; 
    std::vector<std::shared_ptr<DuModuleLog>> du_modules;
    std::vector<std::shared_ptr<NgpModuleLog>> ngp_modules;
    Rlog rlog; 
} Log;

typedef struct structSctp
{
    IpAddrPort dst; 
    IpAddrPort src; 
    CfgParams cfg_params; 
} Sctp;

class oam_agent_rcfd_du_base : public allocator
{
public:
    uint64_t gnb_du_id_; 
    std::shared_ptr<std::string> gnb_du_name_; 
    uint8_t max_cell_supported_; 
    Ue ue_; 
    Sctp sctp_; 
    Egtpu egtpu_; 
    F1UFlowCtrl f1u_flow_ctrl_; 
    std::shared_ptr<Drx> drx_;
    Log log_; 

private:
    void read_ue(XCONFD_YANGTREE_T* yt);
    void read_sctp(XCONFD_YANGTREE_T* yt);
    void read_egtpu(XCONFD_YANGTREE_T* yt);
    void read_f1u_flow_ctrl(XCONFD_YANGTREE_T* yt);
    void read_drx(XCONFD_YANGTREE_T* yt);
    void read_log(XCONFD_YANGTREE_T* yt);
    void read_grp_rlog(XCONFD_YANGTREE_T* yt, Rlog& rlog);
    void read_grp_drx(XCONFD_YANGTREE_T* yt, Drx& drx);
    void read_grp_drx__short_cycle(XCONFD_YANGTREE_T* yt, std::shared_ptr<ShortCycle>& short_cycle);
    void read_grp_ngp_module_log(XCONFD_YANGTREE_T* yt, NgpModuleLog& ngp_module_log);
    void read_grp_log(XCONFD_YANGTREE_T* yt, Log& log);
    void read_grp_log__du_modules(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<DuModuleLog>>& du_modules);
    void read_grp_log__ngp_modules(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<NgpModuleLog>>& ngp_modules);
    void read_grp_log__rlog(XCONFD_YANGTREE_T* yt, Rlog& rlog);
    void read_grp_du_module_log(XCONFD_YANGTREE_T* yt, DuModuleLog& du_module_log);
    void read_grp_sctp(XCONFD_YANGTREE_T* yt, Sctp& sctp);
    void read_grp_sctp__dst(XCONFD_YANGTREE_T* yt, IpAddrPort& dst);
    void read_grp_sctp__src(XCONFD_YANGTREE_T* yt, IpAddrPort& src);
    void read_grp_sctp__cfg_params(XCONFD_YANGTREE_T* yt, CfgParams& cfg_params);

public:
    oam_agent_rcfd_du_base(XCONFD_YANGTREE_T* yt);
    virtual ~oam_agent_rcfd_du_base() {}
};

typedef std::shared_ptr<oam_agent_rcfd_du_base> rcfd_du_base_ptr;

} //end of namespace rcfd
} //end of namespace gnb_du
#endif /* __GNB_DU_OAM_AGENT_DU_BASE__ */