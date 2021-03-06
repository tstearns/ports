# $OpenBSD: Makefile,v 1.9 2017/05/12 15:11:17 espie Exp $

COMMENT=	Tanuki Java Service Wrapper

SVN_REV=	1780
DISTNAME=	wrapper-code-${SVN_REV}-trunk
PKGNAME=	java-tanukiwrapper-3.5.19.1
REVISION=	3
CATEGORIES=	java

HOMEPAGE=	http://wrapper.tanukisoftware.com/

MASTER_SITES=	https://distfiles.nl/

# GPLv2
# http://wrapper.tanukisoftware.com/doc/english/licenseCommunity.html
PERMIT_PACKAGE_CDROM=	Yes

EXTRACT_SUFX=	.zip

MODULES=	java
MODJAVA_VER=	1.6+
MODJAVA_BUILD=	ant

.include <bsd.port.arch.mk>
.if ${PROPERTIES:Mlp64}
BITS=64
.else
BITS=32
.endif

MODJAVA_BUILD_ARGS=-Dbits=${BITS}

WANTLIB=	c iconv m pthread

LIB_DEPENDS=	converters/libiconv

USE_GMAKE=	Yes

WRKDIST=	${WRKDIR}/${DISTNAME}/wrapper

SUBST_VARS+=	CC CFLAGS

post-extract:
	cp ${FILESDIR}/Makefile-openbsd-x86-${BITS}.gmake ${WRKSRC}/src/c/

pre-configure:
	${SUBST_CMD} ${WRKSRC}/src/c/Makefile-openbsd-x86-${BITS}.gmake

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/java/classes/  \
		${PREFIX}/lib/tanukuwrapper/
	${INSTALL_DATA} ${WRKSRC}/lib/wrapper.jar \
		${PREFIX}/share/java/classes/tanukiwrapper.jar
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libwrapper.so ${PREFIX}/lib/tanukuwrapper/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/wrapper ${PREFIX}/sbin/tanukiwrapper

do-test:
	cd ${WRKSRC} && ant -Dbits=${BITS} -f build-tests.xml

.include <bsd.port.mk>
