# $OpenBSD: Makefile,v 1.20 2018/05/14 16:35:30 landry Exp $

COMMENT=	opensource implementation of the OFX specification

DISTNAME=	libofx-0.9.13
CATEGORIES=	devel

HOMEPAGE=	http://libofx.sourceforge.net/

MAINTAINER=	Landry Breuil <landry@openbsd.org>

SHARED_LIBS=	ofx 7.0	# .6.0

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libofx/}

WANTLIB=	c iconv intl m pthread ${COMPILER_LIBCXX} osp

LIB_DEPENDS=	textproc/opensp
BUILD_DEPENDS =	devel/help2man


CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lm" \
		CPPFLAGS="-I${LOCALBASE}/include"

CONFIGURE_ARGS=	--without-libcurl \
		--disable-doxygen \
		--disable-dot \
		--disable-gengetopt

post-install:
	@chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/share/doc/libofx/html

.include <bsd.port.mk>
