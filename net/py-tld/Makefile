# $OpenBSD: Makefile,v 1.2 2018/04/13 08:19:04 rpointel Exp $

COMMENT =	extracts the top level domain (TLD) from the URL given

MODPY_EGG_VERSION =	0.7.10
DISTNAME =	tld-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	net

MAINTAINER =	Remi Pointel <rpointel@openbsd.org>

# MPL 1.1/GPL 2.0/LGPL 2.1
PERMIT_PACKAGE_CDROM =	Yes

MODULES =	lang/python
MODPY_SETUPTOOLS = Yes
MODPY_PI =	Yes

FLAVORS =	python3
FLAVOR ?=

RUN_DEPENDS =	devel/py-six${MODPY_FLAVOR}

TESTS_DEPENDS =	${RUN_DEPENDS}

post-install:
	mv ${PREFIX}/bin/update-tld-names ${PREFIX}/bin/update-tld-names${MODPY_BIN_SUFFIX}

.include <bsd.port.mk>
