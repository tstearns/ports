# $OpenBSD: Makefile,v 1.35 2018/02/16 14:46:50 ajacoutot Exp $

COMMENT=	Google VP8/VP9 video codec

# XXX newer version requires __atomic builtins
DISTNAME=	libvpx-1.6.1
CATEGORIES=	multimedia
MASTER_SITES=	https://storage.googleapis.com/downloads.webmproject.org/releases/webm/
EXTRACT_SUFX=	.tar.bz2
EPOCH=		0

SHARED_LIBS=	vpx	10.0

HOMEPAGE=	https://www.webmproject.org/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	c m pthread ${LIBCXX}

COMPILER =	base-clang base-gcc

.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	devel/yasm
.endif

MAKE_FLAGS=	LIBVPX_VERSION=${LIBvpx_VERSION} verbose=yes

USE_GMAKE=	Yes
CONFIGURE_STYLE= simple
CONFIGURE_ARGS+=--enable-shared \
		--prefix=${PREFIX} \
		--disable-optimizations \
		--disable-unit-tests

NO_TEST=	Yes

ALL_TARGET=

post-install:
	@chown ${BINOWN}:${BINGRP} ${PREFIX}/bin/*
	@chmod ${BINMODE} ${PREFIX}/bin/*
	@chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/include/vpx/*.h
	@chmod ${SHAREMODE} ${PREFIX}/include/vpx/*.h
	@chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lib*
	@chmod ${SHAREMODE} ${PREFIX}/lib/lib*
	@chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/pkgconfig/vpx.pc
	@chmod ${SHAREMODE} ${PREFIX}/lib/pkgconfig/vpx.pc

.include <bsd.port.mk>
