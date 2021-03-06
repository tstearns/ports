# $OpenBSD: Makefile,v 1.15 2018/07/11 17:24:31 bcallah Exp $

COMMENT =		file, shell and text manipulation utilities

DISTNAME =		coreutils-8.30
CATEGORIES =		sysutils

MAINTAINER =		Brian Callahan <bcallah@openbsd.org>

HOMEPAGE =		https://www.gnu.org/software/coreutils/coreutils.html

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c iconv intl pthread

MASTER_SITES =		${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX =		.tar.xz

LIB_DEPENDS =		devel/gettext

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--program-prefix=g \
			--without-gmp

# Prevent conflicts with: id, gpr and god
post-install:
.for I in gid god gpr
	mv "${PREFIX}/bin/$I" "${PREFIX}/bin/g$I"
	mv "${PREFIX}/man/man1/$I.1" "${PREFIX}/man/man1/g$I.1"
.endfor
	if test -f "${PREFIX}/libexec/coreutils/glibstdbuf.so"; then \
	    mv "${PREFIX}/libexec/coreutils/glibstdbuf.so" \
	       "${PREFIX}/libexec/coreutils/libstdbuf.so"; \
	fi

.include <bsd.port.mk>
