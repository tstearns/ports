# $OpenBSD: Makefile,v 1.78 2018/04/23 13:24:35 jasper Exp $

COMMENT=		dialogs for GNOME

GNOME_PROJECT=		zenity
GNOME_VERSION=		3.28.1

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 atk-1.0 c cairo cairo-gobject gdk-3 gdk_pixbuf-2.0 intl
WANTLIB += gio-2.0 glib-2.0 gobject-2.0 gtk-3 javascriptcoregtk-4.0
WANTLIB += notify pango-1.0 pangocairo-1.0 pthread soup-2.4 webkit2gtk-4.0
WANTLIB += fribidi

MODULES=		x11/gnome

LIB_DEPENDS=		devel/libnotify>=0.7.2 \
			www/webkitgtk4

MODGNOME_TOOLS +=	yelp

CONFIGURE_STYLE=	gnu

.include <bsd.port.mk>
