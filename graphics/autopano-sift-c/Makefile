# $OpenBSD: Makefile,v 1.17 2017/07/26 22:45:23 sthen Exp $

COMMENT =		identify control points from groups of overlapping images

DISTNAME =		autopano-sift-C-2.5.1
REVISION=		3
PKGNAME =		${DISTNAME:L}

CATEGORIES =		graphics

HOMEPAGE =		http://hugin.sourceforge.net/

# GPLv2
PERMIT_PACKAGE_CDROM =	US patent, see README
PERMIT_PACKAGE_FTP =	Yes

WANTLIB += c jpeg m pano13 png pthread ${COMPILER_LIBCXX} tiff xml2 z

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=hugin/}

LIB_DEPENDS =		graphics/jpeg \
			graphics/libpano13 \
			graphics/png \
			graphics/tiff \
			textproc/libxml

MODULES +=		devel/cmake

NO_TEST =		Yes

# dos line-endings in file needing patch
post-extract:
	@cd ${WRKSRC} && perl -i -pe 's/\r$$//' CMakeLists.txt APSCpp/APSCpp.c

pre-configure:
	${SUBST_CMD} ${WRKSRC}/CMakeModules/FindPNG.cmake

.include <bsd.port.mk>
