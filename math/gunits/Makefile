# $OpenBSD: Makefile,v 1.4 2017/12/03 13:42:03 ajacoutot Exp $

COMMENT=		GNU units conversion program

DISTNAME=		units-2.16
PKGNAME=		g${DISTNAME}
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GNU:=units/}

HOMEPAGE=		https://www.gnu.org/software/units/

# GPLv3+
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c curses m readline

MODULES =		lang/python

RUN_DEPENDS =		textproc/py-unidecode,${MODPY_FLAVOR}

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	--program-prefix=g

.include <bsd.port.mk>
