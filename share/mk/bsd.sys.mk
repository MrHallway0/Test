# $FreeBSD: src/share/mk/bsd.sys.mk,v 1.37 2005/01/16 21:18:16 obrien Exp $
# $MidnightBSD: src/share/mk/bsd.sys.mk,v 1.11 2012/03/10 01:03:15 laffer1 Exp $
#
# This file contains common settings used for building MidnightBSD
# sources.

# Enable various levels of compiler warning checks.  These may be
# overridden (e.g. if using a non-gcc compiler) by defining NO_WARNS.

# for GCC:  http://gcc.gnu.org/onlinedocs/gcc-4.2.1/gcc/Warning-Options.html

# the default is gnu99 for now
CSTD?=		gnu99

.if ${CSTD} == "k&r"
CFLAGS+=	-traditional
.elif ${CSTD} == "c89" || ${CSTD} == "c90"
CFLAGS+=	-std=iso9899:1990
.elif ${CSTD} == "c94" || ${CSTD} == "c95"
CFLAGS+=	-std=iso9899:199409
.elif ${CSTD} == "c99"
CFLAGS+=	-std=iso9899:1999
.else
CFLAGS+=	-std=${CSTD}
.endif
.if !defined(NO_WARNS)
# -pedantic is problematic because it also imposes namespace restrictions
#CFLAGS+=	-pedantic
. if defined(WARNS)
.  if ${WARNS} >= 1
CWARNFLAGS+=	-Wsystem-headers
.   if !defined(NO_WERROR)
CWARNFLAGS+=	-Werror
.   endif
.  endif
.  if ${WARNS} >= 2
CWARNFLAGS+=	-Wall -Wno-format-y2k
.  endif
.  if ${WARNS} >= 3
CWARNFLAGS+=	-W -Wno-unused-parameter -Wstrict-prototypes\
			-Wmissing-prototypes -Wpointer-arith
.  endif
.  if ${WARNS} >= 4
CWARNFLAGS+=	-Wreturn-type -Wcast-qual -Wwrite-strings -Wswitch\
			-Wshadow -Wunused-parameter
.   if !defined(NO_WCAST_ALIGN)
CWARNFLAGS+=	-Wcast-align
.   endif
.  endif
# BDECFLAGS
.  if ${WARNS} >= 6
CWARNFLAGS+=	-Wchar-subscripts -Winline -Wnested-externs\
			-Wredundant-decls -Wold-style-definition
.  endif
.  if ${WARNS} >= 2 && ${WARNS} <= 4
# XXX Delete -Wuninitialized by default for now -- the compiler doesn't
# XXX always get it right.
CWARNFLAGS+=	-Wno-uninitialized
.  endif
CWARNFLAGS+=	-Wno-pointer-sign
. endif

. if defined(FORMAT_AUDIT)
WFORMAT		=	1
. endif
. if defined(WFORMAT)
.  if ${WFORMAT} > 0
#CWARNFLAGS+=	-Wformat-nonliteral -Wformat-security -Wno-format-extra-args
CWARNFLAGS+=	-Wformat=2 -Wno-format-extra-args
.   if !defined(NO_WERROR)
CWARNFLAGS+=	-Werror
.   endif
.  endif
. endif
. if defined(NO_WFORMAT)
CWARNFLAGS+=	-Wno-format
. endif
.endif

.if defined(IGNORE_PRAGMA)
CWARNFLAGS+=	-Wno-unknown-pragmas
.endif

.if ${MK_SSP} != "no"
SSP_CFLAGS?=	-fstack-protector
CFLAGS+=	${SSP_CFLAGS}
.endif

# Allow user-specified additional warning flags
CFLAGS+=	${CWARNFLAGS}
