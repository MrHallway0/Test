# $FreeBSD: stable/11/tests/sys/mqueue/Makefile 306905 2016-10-09 12:34:56Z kib $

TESTSDIR=	${TESTSBASE}/sys/mqueue

ATF_TESTS_SH=	mqueue_test

BINDIR=		${TESTSDIR}

CFLAGS+=	-I${SRCTOP}/tests

PROGS+=		mqtest1
PROGS+=		mqtest2
PROGS+=		mqtest3
PROGS+=		mqtest4
PROGS+=		mqtest5

LIBADD+=	rt

WARNS?=		6

.include <bsd.test.mk>
