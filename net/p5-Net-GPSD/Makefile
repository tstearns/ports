# $OpenBSD: Makefile,v 1.9 2016/03/20 19:56:53 naddy Exp $

COMMENT=	perl module that provides a client interface to gpsd
MODULES=	cpan
PKG_ARCH=	*
DISTNAME=	Net-GPSD-0.36
REVISION=	0
CATEGORIES=	net

# Perl
PERMIT_PACKAGE_CDROM=	Yes

RUN_DEPENDS=	geo/p5-GPS-PRN \
		geo/p5-Geo-Forward \
		geo/p5-Geo-Functions \
		geo/p5-Geo-Inverse \
		www/p5-libwww

MODCPAN_EXAMPLES=	Yes
MODCPAN_EXAMPLES_DIST=	bin

post-install:
	${MODCPAN_POST_INSTALL}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/*.cgi \
		${PREFIX}/share/examples/p5-Net-GPSD
	${INSTALL_DATA} ${WRKSRC}/doc/*.db \
		${PREFIX}/share/examples/p5-Net-GPSD

.include <bsd.port.mk>
