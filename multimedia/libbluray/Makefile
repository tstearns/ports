# $OpenBSD: Makefile,v 1.13 2017/10/23 17:10:52 sthen Exp $

COMMENT =		library supporting Blu-ray playback

V =			1.0.0
DISTNAME =		libbluray-${V}
CATEGORIES =		multimedia
REVISION =		0

HOMEPAGE =		http://www.videolan.org/developers/libbluray.html

MASTER_SITES =		https://download.videolan.org/pub/videolan/libbluray/${V}/ \
			ftp://ftp.videolan.org/pub/videolan/libbluray/${V}/
EXTRACT_SUFX =		.tar.bz2

# LGPL v2.1
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB +=		c expat fontconfig freetype iconv lzma m pthread
WANTLIB +=		xml2 z

SHARED_LIBS +=		bluray		3.0	# 11.0

LIB_DEPENDS =		converters/libiconv \
			textproc/libxml
BUILD_DEPENDS =		devel/bison

SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	gnu
YACC =			${LOCALBASE}/bin/bison -y
CONFIGURE_ARGS +=	--disable-bdjava \
			--disable-doxygen-doc \
			--disable-optimizations

.include <bsd.port.mk>
