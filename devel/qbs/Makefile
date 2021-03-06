# $OpenBSD: Makefile,v 1.7 2018/05/25 05:45:47 rsadowski Exp $

COMMENT =	declarative cross-platform build tool
V =		1.11.1
DISTNAME =	qbs-src-${V}
PKGNAME =	qbs-${V}

SHARED_LIBS =	qbscore			4.0
SHARED_LIBS +=	qbsqtprofilesetup	2.0

CATEGORIES =	devel
HOMEPAGE =	https://doc.qt.io/qbs/
MAINTAINER =	KDE porting team <openbsd-kde@googlegroups.com>

# LGPLv3 or GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ${COMPILER_LIBCXX} GL Qt5Core Qt5Gui Qt5Network Qt5Script
WANTLIB += Qt5Widgets Qt5Xml c kvm m

MASTER_SITES =		https://download.qt.io/official_releases/qbs/${V}/

MODULES =		devel/qmake x11/qt5

MODQMAKE_PROJECTS =	qbs.pro
MODQMAKE_ARGS =		CONFIG+=qbs_enable_unit_tests=1 \
			CONFIG+=qbs_enable_project_file_updates

BUILD_DEPENDS =		x11/qt5/qtdeclarative
RUN_DEPENDS =		x11/qt5/qtdeclarative
LIB_DEPENDS =		x11/qt5/qtbase \
			x11/qt5/qtscript

TEST_DEPENDS =		${BUILD_PKGPATH}

MAKE_ENV =		LD_LIBRARY_PATH=${WRKBUILD}/lib
TEST_ENV =		LD_LIBRARY_PATH=${WRKBUILD}/lib

do-test:
	cd ${WRKBUILD}/bin/; \
	for t in tst_*; do \
	${SETENV} ${ALL_TEST_ENV} ./$$t; \
	done

pre-fake:
	${INSTALL_DATA_DIR} ${PREFIX}/include/qbs/tools
	${INSTALL_DATA} ${WRKSRC}/src/lib/corelib/tools/*.h \
		${PREFIX}/include/qbs/tools/

.include <bsd.port.mk>
