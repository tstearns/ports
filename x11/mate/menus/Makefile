# $OpenBSD: Makefile,v 1.6 2018/02/10 15:07:17 robert Exp $

COMMENT=		implementation of the FreeDesktop menu spec for MATE

SHARED_LIBS +=  mate-menu                 6.9 # 6.9

MATE_PROJECT=		mate-menus

CATEGORIES=		x11

# GPLv2/LGPLv2/GFDLv1.1
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ffi iconv intl m pthread ${MODPY_WANTLIB} util z
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += pcre

MODULES=		lang/python \
			x11/gnome

LIB_DEPENDS=		devel/glib2

MODGNOME_TOOLS=		gobject-introspection

FAKE_FLAGS=		sysconfdir=${PREFIX}/share/examples/mate-menus

CONFIGURE_STYLE=	gnu

pre-configure:
	${SUBST_CMD} ${WRKSRC}/layout/mate-applications.menu

.include <bsd.port.mk>
