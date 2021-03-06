# $OpenBSD: Makefile,v 1.41 2018/05/18 14:22:07 fcambus Exp $

V =		2.8.9
PL =		19
COMMENT =	text web browser
DISTNAME =	lynx${V}dev.${PL}
PKGNAME =	lynx-${V}pl${PL}
EXTRACT_SUFX =	.tar.bz2
CATEGORIES =	www net

HOMEPAGE =	https://lynx.invisible-island.net/

MAINTAINER =	Frederic Cambus <fcambus@openbsd.org>

# GPLv2 only
PERMIT_PACKAGE_CDROM =	Yes

# uses pledge()
WANTLIB +=	c crypto curses ssl z

MASTER_SITES =	https://invisible-mirror.net/archives/lynx/tarballs/ \
		ftp://ftp.invisible-island.net/lynx/tarballs/

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--datarootdir="${PREFIX}/share/doc/lynx" \
			--disable-idna \
			--disable-nls \
			--disable-bibp-urls \
			--disable-dired \
			--disable-finger \
			--enable-default-colors \
			--enable-ipv6 \
			--enable-widec \
			--with-ssl=/usr \
			--with-zlib \
			--without-bzlib

# This disables most calls to getpw*(3) so we can avoid pledge "getpw".
CONFIGURE_ENV +=	CFLAGS="-DNOUSERS"

# Prevent accepting bzip2 compressed HTML to avoid spawning processes.
CONFIGURE_ENV +=	ac_cv_path_BZIP2=none

MAKE_FILE =	makefile

FAKE_FLAGS =	SYSCONFDIR="${DESTDIR}${PREFIX}/share/examples/lynx"
INSTALL_TARGET =	install install-help install-doc

NO_TEST =	Yes

.include <bsd.port.mk>
