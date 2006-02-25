dnl $Id: krb-prog-yacc.m4,v 1.1.1.2 2006-02-25 02:34:17 laffer1 Exp $
dnl
dnl
dnl We prefer byacc or yacc because they do not use `alloca'
dnl

AC_DEFUN([AC_KRB_PROG_YACC],
[AC_CHECK_PROGS(YACC, byacc yacc 'bison -y')
if test "$YACC" = ""; then
  AC_MSG_WARN([yacc not found - some stuff will not build])
fi
])
