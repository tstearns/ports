# $OpenBSD: Makefile,v 1.28 2018/05/15 11:18:19 espie Exp $

COMMENT=		C++ binding for the ATK library

GNOME_PROJECT=		atkmm
GNOME_VERSION=		2.24.2
PKGNAME=		atk2mm-${GNOME_VERSION}
REVISION=		2

CATEGORIES=		devel

SHARED_LIBS +=  atkmm-1.6            10.1     # 2.0

HOMEPAGE=		http://www.gtkmm.org/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += atk-1.0 ffi glib-2.0 glibmm-2.4 gmodule-2.0 gobject-2.0
WANTLIB += iconv intl m pcre pthread sigc-2.0
WANTLIB += ${COMPILER_LIBCXX}

MODULES=		x11/gnome
# c++11
COMPILER =		base-clang ports-gcc

LIB_DEPENDS=		devel/glib2mm \
			devel/atk

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--enable-static \
			--disable-dependency-tracking

.include <bsd.port.mk>
