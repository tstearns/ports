# $OpenBSD: Makefile,v 1.4 2017/05/12 20:00:43 benoit Exp $

COMMENT =	read, write, and edit vCard address books

MODULES =	cpan
PKG_ARCH =	*
DISTNAME =	Text-vCard-3.09
CATEGORIES =	textproc

# Perl
PERMIT_PACKAGE_CDROM=	Yes

BUILD_DEPENDS =	${RUN_DEPENDS}
RUN_DEPENDS =	www/p5-URI \
		devel/p5-Moo \
		devel/p5-Path-Tiny \
		devel/p5-Text-vFile-asData \
		converters/p5-Unicode-LineBreak
TEST_DEPENDS =	devel/p5-Test-Most \
		devel/p5-Directory-Scratch

.include <bsd.port.mk>
