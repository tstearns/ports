# $OpenBSD: Makefile,v 1.30 2018/06/03 16:57:11 kn Exp $

COMMENT=		dynamic window manager

V=			6.1
DISTNAME=		dwm-${V}
REVISION=		2

CATEGORIES=		x11

HOMEPAGE=		https://dwm.suckless.org/

MAINTAINER=		Klemens Nanni <kn@openbsd.org>

# MIT/X
PERMIT_PACKAGE_CDROM=	Yes

# uses pledge()
WANTLIB=		X11 Xinerama Xft c fontconfig

MASTER_SITES=		https://dl.suckless.org/dwm/

RUN_DEPENDS=		x11/dmenu>=4.6 \
			fonts/terminus-font

MAKE_ENV=		LDFLAGS="${LDFLAGS}" \
			X11INC=${X11BASE}/include \
			X11LIB=${X11BASE}/lib

NO_TEST=		Yes

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/dwm ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dwm.1 ${PREFIX}/man/man1/
	sed -i s/VERSION/${V}/g ${PREFIX}/man/man1/dwm.1

.include <bsd.port.mk>
