# $OpenBSD: Makefile,v 1.7 2018/06/27 19:09:19 espie Exp $

REVISION=4

COMMENT =	sqlalchemy support for flask

MODPY_EGG_VERSION = 1.0
DISTNAME =	Flask-SQLAlchemy-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME:L}

CATEGORIES =	databases www

HOMEPAGE =	https://github.com/mitsuhiko/flask-sqlalchemy/

# BSD
PERMIT_PACKAGE_CDROM =	Yes

MODPY_PI =	Yes

MODULES =	lang/python

MODPY_SETUPTOOLS = Yes

BUILD_DEPENDS =	databases/py-sqlalchemy \
		textproc/py-sphinx \
		www/py-flask
RUN_DEPENDS =	databases/py-sqlalchemy \
		www/py-flask
TEST_DEPENDS =	${RUN_DEPENDS}

MAKE_ENV =	PYTHONPATH="${WRKSRC}"

post-build:
	@cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} html

post-install:
	${INSTALL_DATA_DIR} \
	    ${PREFIX}/share/doc/${MODPY_PY_PREFIX}flask-sqlalchemy
	cd ${WRKSRC}/docs/_build/html && \
	    pax -rw * ${PREFIX}/share/doc/${MODPY_PY_PREFIX}flask-sqlalchemy

.include <bsd.port.mk>
