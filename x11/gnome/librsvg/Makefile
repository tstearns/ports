# $OpenBSD: Makefile,v 1.127 2018/07/12 12:23:45 ajacoutot Exp $

COMMENT=		SAX-based render library for SVG files

GNOME_PROJECT=		librsvg
STABLE_VERSION=		2.42.5
OLD_VERSION=		2.40.20
DISTFILES=		librsvg-${STABLE_VERSION}${EXTRACT_SUFX} \
			librsvg-${OLD_VERSION}${EXTRACT_SUFX}

REVISION=		0

# sync with lang/rust ONLY_FOR_ARCHS
.if ${MACHINE_ARCH} == "aarch64" || ${MACHINE_ARCH} == "amd64" || \
	${MACHINE_ARCH} == "i386"
SHARED_LIBS +=  rsvg-2               39.0     # 44.5
GNOME_VERSION=		${STABLE_VERSION}
BUILD_DEPENDS=		lang/rust
PKG_ARGS=		-Dold=0 -Dstable=1
.else
SHARED_LIBS +=  rsvg-2               38.2     # 42.20
GNOME_VERSION=		${OLD_VERSION}
PATCH_LIST=		old-patch-*
PKG_ARGS=		-Dold=1 -Dstable=0
.endif

CATEGORIES=		devel graphics

# GPLv2/LGPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 Xext Xrender c cairo croco-0.6 expat ffi fontconfig
WANTLIB += freetype fribidi gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 graphite2 gthread-2.0 harfbuzz iconv
WANTLIB += intl lzma m pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre
WANTLIB += pixman-1 png pthread xcb xcb-render xcb-shm xml2 z

MODULES=		x11/gnome

MODGNOME_TOOLS=		gobject-introspection vala

LIB_DEPENDS=		devel/pango \
			graphics/gdk-pixbuf2 \
			textproc/libxml \
			www/libcroco

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--disable-tools

# error: -Bsymbolic-functions requested but not supported by ld
CONFIGURE_ARGS +=	--disable-Bsymbolic

post-install:
	rm ${PREFIX}/lib/gdk-pixbuf-2.0/2.10.0/loaders/*.{a,la}

.include <bsd.port.mk>
