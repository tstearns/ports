# $OpenBSD: Makefile,v 1.14 2017/07/27 11:01:33 sthen Exp $

COMMENT =	asynchronous networking framework for GNUstep

VERSION =	1.1.0
REVISION =	4
EPOCH =		0
DISTNAME =	netclasses-${VERSION}
PKGNAME =	gnustep-netclasses-${VERSION}
CATEGORIES =	net
SHARED_LIBS +=  netclasses	0.0

HOMEPAGE =	http://gap.nongnu.org/talksoup/
MASTER_SITES =	${MASTER_SITE_SAVANNAH:=gap/}

MODULES =		x11/gnustep
MODGNUSTEP_IS_FRAMEWORK = Yes
WANTLIB += 		pthread

CONFIGURE_STYLE =	gnu
MAKE_FLAGS +=	netclasses_INTERFACE_VERSION=${LIBnetclasses_VERSION}

.include <bsd.port.mk>
