# $OpenBSD: Makefile,v 1.12 2016/06/29 16:14:39 espie Exp $

VERSION =	2.60
REVISION =	5

BUILD_DEPENDS =		devel/help2man

CONFIGURE_ARGS +=	--without-lispdir \
			--mandir=${PREFIX}/man \
			--infodir=${PREFIX}/info
MODGNU_CONFIG_GUESS_DIRS = ${WRKSRC}/config
MAKE_FLAGS +=		EMACS=no
FAKE_FLAGS +=		EMACS=no

.include <bsd.port.mk>
