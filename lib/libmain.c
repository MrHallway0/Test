/* libmain - flex run-time support library "main" function */

/* $Header: /home/cvs/src/usr.bin/lex/lib/libmain.c,v 1.2 2012-10-29 20:54:16 laffer1 Exp $
 * $MidnightBSD: trunk/usr.bin/lex/lib/libmain.c 6515 2013-12-20 23:32:25Z laffer1 $ */

extern int yylex();

int main( argc, argv )
int argc;
char *argv[];
	{
	while ( yylex() != 0 )
		;

	return 0;
	}
