# $OpenBSD: Makefile,v 1.3 2018/04/13 11:03:58 rpointel Exp $

COMMENT =	linter for YAML files

MODPY_EGG_VERSION = 1.11.1
DISTNAME =	yamllint-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	devel

MAINTAINER =	Remi Pointel <rpointel@openbsd.org>

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes

MODULES =	lang/python
MODPY_PI =	Yes
MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =	devel/py-pathspec${MODPY_FLAVOR} \
		textproc/py-yaml${MODPY_FLAVOR}
TEST_DEPENDS =	${RUN_DEPENDS}

FLAVORS =	python3
FLAVOR ?=

post-install:
	mv ${PREFIX}/bin/yamllint ${PREFIX}/bin/yamllint${MODPY_BIN_SUFFIX}

.include <bsd.port.mk>
