#	$FreeBSD: stable/11/usr.sbin/nmtree/Makefile 319119 2017-05-29 10:15:41Z ngie $

.include <src.opts.mk>

.PATH: ${SRCTOP}/contrib/mtree

PROG=		mtree
MAN=		mtree.5 mtree.8
SRCS=		compare.c crc.c create.c excludes.c getid.c misc.c mtree.c \
		only.c spec.c specspec.c verify.c

CFLAGS+=	-I${SRCTOP}/contrib/mknod
.PATH:		${SRCTOP}/contrib/mknod
SRCS+=		pack_dev.c

CFLAGS+=	-I${SRCTOP}/lib/libnetbsd
LIBADD=		netbsd md util

LINKS=		${BINDIR}/mtree ${BINDIR}/nmtree
MLINKS=		mtree.8 nmtree.8

.if ${MK_TESTS} != "no"
SUBDIR+=	tests
.endif

.include <bsd.prog.mk>
