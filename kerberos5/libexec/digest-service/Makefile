# $FreeBSD: stable/11/kerberos5/libexec/digest-service/Makefile 344200 2019-02-16 03:18:52Z nyan $

PROG=	digest-service
MAN=
CFLAGS+=	-I${KRB5DIR}/kdc \
		-I${KRB5DIR}/lib/asn1 \
		-I${KRB5DIR}/lib/krb5 \
		-I${KRB5DIR}/lib/ipc \
		-I${KRB5DIR}/lib/wind \
		-I${KRB5DIR}/lib/roken \
		-I${SRCTOP}/contrib/com_err
LIBADD=	hdb kdc heimipcs krb5 roken asn1 crypto vers heimntlm
LDFLAGS=${LDAPLDFLAGS}

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/kdc
