# $OpenBSD: Makefile,v 1.13 2018/06/29 22:16:12 espie Exp $

COMMENT =		tile map editor

V =			0.9.1
DISTNAME =		tiled-qt-${V}
PKGNAME =		tiled-${V}
REVISION =		5

SHARED_LIBS +=		tiled                     0.0 # 1.0

CATEGORIES =		editors games

HOMEPAGE =		http://www.mapeditor.org/

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += GL ICE QtGui QtOpenGL SM X11 Xext Xi Xinerama Xrender
WANTLIB += c fontconfig freetype m pthread ${COMPILER_LIBCXX} z

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=tiled/}

RUN_DEPENDS =		devel/desktop-file-utils \
			x11/gtk+3,-guic
MODULES =		devel/qmake x11/qt4

# XXX qmake picks up Cocoa/Cocoa.h even though it's apparently unused
DPB_PROPERTIES =	nojunk

do-test:
	cd ${WRKSRC}/tests/staggeredrenderer && ./staggeredrenderer && \
	cd ${WRKSRC}/tests/mapreader && ./mapreader

.include <bsd.port.mk>
