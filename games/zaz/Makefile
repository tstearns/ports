# $OpenBSD: Makefile,v 1.11 2018/07/10 13:50:52 naddy Exp $

COMMENT =	Zuma-like arcade game
DISTNAME =	zaz-1.0.0
REVISION =	4
CATEGORIES =	games

HOMEPAGE =	http://zaz.sourceforge.net/

MAINTAINER =	Matthias Kilian <kili@openbsd.org>

# GPLv3+
PERMIT_PACKAGE_CDROM =		Yes

WANTLIB =	GL SDL SDL_image c freetype ftgl iconv intl m ogg pthread \
		${COMPILER_LIBCXX} theoradec theoraenc \
		vorbis vorbisenc vorbisfile z

EXTRACT_SUFX =	.tar.bz2
MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=zaz/}

LIB_DEPENDS =	audio/libvorbis \
		devel/sdl-image \
		devel/sdl-mixer \
		devel/sdl-net \
		devel/sdl-ttf \
		graphics/ftgl \
		multimedia/libtheora

RUN_DEPENDS =	devel/desktop-file-utils

AUTOCONF_VERSION =	2.65
CONFIGURE_STYLE =	autoconf
CONFIGURE_ENV =		CFLAGS="$(CFLAGS) -I${X11BASE}/include \
				-I$(X11BASE)/include/freetype2 -pthread" \
			CXXFLAGS="$(CXXFLAGS) -I${X11BASE}/include \
				-I$(X11BASE)/include/freetype2 -pthread" \
			LDFLAGS="-pthread -L${X11BASE}/lib -L${LOCALBASE}/lib"

.include <bsd.port.mk>
