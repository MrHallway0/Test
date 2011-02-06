/*-
 * Copyright (c) 2003-2007 Tim Kientzle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "archive_platform.h"
__MBSDID("$MidnightBSD$");

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "archive.h"

/*
 * Glue to read an archive from a block of memory.
 *
 * This is mostly a huge help in building test harnesses;
 * test programs can build archives in memory and read them
 * back again without having to mess with files on disk.
 */

struct read_memory_data {
	unsigned char	*buffer;
	unsigned char	*end;
	ssize_t	 read_size;
};

static int	memory_read_close(struct archive *, void *);
static int	memory_read_open(struct archive *, void *);
#if ARCHIVE_API_VERSION < 2
static ssize_t	memory_read_skip(struct archive *, void *, size_t request);
#else
static off_t	memory_read_skip(struct archive *, void *, off_t request);
#endif
static ssize_t	memory_read(struct archive *, void *, const void **buff);

int
archive_read_open_memory(struct archive *a, void *buff, size_t size)
{
	return archive_read_open_memory2(a, buff, size, size);
}

/*
 * Don't use _open_memory2() in production code; the archive_read_open_memory()
 * version is the one you really want.  This is just here so that
 * test harnesses can exercise block operations inside the library.
 */
int
archive_read_open_memory2(struct archive *a, void *buff,
    size_t size, size_t read_size)
{
	struct read_memory_data *mine;

	mine = (struct read_memory_data *)malloc(sizeof(*mine));
	if (mine == NULL) {
		archive_set_error(a, ENOMEM, "No memory");
		return (ARCHIVE_FATAL);
	}
	memset(mine, 0, sizeof(*mine));
	mine->buffer = (unsigned char *)buff;
	mine->end = mine->buffer + size;
	mine->read_size = read_size;
	return (archive_read_open2(a, mine, memory_read_open,
		    memory_read, memory_read_skip, memory_read_close));
}

/*
 * There's nothing to open.
 */
static int
memory_read_open(struct archive *a, void *client_data)
{
	(void)a; /* UNUSED */
	(void)client_data; /* UNUSED */
	return (ARCHIVE_OK);
}

/*
 * This is scary simple:  Just advance a pointer.  Limiting
 * to read_size is not technically necessary, but it exercises
 * more of the internal logic when used with a small block size
 * in a test harness.  Production use should not specify a block
 * size; then this is much faster.
 */
static ssize_t
memory_read(struct archive *a, void *client_data, const void **buff)
{
	struct read_memory_data *mine = (struct read_memory_data *)client_data;
	ssize_t size;

	(void)a; /* UNUSED */
	*buff = mine->buffer;
	size = mine->end - mine->buffer;
	if (size > mine->read_size)
		size = mine->read_size;
        mine->buffer += size;
	return (size);
}

/*
 * Advancing is just as simple.  Again, this is doing more than
 * necessary in order to better exercise internal code when used
 * as a test harness.
 */
#if ARCHIVE_API_VERSION < 2
static ssize_t
memory_read_skip(struct archive *a, void *client_data, size_t skip)
#else
static off_t
memory_read_skip(struct archive *a, void *client_data, off_t skip)
#endif
{
	struct read_memory_data *mine = (struct read_memory_data *)client_data;

	(void)a; /* UNUSED */
	if ((off_t)skip > (off_t)(mine->end - mine->buffer))
		skip = mine->end - mine->buffer;
	/* Round down to block size. */
	skip /= mine->read_size;
	skip *= mine->read_size;
	mine->buffer += skip;
	return (skip);
}

/*
 * Close is just cleaning up our one small bit of data.
 */
static int
memory_read_close(struct archive *a, void *client_data)
{
	struct read_memory_data *mine = (struct read_memory_data *)client_data;
	(void)a; /* UNUSED */
	free(mine);
	return (ARCHIVE_OK);
}
