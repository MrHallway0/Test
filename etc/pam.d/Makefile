# $MidnightBSD$

.include <src.opts.mk>

NO_OBJ=

FILESGROUPS=	FILES

FILES=	README \
	cron \
	gdm \
	imap \
	kde \
	login \
	other \
	passwd pop3 \
	rsh \
	sshd su system \
	xdm

FILESDIR=	/etc/pam.d
FILESMODE=	644

.if ${MK_AT} != "no"
FILESGROUPS+=	AT
AT+=	atrun
ATPACKAGE+=	at
ATDIR=		${FILESDIR}
ATMODE=		${FILESMODE}
.endif

.if ${MK_FTP} != "no"
FILESGROUPS+=	FTP
FTP+=	ftpd
FTPPACKAGE+=	ftp
FTPDIR=		${FILESDIR}
FTPMODE=	${FILESMODE}
LINKS=	${FILESDIR}/ftpd ${FILESDIR}/ftp
.endif

.if ${MK_RCMDS} != "no"
FILESGROUPS+=	RCMDS
RCMDS+=		rsh
RCMDSPACKAGE+=	rcmds
RCMDSDIR=	${FILESDIR}
RCMDSMODE=	${FILESMODE}
.endif

.if ${MK_TELNET} != "no"
FILESGROUPS+=	TELNET
TELNET+=	telnetd
TELNETPACKAGE+=	telnet
TELNETDIR=	${FILESDIR}
TELNETMODE=	${FILESMODE}
.endif

FILESMODE_README=	444

.include <bsd.prog.mk>
