# $OpenBSD: Makefile,v 1.14 2018/01/09 21:02:36 schwarze Exp $

ONLY_FOR_ARCHS =	amd64 i386

COMMENT =		role playing game

V =			0.5.8
DISTNAME =		sumwars-${V}-src
PKGNAME =		sumwars-${V}
REVISION =		5

SUBST_VARS +=		V

CATEGORIES =		games

HOMEPAGE =		http://sumwars.org/wiki/Main_Page

MAINTAINER =		Pascal Stumpf <pascal@stumpf.co>

# GPLv3+ / CC-by-sa 3.0 for data
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += CEGUIBase-0 CEGUIOgreRenderer-0 OIS OgreMain OgreRTShaderSystem
WANTLIB += OgreTerrain X11 Xrandr alut boost_chrono-mt boost_date_time-mt
WANTLIB += boost_filesystem-mt boost_system-mt boost_thread-mt
WANTLIB += c enet iconv intl m ogg openal physfs pthread tinyxml vorbis
WANTLIB += vorbisfile boost_atomic-mt ${MODLUA_WANTLIB} ${COMPILER_LIBCXX}

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=sumwars/}
EXTRACT_SUFX =		.tar.bz2

MODULES =		devel/cmake \
			lang/lua
MODLUA_VERSION =	5.2

COMPILER =		base-clang ports-gcc
LIB_DEPENDS =		x11/cegui \
			audio/freealut \
			audio/libvorbis \
			devel/gettext \
			devel/physfs \
			devel/ois \
			net/enet

CONFIGURE_ARGS += \
	-DCMAKE_EXE_LINKER_FLAGS="-L${LOCALBASE}/lib -liconv -lintl" \
	-DSUMWARS_NO_ENET=ON \
	-DSUMWARS_NO_TINYXML=ON

NO_TEST =		Yes

WRKDIST =		${WRKDIR}/sumwars-${V}

CXXFLAGS +=		-pthread

.include <bsd.port.mk>
