#include <sys/cdefs.h>
__MBSDID("$MidnightBSD$");

#define type		long double
#define	roundit		rintl
#define dtype		long
#define	fn		lrintl

#include "s_lrint.c"
