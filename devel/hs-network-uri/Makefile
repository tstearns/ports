# $OpenBSD: Makefile,v 1.6 2018/01/22 21:42:27 kili Exp $

COMMENT =		URI manipulation

# Dependency of meta/haskell-platform.
# Please do *not* update without thinking.
PORTROACH =		ignore:1

DISTNAME =		network-uri-2.6.0.3
REVISION =		3
CATEGORIES =		devel net

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	GWiZs2R299yBQO2d6Ohaq0

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-parsec>=3.0,<3.2

.include <bsd.port.mk>
