# $DragonFly: src/sys/dev/netif/et/Makefile,v 1.1 2007/10/12 14:12:42 sephe Exp $
# $FreeBSD: stable/11/sys/modules/et/Makefile 319182 2017-05-30 04:11:12Z ngie $

.PATH: ${SRCTOP}/sys/dev/et

KMOD=	if_et
SRCS=	if_et.c
SRCS+=	bus_if.h pci_if.h device_if.h miibus_if.h

.include <bsd.kmod.mk>
