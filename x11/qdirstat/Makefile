# $OpenBSD: Makefile,v 1.3 2018/06/29 22:16:34 espie Exp $

COMMENT =	Qt-based directory statistics

GH_ACCOUNT =	shundhammer
GH_PROJECT =	qdirstat
GH_TAGNAME =	1.4
REVISION =	1

CATEGORIES =	x11

MAINTAINER =	Rafael Sadowski <rsadowski@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ${COMPILER_LIBCXX} GL Qt5Core Qt5Gui Qt5Widgets c m
WANTLIB += z

MODULES =	devel/qmake \
		x11/qt5

RUN_DEPENDS +=	devel/desktop-file-utils \
		x11/gtk+3,-guic

post-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/src/qdirstat ${PREFIX}/bin/

.include <bsd.port.mk>
