# $OpenBSD: Makefile,v 1.15 2018/05/29 18:42:58 rpointel Exp $

COMMENT =	lightweight in-process concurrent programming
# see slp_platformselect.h
ONLY_FOR_ARCHS =	aarch64 amd64 arm i386 powerpc sparc64

MODPY_EGG_VERSION = 0.4.13
DISTNAME =	greenlet-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	devel

# BSD-like
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ${MODPY_WANTLIB}
WANTLIB += pthread

MODPY_PI =	Yes

MODULES =	lang/python

FLAVORS =	python3
FLAVOR ?=

INCL_DIR =	${MODPY_INCDIR:S/${LOCALBASE}\///}
SUBST_VARS +=	INCL_DIR

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${MODPY_PY_PREFIX}greenlet
	${INSTALL_DATA} ${WRKSRC}/README.rst \
		${PREFIX}/share/doc/${MODPY_PY_PREFIX}greenlet

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MODPY_BIN} ./run-tests.py

.include <bsd.port.mk>
