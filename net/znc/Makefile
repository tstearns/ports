# $OpenBSD: Makefile,v 1.36 2018/05/16 06:40:51 ajacoutot Exp $

COMMENT=	advanced IRC bouncer

DISTNAME=	znc-1.7.0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}releases/

HOMEPAGE=	http://znc.in/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# Apache 2.0
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	c crypto m pthread ssl z ${COMPILER_LIBCXX}

MODULES=	devel/cmake

COMPILER=	base-clang ports-gcc

SEPARATE_BUILD=	Yes
CONFIGURE_ARGS+=	-DWANT_CYRUS=NO \
			-DWANT_I18N=NO \
			-DWANT_ICU=NO

NO_TEST=	Yes

.include <bsd.port.mk>
