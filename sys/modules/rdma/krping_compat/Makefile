# $FreeBSD: stable/11/sys/modules/rdma/krping_compat/Makefile 330503 2018-03-05 13:52:25Z hselasky $
.PATH: ${SRCTOP}/sys/contrib/rdma/krping_compat

KMOD= krping_compat
SRCS= krping.c krping_dev.c getopt.c
SRCS+=  bus_if.h device_if.h pci_if.h pcib_if.h vnode_if.h
SRCS+=  opt_sched.h opt_inet.h opt_inet6.h
CFLAGS+= -I${SRCTOP}/sys/ofed/include
CFLAGS+= -I${SRCTOP}/sys/ofed/include/uapi
CFLAGS+= -I${SRCTOP}/sys/compat/linuxkpi/common/include

.include <bsd.kmod.mk>
