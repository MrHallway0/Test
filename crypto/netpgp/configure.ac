# $NetBSD: configure.ac,v 1.15 2009/05/27 00:38:26 agc Exp $
#
# Process this file with autoconf to produce a configure script.

AC_INIT([netpgp], [20090526], [Alistair Crooks <agc@netbsd.org> c0596823])
AC_PREREQ([2.62])
AC_REVISION([$Revision: 1.1.1.1 $])

AS_SHELL_SANITIZE

AC_CONFIG_SRCDIR([src/bin/netpgp.c])
AC_CONFIG_AUX_DIR([buildaux])
AC_CONFIG_HEADER([src/lib/config.h])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_MAINTAINER_MODE

AC_CANONICAL_HOST
CANONICAL_HOST=$host
AC_SUBST([CANONICAL_HOST])

# Checks for programs.
#
AC_PROG_MAKE_SET
AC_PROG_AWK
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_LN_S

# Compiler characteristics
#
AC_MSG_CHECKING([if using gcc])
AS_IF([test "$GCC" = "yes"],
      [WARNCFLAGS="-Werror -Wall -Wpointer-arith"
       AC_MSG_RESULT([yes; adding to CFLAGS: "$WARNCFLAGS"])],
      [WARNCFLAGS=""
       AC_MSG_RESULT([no])])
AC_SUBST([WARNCFLAGS])

# Checks for header files.
#
AC_HEADER_STDC
AC_CHECK_HEADERS([CommonCrypto/CommonDigest.h])
AC_CHECK_HEADERS([dmalloc.h direct.h errno.h fcntl.h \
                 inttypes.h limits.h malloc.h zlib.h])
AC_CHECK_HEADERS([openssl/aes.h openssl/bn.h openssl/cast.h openssl/des.h \
                  openssl/dsa.h openssl/err.h openssl/idea.h openssl/md5.h \
                  openssl/rand.h openssl/rsa.h openssl/sha.h openssl/err.h \
                  openssl/sha.h])
AC_CHECK_HEADERS([sys/cdefs.h sys/file.h sys/mman.h sys/param.h \
                  sys/resource.h sys/uio.h])

AC_CHECK_HEADERS([bzlib.h],
                 [],
                 [AC_MSG_FAILURE([missing <bzlib.h>; is bzip2 installed?])])

# Checks for typedefs, structures, and compiler characteristics.
#
AC_TYPE_LONG_LONG_INT
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

AC_CHECK_TYPES([SHA256_CTX],
               [],
               [AC_MSG_FAILURE([missing SHA256_CTX; is openssl 0.9.8 or newer installed?])],
              [[
#if defined(HAVE_SYS_TYPES_H)
#include <sys/types.h>
#endif
#if defined(HAVE_OPENSSL_SHA_H)
#include <openssl/sha.h>
#endif
#if defined(HAVE_COMMONCRYPTO_COMMONDIGEST_H)
#define COMMON_DIGEST_FOR_OPENSSL 1
#include <CommonCrypto/CommonDigest.h>
#endif
]])

# Checks for library functions.
#
AC_SEARCH_LIBS([gzopen], [z])
AC_SEARCH_LIBS([BZ2_bzDecompress], [bz2])
AC_SEARCH_LIBS([RSA_public_encrypt], [crypto])

# Initialize the testsuite
#
AC_CONFIG_TESTDIR([tests])
AM_MISSING_PROG([AUTOM4TE], [autom4te])

# Generate the Makefiles
#
AC_CONFIG_FILES([
        Makefile
        include/Makefile
        src/Makefile
        src/lib/Makefile
        src/bin/Makefile
        tests/Makefile
        tests/atlocal
])
AC_OUTPUT

# Display feature results
#
AC_MSG_NOTICE([ === Configuration results ===])
AC_MSG_NOTICE([Version:             $PACKAGE_VERSION])
AC_MSG_NOTICE([C compiler:          $CC])
AC_MSG_NOTICE([Warning CFLAGS:      $WARNCFLAGS])
AC_MSG_NOTICE([=============================])
