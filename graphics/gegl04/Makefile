# $OpenBSD: Makefile,v 1.3 2018/07/12 14:34:26 ajacoutot Exp $

COMMENT=		graph based image processing framework (API version 0.4)

V=			0.4.4
DISTNAME=		gegl-${V}
PKGNAME=		gegl04-${V}
EXTRACT_SUFX=		.tar.bz2

SHARED_LIBS +=  gegl-0.4                  0.0 # 404.0

API_VERSION=		${V:R}
SUBST_VARS=		API_VERSION

CATEGORIES=		graphics devel

HOMEPAGE=		http://gegl.org/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv3/LGPLv3
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ${COMPILER_LIBCXX} X11 Xext Xrender babl-0.1 cairo
WANTLIB += croco-0.6 expat ffi fontconfig freetype fribidi gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 graphite2
WANTLIB += gthread-2.0 harfbuzz iconv intl jasper jpeg json-glib-1.0
WANTLIB += lcms2 lzma m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 png raw rsvg-2 tiff webp xcb xcb-render
WANTLIB += xcb-shm xml2 z

MASTER_SITES=		http://download.gimp.org/pub/gegl/${API_VERSION}/

MODULES=		x11/gnome

MODGNOME_TOOLS=		vala gobject-introspection

USE_GMAKE=		Yes

BUILD_DEPENDS=		graphics/libgexiv2

LIB_DEPENDS=		devel/json-glib \
			graphics/babl \
			graphics/lcms2 \
			graphics/libraw \
			graphics/libwebp \
			x11/gnome/librsvg

CONFIGURE_STYLE=	gnu

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			ac_cv_header_execinfo_h="no" \
			ac_cv_path_ASCIIDOC="no" \
			ac_cv_path_W3M="no" \
			ac_cv_path_ENSCRIPT="no" \
			ac_cv_prog_RUBY="" \
			ac_cv_path_DOT="no"

CONFIGURE_ARGS=		--without-lensfun \
			--without-openexr \
			--without-sdl \
			--without-graphviz \
			--without-libavformat \
			--without-libv4l \
			--without-libv4l2 \
			--without-libspiro \
			--without-lua \
			--without-mrg \
			--without-umfpack

# does fishy things (git(1), grabbing the X display...)
CONFIGURE_ARGS +=	--disable-docs

# be safe until proven stable
CONFIGURE_ARGS +=	--enable-mmx \
			--disable-sse

post-install:
	rm ${PREFIX}/lib/gegl-${API_VERSION}/*.{a,la} \
		${PREFIX}/lib/libgegl-{npd,sc}-${API_VERSION}.{a,la}
# fix conflict with graphics/gegl; we currently only care about the libraries
	rm -rf ${PREFIX}/bin/

.include <bsd.port.mk>
