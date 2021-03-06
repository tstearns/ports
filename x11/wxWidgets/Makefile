# $OpenBSD: Makefile,v 1.60 2018/04/08 20:23:44 rsadowski Exp $

COMMENT-main =	C++ cross-platform GUI toolkit
COMMENT-media =	wxMediaCtrl class for wxWidgets

V =		2.8.12
DISTNAME =	wxWidgets-${V}
PKGNAME-main =	wxWidgets-gtk2-${V}
PKGNAME-media =	wxWidgets-media-${V}
REVISION-main =	16
REVISION-media =11
CATEGORIES =	x11
MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=wxwindows/}

SHARED_LIBS =	wx_base			3.0	\
		wx_base_net		3.0	\
		wx_base_odbc		3.0	\
		wx_base_xml		3.0	\
		wx_gtk2_adv		3.0	\
		wx_gtk2_aui		3.0	\
		wx_gtk2_core		3.0	\
		wx_gtk2_dbgrid		3.0	\
		wx_gtk2_fl		3.0	\
		wx_gtk2_gizmos		3.0	\
		wx_gtk2_gizmos_xrc	3.0	\
		wx_gtk2_gl		3.0	\
		wx_gtk2_html		3.0	\
		wx_gtk2_media		3.0	\
		wx_gtk2_ogl		3.0	\
		wx_gtk2_plot		3.0	\
		wx_gtk2_qa		3.0	\
		wx_gtk2_richtext	3.0	\
		wx_gtk2_stc		3.0	\
		wx_gtk2_svg		3.0	\
		wx_gtk2_xrc		3.0

HOMEPAGE =	https://www.wxwidgets.org/

# wxWindows (modified LGPL)
# http://www.wxwidgets.org/about/licence/
PERMIT_PACKAGE_CDROM =	Yes

MULTI_PACKAGES = -main -media

BUILD_DEPENDS =	devel/cppunit \
		devel/gettext-tools
LIB_DEPENDS =	devel/gettext \
		x11/gtk+2
TEST_DEPENDS = ${BUILD_PKGPATH}>=${V}

LIB_DEPENDS-main =	${LIB_DEPENDS} \
			archivers/libmspack \
			databases/iodbc \
			devel/sdl

WANTLIB-main += GL GLU SDL SM X11 Xcomposite Xcursor Xdamage Xext Xfixes
WANTLIB-main += Xi Xinerama Xrandr Xrender Xxf86vm atk-1.0 c expat
WANTLIB-main += fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0
WANTLIB-main += glib-2.0 gobject-2.0 gthread-2.0 gtk-x11-2.0 iconv
WANTLIB-main += intl iodbc jpeg m mspack pango-1.0 pangoft2-1.0 png
WANTLIB-main += pthread ${COMPILER_LIBCXX} tiff z

LIB_DEPENDS-media =	${LIB_DEPENDS} \
			devel/gconf2 \
			multimedia/gstreamer-0.10/core \
			multimedia/gstreamer-0.10/plugins-base \
			${BASE_PKGPATH},-main>=${V}

WANTLIB-media += SM X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB-media += Xrandr Xrender Xxf86vm atk-1.0 fontconfig freetype
WANTLIB-media += gconf-2 gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB-media += gmodule-2.0 gobject-2.0 gstinterfaces-0.10 gstreamer-0.10
WANTLIB-media += gthread-2.0 gtk-x11-2.0 iconv intl jpeg m pango-1.0
WANTLIB-media += pangoft2-1.0 png pthread ${COMPILER_LIBCXX} tiff wx_base wx_gtk2_core
WANTLIB-media += xml2 z

MAKE_FLAGS =	WXUNICODEFLAG=""
.for _l _v in ${SHARED_LIBS}
MAKE_ENV +=	LIB${_l}_VERSION=${_v}
.endfor

USE_GMAKE =	Yes
AUTOCONF_VERSION = 2.59
CONFIGURE_STYLE =autoconf no-autoheader
CONFIGURE_ARGS =--disable-backtrace \
		--enable-mediactrl \
		--enable-unicode \
		--with-odbc \
		--with-opengl \
		--with-sdl \
		--without-gnomeprint \
		--enable-graphics_ctx
CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		WXCONFIG_CPPFLAGS="-I${X11BASE}/include" \
		ac_cv_lib_esd_esd_close=no

# XXX: When used in conjunction with PIE, symbol versioning triggers
# weird linking problems in dependent ports
CONFIGURE_ENV += wx_cv_version_script=no

.ifdef DEBUG
CONFIGURE_ARGS += --enable-debug
.endif

# fix clang6 build
post-extract:
	find ${WRKSRC}/src/ -type f -name '*.xbm' -exec sed -i \
	's/char/unsigned char/g' {} +

do-test:
	@cd ${WRKSRC}/tests && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} && ./test

.include <bsd.port.mk>
