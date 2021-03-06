# $OpenBSD: Makefile,v 1.64 2018/05/14 09:34:43 ajacoutot Exp $

PORTROACH=		limit:^0\.2

COMMENT-main=		graph based image processing framework
COMMENT-plugins=	gegl plugins

API_VERSION=		0.2
SUBST_VARS=		API_VERSION

V=			${API_VERSION}.2
DISTNAME=		gegl-${V}
EXTRACT_SUFX=		.tar.bz2

CATEGORIES=		graphics devel

PKGNAME-main=		gegl-${V}
PKGNAME-plugins=	gegl-plugins-${V}

SHARED_LIBS +=  gegl-0.2             0.0      # 201.1
SHARED_LIBS +=  gegl-sc-0.2          0.0      # unknown

HOMEPAGE=		http://gegl.org/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv3/LGPLv3
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=		http://download.gimp.org/pub/gegl/${V:R}/

MULTI_PACKAGES=		-main -plugins

WANTLIB += ffi gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 iconv intl m pcre z

WANTLIB-main += ${WANTLIB}
WANTLIB-main += X11 Xext Xrender babl-0.1 c cairo croco-0.6 expat fontconfig
WANTLIB-main += freetype fribidi gdk_pixbuf-2.0 graphite2 harfbuzz
WANTLIB-main += jasper jpeg lzma pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB-main += pixman-1 png pthread rsvg-2 xcb xcb-render xcb-shm
WANTLIB-main += xml2

WANTLIB-plugins += ${WANTLIB}
WANTLIB-plugins += ${COMPILER_LIBCXX} Half Iex IexMath IlmImf IlmThread
WANTLIB-plugins += Imath avcodec avformat avutil babl-0.1 bz2 crypto gegl-0.2
WANTLIB-plugins += gsm mp3lame ogg opus speex ssl swresample vorbis vorbisenc
WANTLIB-plugins += vpx x264 x265 xvidcore

MODULES=		textproc/intltool

USE_GMAKE=		Yes

BUILD_DEPENDS=		graphics/exiv2

LIB_DEPENDS-main= 	x11/gnome/librsvg \
			graphics/babl

LIB_DEPENDS-plugins= 	${BUILD_PKGPATH},-main \
			graphics/ilmbase \
			graphics/openexr \
			graphics/ffmpeg

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			ac_cv_header_execinfo_h="no" \
			ac_cv_path_ASCIIDOC="no" \
			ac_cv_path_W3M="no" \
			ac_cv_path_ENSCRIPT="no" \
			ac_cv_prog_RUBY="" \
			ac_cv_path_DOT="no"

CONFIGURE_ARGS=		--disable-docs \
			--without-umfpack \
			--without-sdl \
			--without-lua \
			--without-libopenraw \
			--without-graphviz \
			--without-libv4l \
			--without-libspiro

# be safe until proven stable
CONFIGURE_ARGS +=	--enable-mmx \
			--disable-sse

# https://bugzilla.gnome.org/show_bug.cgi?id=673580
CONFIGURE_ARGS +=	--without-vala \
			--disable-introspection

post-install:
	rm ${PREFIX}/lib/gegl-0.2/*.{a,la}

.include <bsd.port.mk>
