# $OpenBSD: Makefile,v 1.3 2018/06/11 13:22:25 jasper Exp $

PKG_ARCH =		*

COMMENT =		font family inspired by Highway Gothic

V =			3.0.3
DISTNAME =		overpass-$V

CATEGORIES =		fonts

HOMEPAGE =		http://overpassfont.org/

# SIL OFL 1.1
PERMIT_PACKAGE_CDROM =	Yes

GH_ACCOUNT =		RedHatBrand
GH_PROJECT =		Overpass
GH_TAGNAME =		$V

NO_BUILD =		Yes
NO_TEST =		Yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/fonts/overpass
	${INSTALL_DATA} ${WRKSRC}/desktop-fonts/*/*.otf \
		${WRKSRC}/webfonts/*/*.ttf \
		${PREFIX}/share/fonts/overpass

.include <bsd.port.mk>
