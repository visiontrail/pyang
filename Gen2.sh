# CELL:
python pyang.py -f xtypedef /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/cell/certus-5gnr-du-cell-base@2019-06-20.yang \
                -p /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/cell \
                -p /usr/local/confd/src/confd/yang \
                -o /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/include/gnb_du_oam_agent_rcfd_cell_base.h

python pyang.py -f xtypedef /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/cell/certus-5gnr-du-cell-channel@2019-06-20.yang \
                -p /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/cell \
                -p /usr/local/confd/src/confd/yang \
                -o /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/include/gnb_du_oam_agent_rcfd_cell_channel.h

python pyang.py -f xtypedef /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/cell/certus-5gnr-du-cell-l1@2019-06-20.yang \
                -p /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/cell \
                -p /usr/local/confd/src/confd/yang \
                -o /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/include/gnb_du_oam_agent_rcfd_cell_l1.h

python pyang.py -f xtypedef /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/cell/certus-5gnr-du-cell-schd@2019-06-20.yang \
                -p /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/cell \
                -p /usr/local/confd/src/confd/yang \
                -o /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/include/gnb_du_oam_agent_rcfd_cell_schd.h

# DU:
python pyang.py -f xtypedef /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/du/certus-5gnr-du-du-base@2019-07-08.yang \
                -p /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/du \
                -p /usr/local/confd/src/confd/yang \
                -o /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/include/gnb_du_oam_agent_rcfd_du_base.h

python pyang.py -f xtypedef /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/du/certus-5gnr-du-du-ns@2019-07-08.yang \
                -p /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/yang/du \
                -p /usr/local/confd/src/confd/yang \
                -o /home/guoliang/Desktop/WorkSpace/CertusNet/layer2oam/radisys-du/src/du_app/oam_agent/include/gnb_du_oam_agent_rcfd_du_ns.h



