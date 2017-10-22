#!/bin/sh
# $FreeBSD: stable/9/tools/regression/zfs/zpool/replace/spare.t 185029 2008-11-17 20:49:29Z pjd $

dir=`dirname $0`
. ${dir}/../../misc.sh

echo "1..6"

disks_create 4
names_create 1

expect_ok ${ZPOOL} create ${name0} ${disk0} spare ${disk1}
exp=`(
  echo "  pool: ${name0}"
  echo " state: ONLINE"
  echo " scrub: none requested"
  echo "config:"
  echo "	NAME          STATE   READ WRITE CKSUM"
  echo "	${name0}      ONLINE     0     0     0"
  echo "	  ${disk0}    ONLINE     0     0     0"
  echo "	spares"
  echo "	    ${disk1}  AVAIL"
  echo "errors: No known data errors"
)`
expect "${exp}" ${ZPOOL} status ${name0}
expect_fl ${ZPOOL} replace ${name0} ${disk1} ${disk2}
exp=`(
  echo "  pool: ${name0}"
  echo " state: ONLINE"
  echo " scrub: none requested"
  echo "config:"
  echo "	NAME          STATE   READ WRITE CKSUM"
  echo "	${name0}      ONLINE     0     0     0"
  echo "	  ${disk0}    ONLINE     0     0     0"
  echo "	spares"
  echo "	    ${disk1}  AVAIL"
  echo "errors: No known data errors"
)`
expect "${exp}" ${ZPOOL} status ${name0}
expect_ok ${ZPOOL} destroy ${name0}
expect_fl ${ZPOOL} status -x ${name0}

disks_destroy
