# $OpenBSD: Makefile,v 1.22 2017/11/21 00:13:04 naddy Exp $

COMMENT=	import and export WordPerfect(tm) documents

DISTNAME=	libwpd-0.8.9
CATEGORIES=	textproc

REVISION=	10

SHARED_LIBS=	wpd-0.8		8.9 \
		wpd-stream-0.8	8.9

HOMEPAGE=	http://libwpd.sourceforge.net/

MAINTAINER=	Robert Nagy <robert@openbsd.org>

# LGPL
PERMIT_PACKAGE_CDROM=   Yes

WANTLIB += bz2 c ffi gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 gsf-1
WANTLIB += gthread-2.0 iconv intl lzma m pcre pthread ${COMPILER_LIBCXX} xml2 z

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}


LIB_DEPENDS=		devel/libgsf
TEST_DEPENDS=	devel/cppunit

CONFIGURE_STYLE= 	gnu
CONFIGURE_ARGS=		--without-docs

.include <bsd.port.mk>
