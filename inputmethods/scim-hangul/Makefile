# $OpenBSD: Makefile,v 1.24 2017/11/21 00:13:01 naddy Exp $

COMMENT=	scim input method module for hangul

DISTNAME=	scim-hangul-0.3.2
REVISION=	12

CATEGORIES=	inputmethods korean

HOMEPAGE=	https://sourceforge.net/projects/scim/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB+= GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes Xi
WANTLIB+= Xinerama Xrandr Xrender Xxf86vm atk-1.0 cairo drm expat ffi
WANTLIB+= fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0
WANTLIB+= glib-2.0 gmodule-2.0 gobject-2.0 graphite2 gthread-2.0
WANTLIB+= gtk-x11-2.0 hangul harfbuzz iconv intl m pango-1.0 pangocairo-1.0
WANTLIB+= pangoft2-1.0 pcre pixman-1 png pthread scim-1.0
WANTLIB+= scim-gtkutils-1.0 scim-x11utils-1.0 ${COMPILER_LIBCXX} xcb xcb-render
WANTLIB+= xcb-shm z

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

LIB_DEPENDS=	korean/libhangul \
		x11/gtk+2 \
		inputmethods/scim

LIBTOOL_FLAGS=	--tag=disable-static

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--disable-static \
		--disable-skim-support

.include <bsd.port.mk>
