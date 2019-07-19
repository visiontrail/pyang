/*
 * filename: gnb_du_oam_agent_du_ns.h 
 * This header file contains implementation of OAM Agent RConfD Generate by Tools 
*/ 

#ifndef __GNB_DU_OAM_AGENT_DU_NS__
#define __GNB_DU_OAM_AGENT_DU_NS__

#include "gnb_du_oam_agent_rcfd_du_types.h"

namespace gnb_du 
{
namespace rcfd
{

typedef struct structNsCell
{
    uint8_t cell_id; 
    bool en_res_shared; 
    uint8_t res_id; 
    uint8_t dl_num_ue_per_tti; 
    uint8_t ul_num_ue_per_tti; 
    uint16_t dl_prb; 
    uint16_t ul_prb; 
    uint64_t dl_sla_trgt_rate; 
    uint64_t ul_sla_trgt_rate; 
} NsCell;

typedef struct structNsi
{
    uint8_t nsi_id; 
    std::vector<uint16_t> cores;
    std::vector<std::shared_ptr<NsCell>> cells;
} Nsi;

class oam_agent_rcfd_du_ns : public allocator
{
public:
   NsAgentTypeE agent_type_;
   IpAddrPort local_sm_;
   IpAddrPort remote_sm_;
   std::vector<std::shared_ptr<Nsi>> nsis_;

private:
    void read_local_sm(XCONFD_YANGTREE_T* yt, IpAddrPort& local_sm);
    void read_remote_sm(XCONFD_YANGTREE_T* yt, IpAddrPort& remote_sm);
    void read_nsis(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<Nsi>>& nsis);
    void read_grp_nsi(XCONFD_YANGTREE_T* yt, Nsi& nsi);
    void read_grp_nsi__cells(XCONFD_YANGTREE_T* yt, std::vector<std::shared_ptr<NsCell>>& cells);
    void read_grp_ns_cell(XCONFD_YANGTREE_T* yt, NsCell& ns_cell);

public:
    oam_agent_rcfd_du_ns(XCONFD_YANGTREE_T* yt);
    virtual ~oam_agent_rcfd_du_ns() {}
};

} //end of namespace rcfd
} //end of namespace gnb_du
#endif /* __GNB_DU_OAM_AGENT_DU_NS__ */