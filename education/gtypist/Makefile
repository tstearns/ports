# $OpenBSD: Makefile,v 1.33 2018/05/20 08:43:45 espie Exp $

COMMENT=	interactive typing tutor

DISTNAME=	gtypist-2.9.5
REVISION=	1
CATEGORIES=	education
HOMEPAGE=	https://www.gnu.org/software/gtypist/

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPLv3+
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	${MASTER_SITE_GNU:=gtypist/}
EXTRACT_SUFX=	.tar.xz

WANTLIB=	c iconv intl ncursesw
LIB_DEPENDS=	devel/gettext

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${WRKDIR}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" EMACS=no

MAKE_FLAGS=	'gtypist_LDADD=$$(LTLIBINTL)'

# wide curses header expected at <ncursesw/ncurses.h>
pre-configure:
	mkdir ${WRKDIR}/include
	ln -s /usr/include ${WRKDIR}/include/ncursesw

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/tools/gtypist-mode.el \
		${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
