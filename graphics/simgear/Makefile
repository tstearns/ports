# $OpenBSD: Makefile,v 1.15 2017/12/26 19:19:15 rsadowski Exp $

COMMENT =		library set for simulations, games and visualizations

DISTNAME =		simgear-2016.3.1
REVISION =		2

SHARED_LIBS +=  SimGearCore               4.0 # 2.10
SHARED_LIBS +=  SimGearScene              4.0 # 2.10

CATEGORIES =		graphics

MAINTAINER =		Pascal Stumpf <pascal@stumpf.co>

HOMEPAGE =		http://www.flightgear.org

# LGPLv2
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=flightgear/}
EXTRACT_SUFX =		.tar.bz2

WANTLIB += GL GLU OpenThreads curl expat m openal osg osgDB osgGA osgParticle
WANTLIB += osgSim osgText osgUtil osgViewer pthread z ${COMPILER_LIBCXX}

MODULES =		devel/cmake
COMPILER =		base-clang ports-gcc
BUILD_DEPENDS =		devel/boost
LIB_DEPENDS =		graphics/openscenegraph \
			audio/openal

CONFIGURE_ARGS +=	-DSYSTEM_EXPAT=ON

CFLAGS +=		-I${X11BASE}/include -pthread
CXXFLAGS +=		-I${X11BASE}/include -pthread

NO_TEST =		Yes

.include <bsd.port.mk>
