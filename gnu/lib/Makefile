# $FreeBSD: stable/11/gnu/lib/Makefile 356775 2020-01-16 03:38:06Z kevans $

.include <src.opts.mk>

SUBDIR=			csu
SUBDIR+=		libdialog

.if ${MK_GCC} != "no" && ${MK_OPENMP} == "no"
SUBDIR+= libgcov libgomp
.endif

.if ${MK_TESTS} != "no"
SUBDIR+= tests
.endif

.if ${MK_BINUTILS} != "no" && ${MK_GDB} != "no"
SUBDIR+=	libreadline
.endif

.if ${MK_GNU_DIFF} != "no" || ${MK_GNU_GREP} != "no" || \
    ${MK_GNU_GREP_COMPAT} != "no" || ${MK_GDB} != "no"
SUBDIR+=		libregex
.endif

.if ${MK_LLVM_LIBUNWIND} == "no"
SUBDIR+=		libgcc
.endif

# libsupc++ uses libstdc++ headers, although 'make includes' should
# have taken care of that already.
.if ${MK_GNUCXX} != "no"
SUBDIR+= libstdc++ libsupc++
SUBDIR_DEPENDS_libsupc++:= libstdc++
.endif

SUBDIR_PARALLEL=

.include <bsd.subdir.mk>
