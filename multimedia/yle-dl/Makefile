# $OpenBSD: Makefile,v 1.17 2018/06/02 12:01:59 jasper Exp $

GH_ACCOUNT =		aajanki
GH_PROJECT =		yle-dl
GH_TAGNAME =		2.28
MODPY_EGG_VERSION =	${GH_TAGNAME}
REVISION =		2

COMMENT =		download videos from YLE Areena

CATEGORIES =		multimedia

HOMEPAGE =		http://aajanki.github.io/yle-dl/
MAINTAINER =		Timo Myyra <timo.myyra@bittivirhe.fi>

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python \
			lang/php

TEST_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/py-progress \
			net/rtmpdump \
			security/py-cryptodome \
			www/py-requests \
			lang/php/${MODPHP_VERSION},-curl \
			lang/php/${MODPHP_VERSION},-mcrypt \
			net/wget \
			textproc/py-lxml \
			converters/py-amf


MODPY_SETUPTOOLS =	Yes
MODPHP_BUILDDEP =	No

pre-configure:
	@sed -i -e "s,'php','${MODPHP_BIN}',g" ${WRKSRC}/yledl/downloaders.py

.include <bsd.port.mk>
