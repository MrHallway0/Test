/* $FreeBSD: src/sys/contrib/pf/net/if_pflog.h,v 1.9 2007/07/03 12:16:07 mlaier Exp $ */
/* $OpenBSD: if_pflog.h,v 1.14 2006/10/25 11:27:01 henning Exp $ */
/*
 * Copyright 2001 Niels Provos <provos@citi.umich.edu>
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _NET_IF_PFLOG_H_
#define _NET_IF_PFLOG_H_

#define	PFLOGIFS_MAX	16

#ifdef _KERNEL
struct pflog_softc {
#if defined(__FreeBSD__) || defined(__MidnightBSD__)
	struct ifnet		*sc_ifp;	/* the interface pointer */
#else
	struct ifnet		sc_if;		/* the interface */
#endif
	int			sc_unit;
	LIST_ENTRY(pflog_softc)	sc_list;
};
#endif /* _KERNEL */

#define PFLOG_RULESET_NAME_SIZE	16

struct pfloghdr {
	u_int8_t	length;
	sa_family_t	af;
	u_int8_t	action;
	u_int8_t	reason;
	char		ifname[IFNAMSIZ];
	char		ruleset[PFLOG_RULESET_NAME_SIZE];
	u_int32_t	rulenr;
	u_int32_t	subrulenr;
	uid_t		uid;
	pid_t		pid;
	uid_t		rule_uid;
	pid_t		rule_pid;
	u_int8_t	dir;
	u_int8_t	pad[3];
};

#define PFLOG_HDRLEN		sizeof(struct pfloghdr)
/* minus pad, also used as a signature */
#define PFLOG_REAL_HDRLEN	offsetof(struct pfloghdr, pad)

/* XXX remove later when old format logs are no longer needed */
struct old_pfloghdr {
	u_int32_t af;
	char ifname[IFNAMSIZ];
	short rnr;
	u_short reason;
	u_short action;
	u_short dir;
};
#define OLD_PFLOG_HDRLEN	sizeof(struct old_pfloghdr)

#ifdef _KERNEL

#if defined(__FreeBSD__) || defined(__MidnightBSD__)
struct pf_rule;
struct pf_ruleset;
struct pfi_kif;
struct pf_pdesc;

typedef int pflog_packet_t(struct pfi_kif *, struct mbuf *, sa_family_t,
    u_int8_t, u_int8_t, struct pf_rule *, struct pf_rule *,
    struct pf_ruleset *, struct pf_pdesc *);
extern pflog_packet_t *pflog_packet_ptr;
#define	PFLOG_PACKET(i,x,a,b,c,d,e,f,g,h) do {	\
	if (pflog_packet_ptr != NULL)		\
	pflog_packet_ptr(i,a,b,c,d,e,f,g,h);	\
} while (0)
#else /* ! __FreeBSD__ */
#if NPFLOG > 0
#define	PFLOG_PACKET(i,x,a,b,c,d,e,f,g,h) pflog_packet(i,a,b,c,d,e,f,g,h)
#else
#define	PFLOG_PACKET(i,x,a,b,c,d,e,f,g,h) ((void)0)
#endif /* NPFLOG > 0 */
#endif /* __FreeBSD__ */
#endif /* _KERNEL */
#endif /* _NET_IF_PFLOG_H_ */
