## $NetBSD: Makefile.am,v 1.2 2009/05/26 05:42:25 lukem Exp $

AM_CFLAGS		= $(WARNCFLAGS)

bin_PROGRAMS		= netpgp

netpgp_SOURCES		= netpgp.c

netpgp_CPPFLAGS		= -I$(top_srcdir)/include

netpgp_LDADD		= ../lib/libnetpgp.la

man1_MANS		= netpgp.1

dist_man_MANS		= netpgp.1
