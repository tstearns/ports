# $OpenBSD: Makefile,v 1.7 2018/05/17 09:53:02 espie Exp $

COMMENT =	library of general purpose APIs
BROKEN-hppa =	missing atomic ops

SO_VERSION =	0.0
SHARED_LIBS +=	owfat ${SO_VERSION}

DISTNAME =	libowfat-0.31
REVISION =	1
CATEGORIES =	devel

MAINTAINER =	Jan Klemkow <j.klemkow@wemelug.de>

HOMEPAGE =	http://www.fefe.de/libowfat/
MASTER_SITES =	http://www.fefe.de/libowfat/
EXTRACT_SUFX =	.tar.xz
USE_GMAKE =	Yes
MAKE_FILE =	GNUmakefile

MAKE_FLAGS =	CC="${CC}" COPTFLAGS="-fpic ${CFLAGS}" \
		SO_VERSION="${SO_VERSION}"
FAKE_FLAGS =	prefix=${PREFIX} \
		INCLUDEDIR=${PREFIX}/include/lowfat \
		MAN3DIR=${PREFIX}/share/lowfat/man/man3

# GPLv2 only
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	c pthread
NO_TEST =	Yes

.include <bsd.port.mk>
