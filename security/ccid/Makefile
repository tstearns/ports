# $OpenBSD: Makefile,v 1.27 2017/06/06 14:58:58 dcoppa Exp $

COMMENT =	USB Chip/Smart Card Interface Devices driver

DISTNAME =	ccid-1.4.27

CATEGORIES =	security

HOMEPAGE =	http://pcsclite.alioth.debian.org/ccid.html

MASTER_SITES =	https://alioth.debian.org/frs/download.php/latestfile/112/

EXTRACT_SUFX =	.tar.bz2

MAINTAINER =	David Coppa <dcoppa@openbsd.org>

# LGPLv2.1+ and GPLv2+
PERMIT_PACKAGE_CDROM=   Yes

WANTLIB =	pcsclite pthread usb-1.0

LIB_DEPENDS =	devel/libusb1 \
		security/pcsc-lite>=1.8.3


CONFIGURE_STYLE = gnu

CONFIGURE_ARGS = --enable-twinserial

CONFIGURE_ENV =	ac_cv_lib_lex='none needed'

NO_TEST =	Yes

.include <bsd.port.mk>
