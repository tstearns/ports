# $OpenBSD: Makefile,v 1.68 2017/10/22 08:21:35 rsadowski Exp $

COMMENT=	perl-compatible regular expression library

DISTNAME=	pcre-8.41

SHARED_LIBS +=  pcre                 3.0      # 0.1
SHARED_LIBS +=  pcre16               0.0      # 0.0
SHARED_LIBS +=  pcreposix            1.5      # 0.0
SHARED_LIBS +=  pcrecpp              3.3      # 0.0

CATEGORIES=	devel
DPB_PROPERTIES=	parallel

MASTER_SITES=	https://ftp.pcre.org/pub/pcre/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/

HOMEPAGE=	http://www.pcre.org/

MAINTAINER=	Robert Nagy <robert@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c curses m readline ${COMPILER_LIBCXX}

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--enable-pcre8 \
			--enable-pcre16 \
			--enable-utf \
			--enable-unicode-properties \
			--enable-pcretest-libreadline

.include <bsd.port.mk>
