# $OpenBSD: Makefile,v 1.26 2018/06/29 22:16:16 espie Exp $

COMMENT =	simple and fast image viewer for X11

DISTNAME =	gpicview-0.2.5
REVISION =	2

CATEGORIES =	graphics x11

HOMEPAGE =	http://lxde.sourceforge.net/gpicview/

WANTLIB =	X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama \
		Xrandr Xrender atk-1.0 c cairo expat ffi fontconfig freetype \
		gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 \
		gobject-2.0 graphite2 gthread-2.0 gtk-x11-2.0 harfbuzz \
		iconv intl jpeg m pango-1.0 pangocairo-1.0 pangoft2-1.0 \
		pcre pixman-1 png pthread xcb xcb-render \
		xcb-shm z

# GPLv2+
PERMIT_PACKAGE_CDROM =		Yes

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX =	.tar.xz

MODULES =	textproc/intltool

LIB_DEPENDS =	x11/gtk+2
RUN_DEPENDS =	devel/desktop-file-utils \
		x11/gtk+3,-guic

USE_GMAKE =	yes

CONFIGURE_STYLE = gnu

CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		lt_cv_path_SED=/usr/bin/sed

.include <bsd.port.mk>
