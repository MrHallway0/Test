# $FreeBSD: stable/11/lib/libsmb/Makefile 313538 2017-02-10 07:32:40Z ngie $

.include <src.opts.mk>

PACKAGE=lib${LIB}
CONTRIBDIR=	${SRCTOP}/contrib/smbfs
.PATH: ${CONTRIBDIR}/lib/smb

LIB=	smb
SHLIB_MAJOR=	4
LIBADD=	kiconv

SRCS=	rcfile.c ctx.c cfopt.c subr.c nls.c rap.c mbuf.c rq.c file.c \
	print.c \
	kiconv.c \
	nb.c nb_name.c nb_net.c nbns_rq.c

WARNS?=	1
CFLAGS+= -DSMB_CFG_FILE=\"/etc/nsmb.conf\" -I${CONTRIBDIR}/include

.if ${MK_ICONV} != "no"
CFLAGS+= -DHAVE_ICONV=1
.endif

.include <bsd.lib.mk>
