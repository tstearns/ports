# $OpenBSD: Makefile,v 1.78 2018/06/15 10:20:53 sthen Exp $

PV=		5.6
V=		${PV}.36
REVISION=	8
REVISION-apache= 9
REVISION-gd=	9
REVISION-main=	10

MASTER_SITES0=	https://download.suhosin.org/

FLAVORS=	no_suhosin
FLAVOR?=

SUHOSIN_V=	0.9.38

SUPDISTFILES=	suhosin-${SUHOSIN_V}.tar.gz:0

.if !${FLAVOR:Mno_suhosin}
DISTFILES+=	suhosin-${SUHOSIN_V}.tar.gz:0
PATCH_LIST=	patch-* suhosin-*
CONFIGURE_ARGS+= --enable-suhosin

pre-patch:
	@mv ${WRKDIR}/suhosin-${SUHOSIN_V} ${WRKSRC}/ext/suhosin
.endif

.include <bsd.port.mk>
