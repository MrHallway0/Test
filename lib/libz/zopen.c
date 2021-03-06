/*
 * Public domain stdio wrapper for libz, written by Johan Danielsson.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: stable/11/lib/libz/zopen.c 257462 2013-10-31 18:44:40Z emaste $");

#include <stdio.h>
#include <zlib.h>

FILE *zopen(const char *fname, const char *mode);

/* convert arguments */
static int
xgzread(void *cookie, char *data, int size)
{
    return gzread(cookie, data, size);
}

static int
xgzwrite(void *cookie, const char *data, int size)
{
    return gzwrite(cookie, (void*)data, size);
}

static int
xgzclose(void *cookie)
{
    return gzclose(cookie);
}

static fpos_t
xgzseek(void *cookie,  fpos_t offset, int whence)
{
	return gzseek(cookie, (z_off_t)offset, whence);
}

FILE *
zopen(const char *fname, const char *mode)
{
    gzFile gz = gzopen(fname, mode);
    if(gz == NULL)
	return NULL;

    if(*mode == 'r')
	return (funopen(gz, xgzread, NULL, xgzseek, xgzclose));
    else
	return (funopen(gz, NULL, xgzwrite, xgzseek, xgzclose));
}
