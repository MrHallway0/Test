#
# @(#)Makefile	2.1 88/08/02 4.0 RPCSRC
#
#
#   Build all demo services
#
# $FreeBSD: stable/11/share/examples/sunrpc/Makefile 299293 2016-05-10 00:51:50Z gjb $
#

PACKAGE=examples
FILESDIR=${SHAREDIR}/examples/sunrpc
MAKE = make
LIB=

SUBDIR= dir msg sort

all:	${SUBDIR}

clean cleanup:
	cd dir; $(MAKE) ${MFLAGS} cleanup
	cd msg; $(MAKE) ${MFLAGS} cleanup
	cd sort; $(MAKE) ${MFLAGS} cleanup

install:
	@echo "No installations done."

${SUBDIR}:	FRC
	cd $@; $(MAKE) ${MFLAGS} LIB=$(LIB)

FRC:
