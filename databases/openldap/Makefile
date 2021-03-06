# $OpenBSD: Makefile,v 1.163 2018/06/30 11:41:36 landry Exp $

DPB_PROPERTIES =	parallel

COMMENT-main =		open-source LDAP software (client)
COMMENT-server =	open-source LDAP software (server)

DISTNAME =		openldap-2.4.46
PKGNAME-main =		${DISTNAME:S/-/-client-/}
PKGNAME-server =	${DISTNAME:S/-/-server-/}

# overwrite -main pkgname/path to strip FLAVOR, aci only affects the server
FULLPKGNAME-main =	${DISTNAME:S/-/-client-/}${FLAVOR_EXT:S/-aci//}
FULLPKGPATH-main =	databases/openldap,-main${FLAVOR_EXT:S/-aci//:S/-/,/g}

SHARED_LIBS +=	lber                 12.0     # 12.6
SHARED_LIBS +=	lber-2.4             12.0

SHARED_LIBS +=	ldap                 13.1     # 12.6
SHARED_LIBS +=	ldap-2.4             13.1
SHARED_LIBS +=	ldap_r               13.1
SHARED_LIBS +=	ldap_r-2.4           13.1

CATEGORIES =	databases net

HOMEPAGE =	http://www.openldap.org/

MAINTAINER =	Stuart Henderson <sthen@openbsd.org>

# OpenLDAP Public License
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c crypto ssl

MASTER_SITES =	http://mirror.switch.ch/ftp/mirror/OpenLDAP/openldap-release/ \
		http://mirror.aarnet.edu.au/pub/openldap/openldap-release/ \
		ftp://ftp.OpenLDAP.org/pub/OpenLDAP/openldap-release/ \
		http://ftp.ntua.gr/mirror/OpenLDAP/openldap-release/

# patches to enable writemap for MDB tests; fairly intrusive so keeping them out of patches/
MASTER_SITES0 =	https://spacehopper.org/mirrors/
PATCHFILES =	openldap-2.4.45-mdb-tests.diff:0

EXTRACT_SUFX =		.tgz

SEPARATE_BUILD =	Yes
AUTOCONF_VERSION =	2.65
CONFIGURE_STYLE =	autoconf

FLAVOR ?=
FLAVORS =		aci gssapi

CONFIGURE_ARGS +=	--enable-ipv6 \
			--with-tls=openssl

# slapd options
CONFIGURE_ARGS +=	--enable-slapd \
			--enable-cleartext \
			--enable-crypt \
			--enable-rewrite \
			--with-cyrus-sasl \
			--enable-spasswd

# slapd modules
CONFIGURE_ARGS +=	--enable-bdb \
			--enable-dnssrv \
			--enable-hdb \
			--enable-ldap \
			--enable-meta \
			--enable-monitor \
			--enable-null \
			--enable-overlays \
			--enable-passwd \
			--enable-perl \
			--enable-shell

# Enable MDB support, however note patch-servers_slapd_back-mdb_init_c.
#
# MDB normally assumes that the filesystem and buffer cache are unified
# (i.e. a file can be opened normally and mmap()'d, with changes to one
# being reflected to the other). But as Howard Chu says, "This requirement
# can be relaxed in the current version of the library. If you create
# the environment with the MDB_WRITEMAP option then all reads and writes
# are performed using mmap, so the file buffer cache is irrelevant. Of
# course then you lose the protection that the read-only map offers."
#
# Therefore, the patch rejects an MDB configuration in which writemap
# has not been set.
#
CONFIGURE_ARGS +=	--enable-mdb

.if ${FLAVOR:Maci}
CONFIGURE_ARGS +=	--enable-aci
.endif

.if ${FLAVOR:Mgssapi}
CONFIGURE_ARGS +=	--enable-gssapi=${LOCALBASE}/heimdal
MODULES += security/heimdal
WANTLIB += heimdal/lib/gssapi
WANTLIB += heimdal/lib/heimntlm
WANTLIB += heimdal/lib/heimsqlite
.endif

MODGNU_CONFIG_GUESS_DIRS = ${WRKSRC} ${WRKSRC}/build

TEST_TARGET =		test
TEST_DEPENDS =		shells/bash

MULTI_PACKAGES =	-main -server

# formatting is ok with mandoc, but soelim is used at build time
BUILD_DEPENDS +=	textproc/groff
LIB_DEPENDS +=		security/cyrus-sasl2 
WANTLIB +=		pthread sasl2
CPPFLAGS +=		-I${LOCALBASE}/include/sasl

LIB_DEPENDS-server =	${LIB_DEPENDS-main} \
			sysutils/e2fsprogs \
			textproc/icu4c \
			databases/db/v4,no_java,no_tcl

CONFIGURE_ENV +=	CPPFLAGS="-I${LOCALBASE}/include/sasl -I${LOCALBASE}/include/db4 -I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib/db4 -L${LOCALBASE}/lib"

RUN_DEPENDS-server =	databases/openldap,-main
WANTLIB-server +=	${WANTLIB} perl m icudata icuuc uuid
WANTLIB-server +=	${COMPILER_LIBCXX} lib/db4/db>=4

pre-build:
	@cd ${WRKBUILD}; ${MAKE_PROGRAM} depend

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openldap
	${INSTALL_DATA} ${DESTDIR}${SYSCONFDIR}/openldap/*.conf \
		${PREFIX}/share/examples/openldap
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openldap/schema
	${INSTALL_DATA} ${DESTDIR}${SYSCONFDIR}/openldap/schema/*.schema \
		 ${PREFIX}/share/examples/openldap/schema
	${INSTALL_DATA} ${WRKSRC}/servers/slapd/DB_CONFIG \
		${PREFIX}/share/examples/openldap
	@rm -rf ${DESTDIR}${SYSCONFDIR}/openldap

pre-test:
	sed -i 's,^#!/bin/bash,#!${LOCALBASE}/bin/bash,' ${WRKSRC}/tests/scripts/test064-constraint

.include <bsd.port.mk>
