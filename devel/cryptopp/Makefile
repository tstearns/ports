# $OpenBSD: Makefile,v 1.21 2018/01/21 20:25:48 juanfra Exp $

COMMENT = 	C++ library of cryptographic algorithms
CATEGORIES = 	devel security

HOMEPAGE = 	http://www.cryptopp.com/
MASTER_SITES = 	${HOMEPAGE}
DISTNAME = 	cryptopp565
PKGNAME = 	cryptopp-5.6.5
REVISION =      2

EXTRACT_SUFX = 	.zip
WRKDIST = 	${WRKDIR}

MAINTAINER =	David Coppa <dcoppa@openbsd.org>

# individual files are public domain
# compilation is licensed under the Boost Software License 1.0
PERMIT_PACKAGE_CDROM = 		Yes

WANTLIB +=	m pthread ${COMPILER_LIBCXX}

SHARED_LIBS = 	cryptopp	4.0

USE_GMAKE = 	Yes
MAKE_FLAGS +=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -Wno-unused \
			-DCRYPTOPP_DISABLE_SSSE3 \
			-DCRYPTOPP_DISABLE_AESNI \
			-DCRYPTOPP_NO_UNALIGNED_DATA_ACCESS \
			-DNDEBUG -fPIC" \
		LDFLAGS="-lpthread" \
		PREFIX=${PREFIX} \
		LIBcryptopp_VERSION=${LIBcryptopp_VERSION}

MAKE_FILE = 	${WRKDIR}/GNUmakefile

TEST_FLAGS += WRKDIST=${WRKDIST}

pre-patch:
	@cd ${WRKSRC}; perl -i -pe 's/\r$$//' `find . -type f`

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/cryptopp
	${INSTALL_DATA} ${WRKDIR}/*.h ${PREFIX}/include/cryptopp
	${INSTALL_DATA} ${WRKDIR}/libcryptopp.{a,so.${LIBcryptopp_VERSION}} \
		${PREFIX}/lib
	${SUBST_DATA} ${FILESDIR}/cryptopp.pc \
		${PREFIX}/lib/pkgconfig/cryptopp.pc

.include <bsd.port.mk>
