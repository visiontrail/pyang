/*********************************************************************************
 * Filename: gnb_du_oam_agent_du_ns.h 
 *
 * Description: This header file contains implementation of OAM Agent RConfD.
 *
 * Generation time: 2019-08-27 09:54:29
 *
 * YANG file latest revision: 2019-07-08
*********************************************************************************/ 

#ifndef __GNB_DU_OAM_AGENT_DU_NS__
#define __GNB_DU_OAM_AGENT_DU_NS__

#include "gnb_du_oam_agent_rcfd_du_types.h"

namespace gnb_du 
{
namespace rcfd
{

typedef struct structNsi
{
    uint8_t nsi_id; 
    std::vector<uint16_t> cores;
} Nsi;

class oam_agent_rcfd_du_ns : public allocator
{
public:
    NsAgentTypeE agent_type_; 
    IpAddrPort local_sm_; 
    IpAddrPort remote_sm_; 
    std::vector<std::shared_ptr<Nsi>> nsis_;

private:
    void read_local_sm(XCONFD_YANGTREE_T* yt);
    void read_remote_sm(XCONFD_YANGTREE_T* yt);
    void read_nsis(XCONFD_YANGTREE_T* yt);
    void read_grp_nsi(XCONFD_YANGTREE_T* yt, Nsi& nsi);

public:
    oam_agent_rcfd_du_ns(XCONFD_YANGTREE_T* yt);
    virtual ~oam_agent_rcfd_du_ns() {}
};

typedef std::shared_ptr<oam_agent_rcfd_du_ns> rcfd_du_ns_ptr;

} //end of namespace rcfd
} //end of namespace gnb_du
#endif /* __GNB_DU_OAM_AGENT_DU_NS__ */