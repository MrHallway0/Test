/*-
 * Copyright (c) 2010 The FreeBSD Foundation
 * Copyright (c) 2008 John Birrell (jb@freebsd.org)
 * All rights reserved.
 * 
 * Portions of this software were developed by Rui Paulo under sponsorship
 * from the FreeBSD Foundation.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: stable/9/lib/libproc/proc_util.c 212831 2010-09-18 23:38:21Z rpaulo $
 */

#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <err.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "_libproc.h"

int
proc_clearflags(struct proc_handle *phdl, int mask)
{

	if (phdl == NULL)
		return (EINVAL);

	phdl->flags &= ~mask;

	return (0);
}

/*
 * NB: we return -1 as the Solaris libproc Psetrun() function.
 */
int
proc_continue(struct proc_handle *phdl)
{

	if (phdl == NULL)
		return (-1);

	if (ptrace(PT_CONTINUE, phdl->pid, (caddr_t)(uintptr_t) 1, 0) != 0)
		return (-1);

	phdl->status = PS_RUN;

	return (0);
}

int
proc_detach(struct proc_handle *phdl, int reason)
{
	int status;

	if (phdl == NULL)
		return (EINVAL);
	if (reason == PRELEASE_KILL) {
		kill(phdl->pid, SIGKILL);
		return (0);
	}
	if (ptrace(PT_DETACH, phdl->pid, 0, 0) != 0 && errno == ESRCH)
		return (0);
	if (errno == EBUSY) {
		kill(phdl->pid, SIGSTOP);
		waitpid(phdl->pid, &status, WUNTRACED);
		ptrace(PT_DETACH, phdl->pid, 0, 0);
		kill(phdl->pid, SIGCONT);
		return (0);
	}

	return (0);
}

int
proc_getflags(struct proc_handle *phdl)
{

	if (phdl == NULL)
		return (-1);

	return(phdl->flags);
}

int
proc_setflags(struct proc_handle *phdl, int mask)
{

	if (phdl == NULL)
		return (EINVAL);

	phdl->flags |= mask;

	return (0);
}

int
proc_state(struct proc_handle *phdl)
{

	if (phdl == NULL)
		return (-1);

	return (phdl->status);
}

pid_t
proc_getpid(struct proc_handle *phdl)
{

	if (phdl == NULL)
		return (-1);

	return (phdl->pid);
}

int
proc_wstatus(struct proc_handle *phdl)
{
	int status;

	if (phdl == NULL)
		return (-1);
	if (waitpid(phdl->pid, &status, WUNTRACED) < 0) {
		if (errno != EINTR)
			warn("waitpid");
		return (-1);
	}
	if (WIFSTOPPED(status))
		phdl->status = PS_STOP;
	if (WIFEXITED(status) || WIFSIGNALED(status))
		phdl->status = PS_UNDEAD;
	phdl->wstat = status;

	return (phdl->status);
}

int
proc_getwstat(struct proc_handle *phdl)
{

	if (phdl == NULL)
		return (-1);

	return (phdl->wstat);
}

char *
proc_signame(int sig, char *name, size_t namesz)
{

	strlcpy(name, strsignal(sig), namesz);

	return (name);
}

int
proc_read(struct proc_handle *phdl, void *buf, size_t size, size_t addr)
{
	struct ptrace_io_desc piod;

	if (phdl == NULL)
		return (-1);
	piod.piod_op = PIOD_READ_D;
	piod.piod_len = size;
	piod.piod_addr = (void *)buf;
	piod.piod_offs = (void *)addr;

	if (ptrace(PT_IO, phdl->pid, (caddr_t)&piod, 0) < 0)
		return (-1);
	return (piod.piod_len);
}

const lwpstatus_t *
proc_getlwpstatus(struct proc_handle *phdl)
{
	struct ptrace_lwpinfo lwpinfo;
	lwpstatus_t *psp = &phdl->lwps;
	siginfo_t *siginfo;

	if (phdl == NULL)
		return (NULL);
	if (ptrace(PT_LWPINFO, phdl->pid, (caddr_t)&lwpinfo,
	    sizeof(lwpinfo)) < 0)
		return (NULL);
	siginfo = &lwpinfo.pl_siginfo;
	if (lwpinfo.pl_event == PL_EVENT_SIGNAL &&
	    (lwpinfo.pl_flags & PL_FLAG_SI) &&
	    siginfo->si_signo == SIGTRAP &&
	    (siginfo->si_code == TRAP_BRKPT ||
	    siginfo->si_code == TRAP_TRACE)) {
		psp->pr_why = PR_FAULTED;
		psp->pr_what = FLTBPT;
	} else if (lwpinfo.pl_flags & PL_FLAG_SCE) {
		psp->pr_why = PR_SYSENTRY;
	} else if (lwpinfo.pl_flags & PL_FLAG_SCX) {
		psp->pr_why = PR_SYSEXIT;
	}

	return (psp);
}
