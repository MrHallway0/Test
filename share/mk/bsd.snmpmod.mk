# $FreeBSD: stable/11/share/mk/bsd.snmpmod.mk 313239 2017-02-04 17:10:19Z ngie $

INCSDIR=	${INCLUDEDIR}/bsnmp

SHLIB_NAME=	snmp_${MOD}.so.${SHLIB_MAJOR}
SRCS+=		${MOD}_oid.h ${MOD}_tree.c ${MOD}_tree.h
CLEANFILES+=	${MOD}_oid.h ${MOD}_tree.c ${MOD}_tree.h
CFLAGS+=	-I.

${MOD}_oid.h: ${MOD}_tree.def ${EXTRAMIBDEFS} ${EXTRAMIBSYMS}
	cat ${.ALLSRC} | gensnmptree -e ${XSYM} > ${.TARGET}

.ORDER: ${MOD}_tree.c ${MOD}_tree.h
${MOD}_tree.h: .NOMETA
${MOD}_tree.c ${MOD}_tree.h: ${MOD}_tree.def ${EXTRAMIBDEFS}
	cat ${.ALLSRC} | gensnmptree -p ${MOD}_

.if defined(DEFS)
FILESGROUPS+=	DEFS
DEFSDIR?=	${SHAREDIR}/snmp/defs
.endif

.if defined(BMIBS)
FILESGROUPS+=	BMIBS
BMIBSDIR?=	${SHAREDIR}/snmp/mibs
.endif

.if !target(smilint) && !empty(BMIBS)
LOCALBASE?=	/usr/local

SMILINT?=	${LOCALBASE}/bin/smilint

SMIPATH?=	${BMIBSDIR}:${LOCALBASE}/share/snmp/mibs

SMILINT_FLAGS?=	-c /dev/null -l6 -i group-membership

smilint: ${BMIBS}
	SMIPATH=${SMIPATH} ${SMILINT} ${SMILINT_FLAGS} ${.ALLSRC}
.endif
smilint: .PHONY

.include <bsd.lib.mk>
