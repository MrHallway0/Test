# $FreeBSD: stable/11/secure/libexec/Makefile 289393 2015-10-15 22:55:08Z bdrewery $

.include <src.opts.mk>

SUBDIR=
.if ${MK_OPENSSH} != "no"
SUBDIR+=sftp-server ssh-keysign ssh-pkcs11-helper
.endif

.if ${MK_TESTS} != "no"
SUBDIR+=tests
.endif

SUBDIR_PARALLEL=

.include <bsd.subdir.mk>
