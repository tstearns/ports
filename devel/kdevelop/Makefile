# $OpenBSD: Makefile,v 1.16 2018/07/20 13:11:46 rsadowski Exp $

CATEGORIES =	devel x11
COMMENT =	integrated development environment for KDE 4
KDEV_V =	4.7.1
KDEVPLAT_V =	1.7.1
REVISION =	7
DISTNAME =	kdevelop-${KDEV_V}
HOMEPAGE =	http://www.kdevelop.org/

SHARED_LIBS =	kdev4cmakecommon	1.0
SHARED_LIBS +=	kdev4cppduchain		1.0
SHARED_LIBS +=	kdev4cppparser		1.0
SHARED_LIBS +=	kdev4cpprpp		1.0
SHARED_LIBS +=	kdevcompilerprovider	0.0

MASTER_SITES =	${MASTER_SITE_KDE:=stable/kdevelop/${KDEV_V}/src/}
DIST_SUBDIR =	kde

# GPLv2+, LGPLv2.1+, GNU FDLv1.2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =  c iconv intl m pthread
WANTLIB += lib/qt4/QtDBus lib/qt4/QtDeclarative lib/qt4/QtGui
WANTLIB += lib/qt4/QtHelp lib/qt4/QtNetwork lib/qt4/QtScript
WANTLIB += lib/qt4/QtSvg lib/qt4/QtWebKit lib/qt4/QtXml
WANTLIB += ${KDE4LIB}/kcmutils ${KDE4LIB}/kdeclarative ${KDE4LIB}/kdeui
WANTLIB += ${KDE4LIB}/kemoticons ${KDE4LIB}/kidletime ${KDE4LIB}/kio
WANTLIB += ${KDE4LIB}/knewstuff3 ${KDE4LIB}/knotifyconfig ${KDE4LIB}/kparts
WANTLIB += ${KDE4LIB}/kprintutils ${KDE4LIB}/ktexteditor ${KDE4LIB}/kutils
WANTLIB += ${KDE4LIB}/nepomuk ${KDE4LIB}/nepomukutils ${KDE4LIB}/plasma
WANTLIB += ${KDE4LIB}/threadweaver
WANTLIB += kdevplatformdebugger kdevplatformdocumentation
WANTLIB += kdevplatforminterfaces kdevplatformlanguage
WANTLIB += kdevplatformoutputview kdevplatformproject kdevplatformshell
WANTLIB += kdevplatformutil kdevplatformvcs
WANTLIB += processcore processui qjson soprano sublime
WANTLIB += ${COMPILER_LIBCXX}

MODULES =	x11/kde4 lang/python
MODKDE4_USE =	workspace

BUILD_DEPENDS =	devel/gettext-tools \
		misc/shared-mime-info

RUN_DEPENDS =	x11/kde-applications/kate \
		devel/desktop-file-utils \
		misc/shared-mime-info \
		x11/gtk+3,-guic \
		x11/kde4/kapptemplate>=${MODKDE4_DEP_VERSION}

LIB_DEPENDS = 	devel/kdevplatform>=${KDEVPLAT_V}

pre-configure:
	rm ${WRKSRC}/cmake/modules/{FindLibOkteta.cmake,FindLibKasten.cmake}

# XXX because OBJECT_DEPENDS doesn't work as it should in
# the patch-languages_cpp_CMakeLists_txt
pre-build:
	@${MODCMAKE_BUILD_TARGET:S,^${ALL_TARGET}$,languages/cpp/ui_custom_include_paths.h,}

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${PREFIX}/share/apps/kdevgdb/printers

.include <bsd.port.mk>
