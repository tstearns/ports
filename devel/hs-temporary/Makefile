# $OpenBSD: Makefile,v 1.2 2018/01/22 21:43:45 kili Exp $

COMMENT =		portable temporary file and directory support

DISTNAME =		temporary-1.2.1.1
REVISION =		0
CATEGORIES =		devel

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	EaGJD8l9MwE6FMqsytxEjz

RUN_DEPENDS =		devel/hs-exceptions>=0.6

BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
