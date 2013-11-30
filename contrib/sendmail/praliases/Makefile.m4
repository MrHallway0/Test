dnl $Id: Makefile.m4,v 1.1.1.2 2006-02-25 02:33:57 laffer1 Exp $
include(confBUILDTOOLSDIR`/M4/switch.m4')

define(`confREQUIRE_LIBSM', `true')
# sendmail dir
SMSRCDIR=	ifdef(`confSMSRCDIR', `confSMSRCDIR', `${SRCDIR}/sendmail')
PREPENDDEF(`confENVDEF', `confMAPDEF')
PREPENDDEF(`confINCDIRS', `-I${SMSRCDIR} ')

bldPRODUCT_START(`executable', `praliases')
define(`bldINSTALL_DIR', `S')
define(`bldSOURCES', `praliases.c ')
bldPUSH_SMLIB(`sm')
bldPUSH_SMLIB(`smutil')
bldPUSH_SMLIB(`smdb')
APPENDDEF(`confENVDEF', `-DNOT_SENDMAIL')
bldPRODUCT_END

bldPRODUCT_START(`manpage', `praliases')
define(`bldSOURCES', `praliases.8')
bldPRODUCT_END

bldFINISH

