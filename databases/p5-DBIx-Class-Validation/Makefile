# $OpenBSD: Makefile,v 1.11 2016/03/20 19:56:10 naddy Exp $

COMMENT=	data validation for DBIx::Class

MODULES=	cpan
PKG_ARCH=	*
DISTNAME=	DBIx-Class-Validation-0.02005
CATEGORIES=	databases devel

# perl
PERMIT_PACKAGE_CDROM=	Yes

RUN_DEPENDS=	databases/p5-DBIx-Class \
		devel/p5-FormValidator-Simple

TEST_DEPENDS=databases/p5-DBD-SQLite \
		devel/p5-DateTime-Format-SQLite \
		devel/p5-Data-FormValidator \
		devel/p5-Test-Spelling

MAKE_ENV=	TEST_POD=Yes TEST_AUTHOR=Yes

CONFIGURE_STYLE =	modinst

.include <bsd.port.mk>
