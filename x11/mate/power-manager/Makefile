# $OpenBSD: Makefile,v 1.9 2018/07/06 06:04:48 espie Exp $

COMMENT=		MATE power manager
REVISION=		2

MATE_PROJECT=		mate-power-manager
MATE_VERSION=		1.20.1

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xext Xfixes
WANTLIB += Xi Xinerama Xrandr Xrender c epoxy expat ffi fontconfig
WANTLIB += freetype gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += gobject-2.0 gthread-2.0 iconv intl m pcre pixman-1
WANTLIB += png pthread xcb xcb-render xcb-shm z fribidi
WANTLIB += atk-1.0 atk-bridge-2.0 atspi cairo-gobject cairo
WANTLIB += canberra-gtk3 canberra dbus-1 dbus-glib-1 execinfo
WANTLIB += gcrypt gdk-3 gnome-keyring gpg-error graphite2 gtk-3
WANTLIB += harfbuzz ltdl mate-panel-applet-4 notify ogg pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 upower-glib vorbis vorbisfile

MODULES=		devel/dconf \
			x11/gnome

MODGNOME_TOOLS=		desktop-file-utils gtk-update-icon-cache yelp

CONFIGURE_STYLE=	gnu

MODGNOME_LDFLAGS=	-lexecinfo

LIB_DEPENDS=		sysutils/upower \
			devel/libexecinfo \
			x11/gnome/libgnome-keyring \
			x11/mate/panel

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${MATE_PROJECT}
	@mv ${WRKINST}/etc/xdg \
		${PREFIX}/share/examples/${MATE_PROJECT}/xdg

.include <bsd.port.mk>
