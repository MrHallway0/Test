# $FreeBSD: stable/11/cddl/usr.sbin/zfsd/tests/Makefile 305909 2016-09-18 02:41:50Z ngie $

.include "${.CURDIR}/../Makefile.common"
.PATH:	${.CURDIR:H}

PLAIN_TESTS_CXX=	zfsd_unittest
SRCS.zfsd_unittest:=		${SRCS:Nzfsd_main.cc}
SRCS.zfsd_unittest+=		libmocks.c zfsd_unittest.cc
SRCS=

# Use #include <zfsd/xxx.h> in test programs.
INCFLAGS+=	-I${.CURDIR:H:H}

.if defined(DESTDIR)
INCFLAGS+=	-I${DESTDIR}/usr/include
LIBRARY_PATH=	${DESTDIR}/lib:${DESTDIR}/usr/lib
LDFLAGS.zfsd_unittest+=	-L${DESTDIR}/lib -L${DESTDIR}/usr/lib
.elif defined(WORLDTMP)
INCFLAGS+=	-I${WORLDTMP}/usr/include
LIBRARY_PATH=	${WORLDTMP}/lib:${WORLDTMP}/usr/lib
LDFLAGS.zfsd_unittest+=	-L${WORLDTMP}/lib -L${WORLDTMP}/usr/lib
.else
LIBRARY_PATH=
.endif

# Googletest options
INCFLAGS+=	-I${LOCALBASE}/include -D_THREAD_SAFE -pthread
LDFLAGS.zfsd_unittest+=	-L${LOCALBASE}/lib -D_THREAD_SAFE -pthread
LDADD.zfsd_unittest+=		${LOCALBASE}/lib/libgtest.a

# GoogleMock options
LDADD.zfsd_unittest+= ${LOCALBASE}/lib/libgmock.a ${LOCALBASE}/lib/libgmock_main.a

# Googlemock fails if we don't have this line
# https://groups.google.com/forum/#!msg/googletestframework/h8ixEPCFm0o/amwfu4xGJb0J
CFLAGS.zfsd_unittest+= -DGTEST_HAS_PTHREAD

.include <bsd.test.mk>
