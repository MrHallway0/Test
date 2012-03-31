/* $MidnightBSD$ */
/*-
 * Copyright (c) 1988, 1993
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
 *	@(#)ktrace.h	8.1 (Berkeley) 6/2/93
 * $FreeBSD: src/sys/sys/ktrace.h,v 1.33.2.1.2.1 2008/11/25 02:59:29 kensmith Exp $
 */

#ifndef _SYS_KTRACE_H_
#define _SYS_KTRACE_H_

/*
 * operations to ktrace system call  (KTROP(op))
 */
#define KTROP_SET		0	/* set trace points */
#define KTROP_CLEAR		1	/* clear trace points */
#define KTROP_CLEARFILE		2	/* stop all tracing to file */
#define	KTROP(o)		((o)&3)	/* macro to extract operation */
/*
 * flags (ORed in with operation)
 */
#define KTRFLAG_DESCEND		4	/* perform op on all children too */

/*
 * ktrace record header
 */
struct ktr_header {
	int	ktr_len;		/* length of buf */
	short	ktr_type;		/* trace record type */
	pid_t	ktr_pid;		/* process id */
	char	ktr_comm[MAXCOMLEN+1];	/* command name */
	struct	timeval ktr_time;	/* timestamp */
	intptr_t	ktr_tid;	/* was ktr_buffer */
};

/*
 * Test for kernel trace point (MP SAFE).
 *
 * KTRCHECK() just checks that the type is enabled and is only for
 * internal use in the ktrace subsystem.  KTRPOINT() checks against
 * ktrace recursion as well as checking that the type is enabled and
 * is the public interface.
 */
#define	KTRCHECK(td, type)	((td)->td_proc->p_traceflag & (1 << type))
#define KTRPOINT(td, type)						\
	(KTRCHECK((td), (type)) && !((td)->td_pflags & TDP_INKTRACE))
#define	KTRCHECKDRAIN(td)	(!(STAILQ_EMPTY(&(td)->td_proc->p_ktr)))
#define	KTRUSERRET(td) do {						\
	if (KTRCHECKDRAIN(td))						\
		ktruserret(td);						\
} while (0)
#define	KTRPROCEXIT(td) do {						\
	if (KTRCHECKDRAIN(td))						\
		ktrprocexit(td);					\
} while (0)

/*
 * ktrace record types
 */

/*
 * KTR_SYSCALL - system call record
 */
#define KTR_SYSCALL	1
struct ktr_syscall {
	short	ktr_code;		/* syscall number */
	short	ktr_narg;		/* number of arguments */
	/*
	 * followed by ktr_narg register_t
	 */
	register_t	ktr_args[1];
};

/*
 * KTR_SYSRET - return from system call record
 */
#define KTR_SYSRET	2
struct ktr_sysret {
	short	ktr_code;
	short	ktr_eosys;
	int	ktr_error;
	register_t	ktr_retval;
};

/*
 * KTR_NAMEI - namei record
 */
#define KTR_NAMEI	3
	/* record contains pathname */

/*
 * KTR_GENIO - trace generic process i/o
 */
#define KTR_GENIO	4
struct ktr_genio {
	int	ktr_fd;
	enum	uio_rw ktr_rw;
	/*
	 * followed by data successfully read/written
	 */
};

/*
 * KTR_PSIG - trace processed signal
 */
#define	KTR_PSIG	5
struct ktr_psig {
	int	signo;
	sig_t	action;
	int	code;
	sigset_t mask;
};

/*
 * KTR_CSW - trace context switches
 */
#define KTR_CSW		6
struct ktr_csw {
	int	out;	/* 1 if switch out, 0 if switch in */
	int	user;	/* 1 if usermode (ivcsw), 0 if kernel (vcsw) */
};

/*
 * KTR_USER - data coming from userland
 */
#define KTR_USER_MAXLEN	2048	/* maximum length of passed data */
#define KTR_USER	7

/*
 * KTR_STRUCT - misc. structs
 */
#define KTR_STRUCT	8
struct sockaddr;
struct stat;

/*
 * KTR_DROP - If this bit is set in ktr_type, then at least one event
 * between the previous record and this record was dropped.
 */
#define	KTR_DROP	0x8000

/*
 * kernel trace points (in p_traceflag)
 */
#define KTRFAC_MASK	0x00ffffff
#define KTRFAC_SYSCALL	(1<<KTR_SYSCALL)
#define KTRFAC_SYSRET	(1<<KTR_SYSRET)
#define KTRFAC_NAMEI	(1<<KTR_NAMEI)
#define KTRFAC_GENIO	(1<<KTR_GENIO)
#define	KTRFAC_PSIG	(1<<KTR_PSIG)
#define KTRFAC_CSW	(1<<KTR_CSW)
#define KTRFAC_USER	(1<<KTR_USER)
#define KTRFAC_STRUCT	(1<<KTR_STRUCT)
/*
 * trace flags (also in p_traceflags)
 */
#define KTRFAC_ROOT	0x80000000	/* root set this trace */
#define KTRFAC_INHERIT	0x40000000	/* pass trace flags to children */
#define	KTRFAC_DROP	0x20000000	/* last event was dropped */

#ifdef	_KERNEL
extern struct mtx ktrace_mtx;

void	ktrnamei(char *);
void	ktrcsw(int, int);
void	ktrpsig(int, sig_t, sigset_t *, int);
void	ktrgenio(int, enum uio_rw, struct uio *, int);
void	ktrsyscall(int, int narg, register_t args[]);
void	ktrsysret(int, int, register_t);
void	ktrprocexit(struct thread *);
void	ktruserret(struct thread *);
void	ktrstruct(const char *, size_t, void *, size_t);
#define ktrsockaddr(s) \
	ktrstruct("sockaddr", 8, (s), ((struct sockaddr *)(s))->sa_len)
#define ktrstat(s) \
	ktrstruct("stat", 4, (s), sizeof(struct stat))

#else

#include <sys/cdefs.h>

__BEGIN_DECLS
int	ktrace(const char *, int, int, pid_t);
int	utrace(const void *, size_t);
__END_DECLS

#endif

#endif
