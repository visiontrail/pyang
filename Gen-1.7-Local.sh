
# CELL:
python pyang.py -f xtypedef CertusNet_Yang/GNB/cell/certus-5gnr-du-cell-base@2019-06-20.yang \
                -p CertusNet_Yang/GNB/cell \
                -p /usr/local/confd/src/confd/yang \
                -o CertusNet_Yang/GNB/output/include/gnb_du_oam_agent_rcfd_cell_base.h

python pyang.py -f xtypedef CertusNet_Yang/GNB/cell/certus-5gnr-du-cell-bwps@2019-08-23.yang \
                -p CertusNet_Yang/GNB/cell \
                -p /usr/local/confd/src/confd/yang \
                -o CertusNet_Yang/GNB/output/include/gnb_du_oam_agent_rcfd_cell_bwps.h

python pyang.py -f xtypedef CertusNet_Yang/GNB/cell/certus-5gnr-du-cell-l1@2019-06-20.yang \
                -p CertusNet_Yang/GNB/cell \
                -p /usr/local/confd/src/confd/yang \
                -o CertusNet_Yang/GNB/output/include/gnb_du_oam_agent_rcfd_cell_l1.h

python pyang.py -f xtypedef CertusNet_Yang/GNB/cell/certus-5gnr-du-cell-ul-dl@2019-08-23.yang \
                -p CertusNet_Yang/GNB/cell \
                -p /usr/local/confd/src/confd/yang \
                -o CertusNet_Yang/GNB/output/include/gnb_du_oam_agent_rcfd_cell_ul_dl.h

# DU:
python pyang.py -f xtypedef CertusNet_Yang/GNB/du/certus-5gnr-du-du-ns@2019-07-08.yang \
                -p CertusNet_Yang/GNB/du \
                -p /usr/local/confd/src/confd/yang \
                -o CertusNet_Yang/GNB/output/include/gnb_du_oam_agent_rcfd_du_ns.h

python pyang.py -f xtypedef CertusNet_Yang/GNB/du/certus-5gnr-du-du-base@2019-07-08.yang \
                -p CertusNet_Yang/GNB/du \
                -p /usr/local/confd/src/confd/yang \
                -o CertusNet_Yang/GNB/output/include/gnb_du_oam_agent_rcfd_du_base.h



