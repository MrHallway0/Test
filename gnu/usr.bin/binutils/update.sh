#! /bin/sh
#
# $FreeBSD: stable/11/gnu/usr.bin/binutils/update.sh 70065 2000-12-15 20:11:28Z obrien $
#
# This script installs the main files generated by the binutils
# "configure" scripts and makefiles.  It can be used for upgrading to
# a new version of binutils.
#
# Don't forget to change the VERSION definition in the top level
# "Makefile.inc0".

gnudir=$(pwd)
contribdir="${gnudir}/../../../contrib/binutils"
platform="`uname -m`"

rm -rf build
mkdir build

echo "binutils elf configuration for $platform"

(cd build
    ${contribdir}/configure $platform-unknown-freebsd || exit
    (cd gas
	echo "Updating as"
	make config.h || exit
	cp config.h ${gnudir}/as/$platform/config.h || exit
	)
    (cd ld
	echo "Updating ld"
	make config.h ldemul-list.h || exit
	cp config.h ${gnudir}/ld || exit
	cp ldemul-list.h ${gnudir}/ld/$platform || exit
	)
    (cd bfd
	echo "Updating libbfd"
	make bfd.h config.h || exit
	cp bfd.h ${gnudir}/libbfd/$platform || exit
	cp config.h ${gnudir}/libbfd/$platform || exit
	)
    (cd binutils
	echo "Updating libbinutils"
	make config.h || exit
	cp config.h ${gnudir}/libbinutils/config.h || exit
	)
    )

rm -rf build
