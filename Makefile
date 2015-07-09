# $MidnightBSD: trunk/usr.bin/lex/Makefile 6515 2013-12-20 23:32:25Z laffer1 $
#
# By default, flex will be configured to generate 8-bit scanners only if the
# -8 flag is given.  If you want it to always generate 8-bit scanners, add
# "-DDEFAULT_CSIZE=256" to CFLAGS.  Note that doing so will double the size
# of all uncompressed scanners.
#
# Bootstrapping of lex is handled automatically.
# Also note that flex.skel no longer gets installed.
#

PROG=		lex
LINKS+=	${BINDIR}/lex ${BINDIR}/lex++
LINKS+=	${BINDIR}/lex ${BINDIR}/flex
LINKS+=	${BINDIR}/lex ${BINDIR}/flex++

SRCS=		scan.c ccl.c dfa.c ecs.c gen.c main.c misc.c nfa.c parse.y \
		skel.c sym.c tblcmp.c yylex.c
LFLAGS+=	-is
CFLAGS+=	-I. -I${.CURDIR}
INCS=		FlexLexer.h
INCSDIR=	${INCLUDEDIR}
MLINKS+=	lex.1 flex.1
MLINKS+=	lex.1 flex++.1
MLINKS+=	lex.1 lex++.1

WARNS?=		2

CLEANFILES=	scan.c skel.c

SUBDIR=		lib

skel.c: mkskel.sh flex.skl
	sh ${.CURDIR}/mkskel.sh ${.CURDIR}/flex.skl > skel.c

bootstrap: initscan.c
	@cmp -s ${.CURDIR}/initscan.c scan.c || { \
		echo "Bootstrapping flex" ; \
		rm -f scan.c ; \
		cp -f ${.CURDIR}/initscan.c scan.c ; \
	}

test: check
check: $(PROG)
	./$(PROG) $(LFLAGS) -t $(COMPRESSION) $(.CURDIR)/scan.l \
	| sed s,\"$(.CURDIR)/scan.l",\"scan.l", \
	| diff -I '\$$FreeBS[D]:.*\$$' $(.CURDIR)/initscan.c -
	@echo "Check successful"

.include <bsd.prog.mk>
