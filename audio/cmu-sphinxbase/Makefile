# $OpenBSD: Makefile,v 1.16 2018/02/10 09:19:48 landry Exp $

COMMENT=	common libraries for the CMU speech recognition engines

VERSION=	0.6
DISTNAME=	sphinxbase-${VERSION}
PKGNAME=	cmu-sphinxbase-${VERSION}
REVISION=	5
CATEGORIES=	audio
SHARED_LIBS= 	sphinxbase	1.0 \
		sphinxad	1.0

HOMEPAGE=	http://cmusphinx.sourceforge.net/

# CMU
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmusphinx/}

WANTLIB=	blas c iconv lapack m pthread sndio ${MODFORTRAN_WANTLIB}
MODULES=	fortran
MODFORTRAN_COMPILER = gfortran


LIB_DEPENDS=	converters/libiconv \
		math/lapack \
		${MODFORTRAN_LIB_DEPENDS}

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--without-python
CONFIGURE_ENV=		CPPFLAGS=-I${LOCALBASE}/include	\
			LDFLAGS=-L${LOCALBASE}/lib 	\
			LIBS="-lblas -lm -lgfortran -lsndio" \
			HAVE_DOXYGEN="no"

pre-build:
	@cp ${FILESDIR}/ad_sndio.c ${WRKSRC}/src/libsphinxad/

.include <bsd.port.mk>
