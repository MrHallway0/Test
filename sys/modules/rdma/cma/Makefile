# $MidnightBSD$

RDMA=	${.CURDIR}/../../../contrib/rdma
.PATH: ${RDMA}

KMOD=  rdma_cma
SRCS=  device_if.h bus_if.h pci_if.h pcib_if.h opt_sched.h
SRCS+= rdma_cma.c 

.include <bsd.kmod.mk>
