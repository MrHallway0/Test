#	From: @(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: stable/11/usr.sbin/lpr/lpr/Makefile 321276 2017-07-20 01:07:15Z ngie $

.PATH: ${.CURDIR:H}/common_source

BINDIR=	/usr/bin

PROG=	lpr
MAN=	lpr.1 printcap.5
BINOWN=	root
BINGRP=	daemon
BINMODE= 6555

CFLAGS+= -I${.CURDIR:H}/common_source

WARNS?=	2

LIBADD=	lpr

.include <bsd.prog.mk>
