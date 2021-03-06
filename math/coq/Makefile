# $OpenBSD: Makefile,v 1.35 2018/05/20 08:25:36 espie Exp $

COMMENT=		proof assistant based on a typed lambda calculus

V=			8.4pl6
DISTNAME=		coq-$V
REVISION=		3

CATEGORIES=		math
HOMEPAGE=		https://coq.inria.fr/

MAINTAINER=		Yozo Toda <yozo@v007.vaio.ne.jp>

# LGPL 2.1
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB += Xrandr Xrender atk-1.0 c cairo fontconfig freetype
WANTLIB += gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gobject-2.0
WANTLIB += gtk-x11-2.0 intl m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pthread z

MASTER_SITES=	https://coq.inria.fr/distrib/V${V}/files/

MODULES=	lang/ocaml

BUILD_DEPENDS=	x11/lablgtk2 \
		lang/ocaml-camlp4 \
		sysutils/findlib
RUN_DEPENDS=	x11/lablgtk2

DESTDIRNAME=	COQINSTALLPREFIX

USE_GMAKE=	Yes

CONFIGURE_STYLE= simple
CONFIGURE_ARGS=	-emacslib ${PREFIX}/share/emacs/site-lisp \
		-makecmd ${GMAKE} \
		-prefix ${PREFIX} \
		-mandir ${PREFIX}/man \
		-configdir ${SYSCONFDIR}/xdg/coq \
		-with-doc no \
		-usecamlp4

.include <bsd.port.arch.mk>
.if ${PROPERTIES:Mocaml_native_dynlink}
CONFIGURE_ARGS+=	-opt
.else
CONFIGURE_ARGS+=	-byteonly
.endif

ALL_TARGET=		world
# Order is important!
INSTALL_TARGET=		install-byte install-ide-byte install
TEST_TARGET=		check

post-install:
	cd ${WRKDIST}; ${INSTALL_DATA} LICENSE COPYRIGHT CREDITS CHANGES \
	    COMPATIBILITY ${PREFIX}/share/doc/coq/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/coq/
	mv ${WRKINST}${SYSCONFDIR}/xdg/coq/* ${PREFIX}/share/examples/coq/
	rmdir ${WRKINST}${SYSCONFDIR}/xdg/coq/ ${WRKINST}${SYSCONFDIR}/xdg/

.include <bsd.port.mk>
