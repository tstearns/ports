# $OpenBSD: Makefile,v 1.11 2018/06/04 00:56:09 sthen Exp $

COMMENT =		memory artifact extraction utility framework

MODPY_EGG_VERSION =	2.6
DISTNAME =		volatility-${MODPY_EGG_VERSION}
REVISION =		1

EXTRACT_SUFX =		.zip

CATEGORIES =		security

HOMEPAGE =		http://www.volatilityfoundation.org/

MAINTAINER = 		Remi Pointel <rpointel@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM = Yes

MASTER_SITES =		http://downloads.volatilityfoundation.org/releases/${MODPY_EGG_VERSION}/

MODULES =		lang/python
MODPY_SETUPTOOLS = 	Yes

RUN_DEPENDS =	security/distorm3 \
		security/yara/python \
		graphics/py-Pillow \
		security/py-cryptodome

WRKDIST = 	${WRKDIR}/volatility-master

NO_TEST =		Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/volatility/
.for dir in contrib tools
	mv ${PREFIX}/${dir} ${PREFIX}/share/volatility/
.endfor

.include <bsd.port.mk>
