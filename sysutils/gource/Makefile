# $OpenBSD: Makefile,v 1.18 2018/06/14 08:19:56 gonzalo Exp $

COMMENT =	software version control visualization tool

DISTNAME =	gource-0.49
CATEGORIES =	sysutils graphics
HOMEPAGE =	http://gource.io/

MAINTAINER =	Gonzalo L. R. <gonzalo@openbsd.org>

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =	https://github.com/acaudwell/Gource/releases/download/${DISTNAME}/

CONFIGURE_STYLE =	gnu noman
COMPILER =		base-clang ports-gcc


WANTLIB += GL GLEW GLU SDL2 SDL2_image boost_filesystem boost_system
WANTLIB += c freetype m pcre png pthread z ${COMPILER_LIBCXX}

BUILD_DEPENDS =		graphics/glm
LIB_DEPENDS =           devel/boost \
			devel/pcre \
			devel/sdl2-image \
			graphics/glew

post-install:
	@gzip -d ${PREFIX}/man/man1/gource.1.gz

.include <bsd.port.mk>
