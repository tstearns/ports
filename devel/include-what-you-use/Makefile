#	$OpenBSD: Makefile,v 1.12 2018/05/22 07:34:09 jsg Exp $

COMMENT=	tool to analyse \#includes in C and C++ source files
CATEGORIES=	devel
DISTNAME=	include-what-you-use-0.9.src
PKGNAME=	include-what-you-use-0.9
REVISION=	1

HOMEPAGE=	http://include-what-you-use.org
MASTER_SITES=	${HOMEPAGE}/downloads/
WRKDIST=	${WRKDIR}/include-what-you-use

MAINTAINER=	Jonathan Gray <jsg@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	c curses execinfo form m pthread z
BUILD_DEPENDS=	devel/llvm>=6.0.0
LIB_DEPENDS=	devel/libexecinfo

MODULES=		devel/cmake lang/python
COMPILER=		base-clang ports-gcc
COMPILER_LANGS=		c++
CONFIGURE_ARGS=		-DIWYU_LLVM_ROOT_PATH=${LOCALBASE}

MODPY_ADJ_FILES = fix_includes.py iwyu_tool.py

.include <bsd.port.mk>
