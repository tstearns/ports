# $OpenBSD: Makefile,v 1.27 2018/05/12 10:00:24 espie Exp $

COMMENT=	audio file volume normalizer

DISTNAME=	normalize-0.7.7
REVISION=	3
CATEGORIES=	audio

MASTER_SITES=	${MASTER_SITE_SAVANNAH:=normalize/}

HOMEPAGE=	http://normalize.nongnu.org/

MAINTAINER=	Vlad Glagolev <stealth@sourcemage.org>

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	c iconv intl m mad>=2 audiofile FLAC ogg

LIB_DEPENDS=	audio/libmad \
		devel/gettext \
		devel/libaudiofile

CONFIGURE_STYLE= gnu

CONFIGURE_ARGS=	--with-mad \
		--with-audiofile

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MODGNU_CONFIG_GUESS_DIRS=${WRKSRC}/config

.include <bsd.port.mk>
