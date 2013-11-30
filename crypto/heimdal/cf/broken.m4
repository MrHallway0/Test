dnl $Id: broken.m4,v 1.1.1.2 2006-02-25 02:34:17 laffer1 Exp $
dnl
dnl
dnl Same as AC _REPLACE_FUNCS, just define HAVE_func if found in normal
dnl libraries 

AC_DEFUN([AC_BROKEN],
[AC_FOREACH([rk_func], [$1],
	[AC_CHECK_FUNC(rk_func,
		[AC_DEFINE_UNQUOTED(AS_TR_CPP(HAVE_[]rk_func), 1, 
			[Define if you have the function `]rk_func['.])],
		[rk_LIBOBJ(rk_func)])])])
