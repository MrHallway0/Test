# $FreeBSD: stable/11/usr.sbin/bsnmpd/modules/snmp_usm/Makefile 312056 2017-01-13 09:07:29Z ngie $
#
# Author: Shteryana Shopova <syrinx@freebsd.org>

CONTRIB= ${SRCTOP}/contrib/bsnmp
.PATH: ${CONTRIB}/snmp_usm

MOD=	usm
SRCS=	usm_snmp.c
XSYM=	snmpUsmMIB usmNoAuthProtocol usmHMACMD5AuthProtocol \
	usmHMACSHAAuthProtocol usmNoPrivProtocol usmDESPrivProtocol \
	usmAesCfb128Protocol usmUserSecurityName

MAN=	snmp_usm.3

CFLAGS+= -I${CONTRIB}/lib -I${CONTRIB}/snmpd -DSNMPTREE_TYPES
CFLAGS+= -DHAVE_ERR_H -DHAVE_GETADDRINFO -DHAVE_STRLCPY -DHAVE_SYS_TREE_H

DEFS=	${MOD}_tree.def
BMIBS=

.include <bsd.snmpmod.mk>
