# $FreeBSD: stable/11/sbin/nvmecontrol/Makefile 328728 2018-02-01 19:46:41Z mav $

PACKAGE=runtime
PROG=	nvmecontrol
SRCS=	nvmecontrol.c devlist.c firmware.c identify.c logpage.c	\
	perftest.c reset.c nvme_util.c power.c util.c wdc.c
MAN=	nvmecontrol.8

.PATH:	${SRCTOP}/sys/dev/nvme

.include <bsd.prog.mk>
