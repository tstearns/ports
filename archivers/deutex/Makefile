# $OpenBSD: Makefile,v 1.2 2018/01/16 08:51:34 bentley Exp $

COMMENT =	WAD composer for Doom, Heretic, Hexen, and Strife

GH_ACCOUNT =	Doom-Utils
GH_PROJECT =	deutex
GH_TAGNAME =	v5.1.1

CATEGORIES =	archivers

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c png z

BUILD_DEPENDS =		${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS} \
			textproc/asciidoc
LIB_DEPENDS =		graphics/png

CONFIGURE_STYLE =	gnu

AUTOCONF_VERSION =	2.69
AUTOMAKE_VERSION =	1.15

pre-configure:
	cd ${WRKDIST} && \
	AUTOCONF_VERSION="${AUTOCONF_VERSION}" \
	AUTOMAKE_VERSION="${AUTOMAKE_VERSION}" \
	autoreconf -i

.include <bsd.port.mk>
