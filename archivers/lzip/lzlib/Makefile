# $OpenBSD: Makefile,v 1.9 2018/02/14 16:43:32 juanfra Exp $

COMMENT =		lzip compression library

DISTNAME =		lzlib-1.10

SHARED_LIBS +=		lz	1.3 # 1.9

HOMEPAGE =		http://lzip.nongnu.org/lzlib.html
MASTER_SITES =		${MASTER_SITE_SAVANNAH:=lzip/lzlib/}

# 2-clause BSD
PERMIT_PACKAGE_CDROM =	Yes

MAKE_ENV +=		LIBlz_VERSION=${LIBlz_VERSION}

USE_GMAKE =		Yes

CONFIGURE_ARGS +=	--disable-static \
			--disable-ldconfig

# The Makefile tries to strip a shared lib with the install-strip target.
INSTALL_TARGET =	install

.include <bsd.port.mk>
