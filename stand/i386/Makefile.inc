# Common defines for all of /stand/i386/
#
# $FreeBSD: stable/11/stand/i386/Makefile.inc 333048 2018-04-27 01:21:52Z emaste $

.sinclude <bsd.linker.mk>

LOADER_ADDRESS?=0x200000
LDFLAGS+=	-nostdlib
.if defined(LINKER_TYPE) && ${LINKER_TYPE} == "lld"
LDFLAGS+=	-Wl,--no-rosegment
.endif

# BTX components
BTXDIR=		${BOOTOBJ}/i386/btx
BTXLDR=		${BTXDIR}/btxldr/btxldr
BTXKERN=	${BTXDIR}/btx/btx
BTXCRT=		${BTXDIR}/lib/crt0.o

BTXSRC=		${BOOTSRC}/i386/btx
BTXLIB=		${BTXSRC}/lib

CFLAGS+=	-I${BTXLIB}

# compact binary with no padding between text, data, bss
LDSCRIPT=	${BOOTSRC}/i386/boot.ldscript
# LDFLAGS_BIN=-e start -Ttext ${ORG} -Wl,-T,${LDSCRIPT},-S,--oformat,binary
# LD_FLAGS_BIN=-static -T ${LDSCRIPT} --gc-sections
LDFLAGS_BIN=-e start -Ttext ${ORG} -Wl,-N,-S,--oformat,binary
LD_FLAGS_BIN=-static -N --gc-sections

.if ${MACHINE_CPUARCH} == "amd64"
DO32=1
.endif

.if defined(LOADER_FIREWIRE_SUPPORT)
MK_LOADER_FIREWIRE=yes
.warning "LOADER_FIREWIRE_SUPPORT deprecated, please move to WITH_LOADER_FIREWIRE"
.endif

.include "../Makefile.inc"
