# $FreeBSD: stable/11/lib/libmp/Makefile 313538 2017-02-10 07:32:40Z ngie $

.include <src.opts.mk>

PACKAGE=lib${LIB}
LIB=		mp
SHLIB_MAJOR=	7
LIBADD=		crypto
MAN=		libmp.3
INCS=		mp.h
SRCS=		mpasbn.c

CFLAGS+=	-I${SRCTOP}/crypto

VERSION_DEF=	${SRCTOP}/lib/libc/Versions.def
SYMBOL_MAPS=	${.CURDIR}/Symbol.map

.if ${MK_TESTS} != "no"
SUBDIR+=	tests
.endif

.include <bsd.lib.mk>
