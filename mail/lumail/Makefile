# $OpenBSD: Makefile,v 1.30 2017/11/16 23:20:39 naddy Exp $

PORTROACH =		limit:^0

COMMENT =		console-based e-mail client with Lua scripting support

DISTNAME =		lumail-0.26
CATEGORIES =		mail
REVISION =		5

HOMEPAGE =		http://lumail.org/
MASTER_SITES =		http://lumail.org/download/

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB +=		c gio-2.0 glib-2.0 glibmm-2.4 gmime-2.6 gobject-2.0
WANTLIB +=		intl ${MODLUA_WANTLIB} m ncursesw pcrecpp pthread
WANTLIB +=		sigc-2.0 ${COMPILER_LIBCXX}

MODULES =		lang/lua

# c++11
COMPILER =		base-clang ports-gcc

LIB_DEPENDS +=		${MODLUA_LIB_DEPENDS} \
			devel/glib2mm \
			mail/gmime \
			devel/pcre

USE_GMAKE =		Yes
ALL_TARGET =		lumail lumailctl
MAKE_FLAGS =		C="${CC}" CC="${CXX}" \
			CPPFLAGS="-std=gnu++0x -I${LOCALBASE}/include \
				`pkg-config --cflags ${MODLUA_DEP}`" \
			LDLIBS="`pkg-config --libs ${MODLUA_DEP}` \
				-lncursesw -lpcrecpp"

NO_TEST =		Yes

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/src/bindings.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lumail ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lumailctl ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/lumail
	${INSTALL_DATA} ${WRKSRC}/lumail.help ${PREFIX}/share/lumail
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lumail
	${INSTALL_DATA} ${WRKSRC}/lumail.lua ${PREFIX}/share/examples/lumail

.include <bsd.port.mk>
