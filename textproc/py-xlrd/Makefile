# $OpenBSD: Makefile,v 1.1.1.1 2018/06/19 05:36:01 rpointel Exp $

COMMENT =	extract data from xls and xlsx spreadsheet files

MODPY_EGG_VERSION =	1.1.0
DISTNAME =		xlrd-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}

CATEGORIES =	textproc devel

HOMEPAGE =	http://www.python-excel.org/

# BSD-style
PERMIT_PACKAGE_CDROM =	Yes

MODULES =	lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS = 	Yes

FLAVORS =	python3
FLAVOR ?=

TEST_DEPENDS =		devel/py-test${MODPY_FLAVOR}

post-install:
	mv ${PREFIX}/bin/runxlrd.py ${PREFIX}/bin/runxlrd${MODPY_BIN_SUFFIX}

do-test:
	@cd ${WRKSRC} && ${MODPY_BIN} -m pytest

.include <bsd.port.mk>
