# $OpenBSD: Makefile,v 1.4 2018/04/08 22:49:23 abieber Exp $

COMMENT =		friendly interactive shell

V =			2.7.1
DISTNAME =		fish-$V
REVISION =		0

CATEGORIES =		shells

HOMEPAGE =		https://fishshell.com/

MAINTAINER =		Aaron Bieber <abieber@openbsd.org>

# GPLv2 only
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ${COMPILER_LIBCXX} c curses intl m pcre2-32

MASTER_SITES =		https://github.com/fish-shell/fish-shell/releases/download/${V}/

# C++11
COMPILER =		base-clang ports-gcc ports-clang

MODULES =		lang/python

# https://github.com/fish-shell/fish-shell/pull/4685
AUTOCONF_VERSION =	2.69
AUTOMAKE_VERSION =	1.15

BUILD_DEPENDS =		devel/gettext-tools \
			${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS}

LIB_DEPENDS =		devel/pcre2 \
			devel/gettext

RUN_DEPENDS =		misc/gnugetopt
TEST_DEPENDS =		${RUN_DEPENDS}

MODPY_ADJ_FILES =	share/tools/create_manpage_completions.py \
			share/tools/deroff.py \
			share/tools/web_config/webconfig.py

MAKE_FLAGS =		V=1

USE_GMAKE =		Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--without-included-pcre2
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

FAKE_FLAGS =		SYSCONFDIR=${PREFIX}/share/examples/fish

NO_TEST =		yes

pre-configure:
	sed -i 's/getopt/gnugetopt/' ${WRKSRC}/share/functions/*.fish
	cd ${WRKSRC} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} autoreconf

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/fish/tools/deroff.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/fish/tools/create_manpage_completions.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/fish/tools/web_config/webconfig.py
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fish
	mv ${DESTDIR}/etc/fish/config.fish ${PREFIX}/share/examples/fish/
	rm -Rf ${DESTDIR}/etc/fish

.include <bsd.port.mk>
