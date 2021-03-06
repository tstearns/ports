# $OpenBSD: Makefile,v 1.4 2018/07/09 13:38:26 gonzalo Exp $

COMMENT =		interact with Mastodon social networks from the command line

MODPY_EGG_VERSION =	0.19.0
DISTNAME =		toot-${MODPY_EGG_VERSION}

CATEGORIES =		net

MAINTAINER =		Klemens Nanni <kn@openbsd.org>

MASTER_SITES =		https://github.com/ihabunek/toot/releases/download/${MODPY_EGG_VERSION}/

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-future${MODPY_FLAVOR}>=0.16 \
			www/py-beautifulsoup4${MODPY_FLAVOR}>=4.5.0,<5.0 \
			www/py-requests${MODPY_FLAVOR}>=2.13,<3.0
TEST_DEPENDS =		${FULLPKGNAME}:${BUILD_PKGPATH} \
			devel/py-test${MODPY_FLAVOR}>=3.0.0 \
			devel/py-test-cov${MODPY_FLAVOR}>=2.4.0

MAKE_ENV =		LC_CTYPE=C.UTF-8
TEST_ENV =		PATH=${PORTPATH}

pre-test:
	ln -sf ${LOCALBASE}/bin/py.test${MODPY_BIN_SUFFIX} \
	    ${WRKDIR}/bin/py.test

do-test:
	${TEST_ENV} ${MAKE_PROGRAM} -C ${WRKSRC} coverage

.include <bsd.port.mk>
