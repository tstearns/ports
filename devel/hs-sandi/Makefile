# $OpenBSD: Makefile,v 1.6 2018/01/22 21:43:45 kili Exp $

COMMENT =		data encoding library

DISTNAME =		sandi-0.4.1
REVISION =		0
CATEGORIES =		devel

# BSD
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	IzshKkho05BGGpyRzAGPU7

BUILD_DEPENDS =		${RUN_DEPENDS}

RUN_DEPENDS =		devel/hs-conduit>=1.2,<1.3 \
			devel/hs-exceptions>=0.6,<0.9 \
			textproc/hs-stringsearch>=0.3,<0.4

.include <bsd.port.mk>
