/*
 * Copyright (c) 2002 Networks Associates Technology, Inc.
 * All rights reserved.
 *
 * This software was developed for the FreeBSD Project by Marshall
 * Kirk McKusick and Network Associates Laboratories, the Security
 * Research Division of Network Associates, Inc. under DARPA/SPAWAR
 * contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA CHATS
 * research program.
 *
 * Copyright (c) 1980, 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: src/sbin/newfs/newfs.h,v 1.18 2006/10/31 21:52:27 pjd Exp $
 */

#include <libufs.h>

/*
 * The following two constants set the default block and fragment sizes.
 * Both constants must be a power of 2 and meet the following constraints:
 *	MINBSIZE <= DESBLKSIZE <= MAXBSIZE
 *	sectorsize <= DESFRAGSIZE <= DESBLKSIZE
 *	DESBLKSIZE / DESFRAGSIZE <= 8
 */
#define	DFL_FRAGSIZE	4096
#define	DFL_BLKSIZE	32768

/*
 * Cylinder groups may have up to MAXBLKSPERCG blocks. The actual
 * number used depends upon how much information can be stored
 * in a cylinder group map which must fit in a single file system
 * block. The default is to use as many as possible blocks per group.
 */
#define	MAXBLKSPERCG	0x7fffffff	/* desired fs_fpg ("infinity") */

/*
 * MAXBLKPG determines the maximum number of data blocks which are
 * placed in a single cylinder group. The default is one indirect
 * block worth of data blocks.
 */
#define MAXBLKPG(bsize)	((bsize) / sizeof(ufs2_daddr_t))

/*
 * Each file system has a number of inodes statically allocated.
 * We allocate one inode slot per NFPI fragments, expecting this
 * to be far more than we will ever need.
 */
#define	NFPI		4

/*
 * variables set up by front end.
 */
extern int	Lflag;		/* add a volume label */
extern int	Nflag;		/* run mkfs without writing file system */
extern int	Oflag;		/* build UFS1 format file system */
extern int	Rflag;		/* regression test */
extern int	Uflag;		/* enable soft updates for file system */
extern int	Eflag;		/* exit as if error, for testing */
extern int	Jflag;		/* enable gjournal for file system */
extern int	lflag;		/* enable multilabel MAC for file system */
extern int	nflag;		/* do not create .snap directory */
extern quad_t	fssize;		/* file system size */
extern int	sectorsize;	/* bytes/sector */
extern int	realsectorsize;	/* bytes/sector in hardware*/
extern int	fsize;		/* fragment size */
extern int	bsize;		/* block size */
extern int	maxbsize;	/* maximum clustering */
extern int	maxblkspercg;	/* maximum blocks per cylinder group */
extern int	minfree;	/* free space threshold */
extern int	opt;		/* optimization preference (space or time) */
extern int	density;	/* number of bytes per inode */
extern int	maxcontig;	/* max contiguous blocks to allocate */
extern int	maxbpg;		/* maximum blocks per file in a cyl group */
extern int	avgfilesize;	/* expected average file size */
extern int	avgfilesperdir;	/* expected number of files per directory */
extern u_char	*volumelabel;	/* volume label for filesystem */
extern struct uufsd disk;	/* libufs disk structure */

void mkfs (struct partition *, char *);
