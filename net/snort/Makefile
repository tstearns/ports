# $OpenBSD: Makefile,v 1.99 2018/01/28 03:09:12 lteo Exp $

COMMENT =		highly flexible sniffer/NIDS

VERSION =		2.9.11.1
DISTNAME =		snort-${VERSION}

CATEGORIES =		net security

HOMEPAGE =		https://www.snort.org/

MAINTAINER =		Markus Lude <markus.lude@gmx.de>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c crypto daq dnet lzma m nghttp2 pcap pcre pthread z

MASTER_SITES =		https://www.snort.org/downloads/snort/

SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--disable-static-daq \
			--enable-non-ether-decoders

LIB_DEPENDS =		archivers/xz \
			devel/pcre \
			net/daq \
			net/libdnet \
			www/nghttp2

CONFIGS	=		classification.config gen-msg.map reference.config \
			snort.conf threshold.conf unicode.map

PREPROC =		decoder.rules preprocessor.rules

DOCS =			AUTHORS CREDITS README README.* *.pdf TODO USAGE \
			WISHLIST

V =			${VERSION:S/.//g}
SUBST_VARS +=		V

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/etc/snort.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/snort
.for i in ${CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/share/examples/snort
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/generators ${PREFIX}/share/examples/snort

.for i in ${PREPROC}
	${INSTALL_DATA} ${WRKSRC}/preproc_rules/${i} ${PREFIX}/share/examples/snort
.endfor

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/snort
.endfor

NO_TEST =		Yes

.include <bsd.port.mk>
