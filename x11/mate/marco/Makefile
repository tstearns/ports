# $OpenBSD: Makefile,v 1.10 2018/07/06 06:04:47 espie Exp $

COMMENT=		the MATE window manager
REVISION=		1

SHARED_LIBS +=  marco-private             1.0 # 1.0

MATE_PROJECT=		marco
MATE_VERSION=		1.20.1

CATEGORIES=		x11

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ICE SM X11 X11-xcb Xcomposite Xcursor Xdamage Xext
WANTLIB += Xfixes Xi Xinerama Xrandr Xrender atk-1.0 atk-bridge-2.0
WANTLIB += atspi c cairo cairo-gobject dbus-1 epoxy expat ffi
WANTLIB += fontconfig freetype gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 graphite2 gthread-2.0 gtk-3
WANTLIB += harfbuzz iconv intl m ogg pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png pthread fribidi
WANTLIB += vorbis vorbisfile xcb xcb-render xcb-shm xcb-util z
WANTLIB += canberra canberra-gtk3 ltdl startup-notification-1

LIB_DEPENDS=		audio/libcanberra,-gtk3 \
			devel/startup-notification

BUILD_DEPENDS=		x11/gnome/zenity
RUN_DEPENDS=		x11/gnome/zenity

MODULES=		devel/dconf \
			x11/gnome

MODGNOME_TOOLS=		yelp

CONFIGURE_STYLE=	gnu

.include <bsd.port.mk>
