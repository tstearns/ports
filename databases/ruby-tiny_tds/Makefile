# $OpenBSD: Makefile,v 1.17 2018/06/13 22:26:52 jeremy Exp $

COMMENT =	simple and fast ruby binding to FreeTDS

DISTNAME =	tiny_tds-2.1.0
REVISION =	0
CATEGORIES =	databases

HOMEPAGE =	https://github.com/rails-sqlserver/tiny_tds

MAINTAINER  =	Jeremy Evans <jeremy@openbsd.org>

# MIT License
PERMIT_PACKAGE_CDROM =	Yes

MODULES =	lang/ruby

WANTLIB =	sybdb

LIB_DEPENDS =	databases/freetds

CONFIGURE_STYLE =ruby gem ext

.include <bsd.port.mk>
