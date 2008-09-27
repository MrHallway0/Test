# $FreeBSD: src/share/skel/dot.profile,v 1.21 2002/07/07 00:00:54 mp Exp $
# $MidnightBSD: src/share/skel/dot.profile,v 1.6 2007/10/13 21:25:46 laffer1 Exp $
#
# .profile - Bourne Shell startup script for login shells
#
# see also sh(1), ksh(1), environ(7).
#

# remove /usr/games if you want
PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/games:/usr/local/sbin:/usr/local/bin:$HOME/bin; export PATH

# A righteous umask
umask 22

# set a few alias
alias h="fc -l"
alias j="jobs -l"
alias la="ls -a"
alias lf="ls -FA"
alias ll="ls -lA"

# Setting TERM is normally done through /etc/ttys.  Do only override
# if you're sure that you'll never log in via telnet or xterm or a
# serial line.
# Use cons25l1 for iso-* fonts
# TERM=cons25; 	export TERM

BLOCKSIZE=K;	export BLOCKSIZE
EDITOR=vi;   	export EDITOR
PAGER=more;  	export PAGER
VISUAL=vi;	export VISUAL

# set ENV to a file invoked each time sh is started for interactive use.
if [ $SHELL = "/bin/ksh" ]; then
	ENV=$HOME/.kshrc; export ENV
elif [ $SHELL = "/bin/sh" ]; then
	ENV=$HOME/.shrc; export ENV
fi

# Source GNUstep so we can use openapp and friends.
if [ -x /usr/local/GNUstep/System/Makefiles/GNUstep.sh ]; then
	. /usr/local/GNUstep/System/Makefiles/GNUstep.sh
fi
if [ -x /usr/local/GNUstep/System/Library/Makefiles/GNUstep.sh ]; then
	. /usr/local/GNUstep/System/Library/Makefiles/GNUstep.sh
fi

[ -x /usr/games/fortune ] && /usr/games/fortune freebsd-tips
