# $OpenBSD: Makefile,v 1.6 2018/04/26 13:06:01 jasper Exp $

COMMENT =	perl-compatible regular expression library, version 2

DISTNAME =	pcre2-10.31

SHARED_LIBS +=  pcre2-16                  0.1 # 3.0
SHARED_LIBS +=  pcre2-32                  0.1 # 3.0
SHARED_LIBS +=  pcre2-8                   0.2 # 3.0
SHARED_LIBS +=  pcre2-posix               0.1 # 0.1

CATEGORIES =	devel

MASTER_SITES =	http://ftp.csx.cam.ac.uk/pub/software/programming/pcre/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/

HOMEPAGE =	http://www.pcre.org/

# BSD
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += bz2 c curses readline z

LIB_DEPENDS =		archivers/bzip2

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--enable-pcre2-16 \
			--enable-pcre2-32 \
			--enable-newline-is-any \
			--enable-pcre2grep-libz \
			--enable-pcre2grep-libbz2 \
			--enable-pcre2test-libreadline
# explicitly disable JIT that would require WXNEEDED
CONFIGURE_ARGS +=	--disable-jit
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
