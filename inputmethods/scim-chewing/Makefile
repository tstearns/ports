# $OpenBSD: Makefile,v 1.25 2017/11/21 00:13:01 naddy Exp $

COMMENT=	scim input method module for chewing

GH_ACCOUNT=	chewing
GH_PROJECT=	scim-chewing
GH_TAGNAME=	v0.5.1
REVISION=	0

CATEGORIES=	inputmethods chinese

HOMEPAGE=	http://chewing.im/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ${COMPILER_LIBCXX} X11 Xcomposite Xcursor Xdamage Xext
WANTLIB += Xfixes Xi Xinerama Xrandr Xrender atk-1.0 cairo chewing
WANTLIB += expat ffi fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 graphite2 gthread-2.0
WANTLIB += gtk-x11-2.0 harfbuzz iconv intl m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png scim-1.0 scim-gtkutils-1.0
WANTLIB += scim-x11utils-1.0 sqlite3 xcb xcb-render xcb-shm z

MODULES=	textproc/intltool
BUILD_DEPENDS=	${MODGNU_AUTOCONF_DEPENDS} \
		${MODGNU_AUTOMAKE_DEPENDS} \
		devel/libtool
LIB_DEPENDS=	x11/gtk+2 \
		chinese/libchewing \
		inputmethods/scim

LIBTOOL_FLAGS=	--tag=disable-static

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS= --disable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=	1.15

post-patch:
	@cd ${WRKSRC} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} ./autogen.sh

.include <bsd.port.mk>
