# $OpenBSD: Makefile,v 1.3 2018/04/03 20:22:12 rpointel Exp $

COMMENT =	dex to java decompiler

VERSION =	0.7.1
DISTNAME =	jadx-${VERSION}

CATEGORIES =	devel security

HOMEPAGE =	https://github.com/skylot/jadx

MAINTAINER =	Remi Pointel <rpointel@openbsd.org>

# Apachev2
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =	https://github.com/skylot/jadx/releases/download/v${VERSION}/

EXTRACT_SUFX =	.zip

MODULES =	java
MODJAVA_VER =	1.8+
MODJAVA_JRERUN =Yes

RUN_DEPENDS =	java/javaPathHelper \
		shells/bash

NO_BUILD =	Yes
NO_TEST =	Yes

WRKDIST = ${WRKDIR}

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/jadx/
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/jadx/lib
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/jadx/bin
	cp -r ${WRKSRC}/lib ${PREFIX}/share/jadx/
.for i in jadx jadx-gui
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${i} ${PREFIX}/share/jadx/bin/
	ln -s ${TRUEPREFIX}/share/jadx/bin/${i} ${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
