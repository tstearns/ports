# $OpenBSD: Makefile,v 1.13 2018/01/22 21:48:45 kili Exp $

COMMENT =		basic types for representing XML

DISTNAME =		xml-types-0.3.6
REVISION =		4
CATEGORIES =		textproc

HOMEPAGE =		https://john-millikin.com/software/haskell-xml/

MAINTAINER =		David Coppa <dcoppa@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	KBWVauU3pnf3clHxqFFRXL

RUN_DEPENDS =		devel/hs-text
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
