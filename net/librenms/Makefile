# $OpenBSD: Makefile,v 1.69 2018/07/01 21:49:17 sthen Exp $

COMMENT =	auto-discovering network management/monitoring system

GH_ACCOUNT =	librenms
GH_PROJECT =	librenms
GH_TAGNAME =	1.41
DISTFILES =	librenms-${GH_TAGNAME}.tar.gz librenms-vendor-${GH_TAGNAME}.tar.xz:0
EPOCH =		0

CATEGORIES =	net www

HOMEPAGE =	https://www.librenms.org/

MAINTAINER =	Stuart Henderson <sthen@openbsd.org>

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES0 =	https://spacehopper.org/mirrors/

MODULES =	lang/php \
		lang/python
MODPY_BUILDDEP = No

RUN_DEPENDS =	databases/py-mysql \
		lang/php/${MODPHP_VERSION},-curl \
		lang/php/${MODPHP_VERSION},-gd \
		lang/php/${MODPHP_VERSION},-mcrypt \
		lang/php/${MODPHP_VERSION},-mysqli \
		lang/php/${MODPHP_VERSION},-pdo_mysql \
		lang/php/${MODPHP_VERSION},-snmp \
		net/fping \
		net/mtr \
		net/net-snmp \
		net/nmap \
		net/rrdtool \
		shells/bash \
		sysutils/ipmitool

NO_BUILD =	Yes
NO_TEST =	Yes

PKG_ARCH =	*

PREFIX =	/var/www
INSTDIR =	${PREFIX}/librenms
SUBST_VARS =	INSTDIR MODPHP_BIN

R =	s,^\#!( )?(/usr/bin/env |/bin/)bash,\#!${LOCALBASE}/bin/bash,;
R +=	s,^\#!( )?/usr/bin/(env )?python.*,\#!${MODPY_BIN},;
R +=	s,/usr/bin/(env )?php,${MODPHP_BIN},g;
R +=	s,/opt/librenms,/var/www/librenms,g;
R +=	s,/var/www/librenms,${TRUEPREFIX}/librenms,g;
R +=	s,/usr/local,${LOCALBASE},g

post-extract:
	mv ${WRKDIR}/vendor ${WRKSRC}/
	perl -pi \
	    -e "s,'/usr/bin/snmp,'/usr/local/bin/snmp,;" \
	    -e "s,'/bin/ping,'/sbin/ping,;" \
	    -e "s,'/usr/bin/(mtr|nmap|ipmitool|virsh|dot|sfdp)','/usr/local/bin/\1',;" \
	    -e "s,'/usr/lib/nagios/plugins,'/usr/local/libexec/nagios/plugins,;" \
	    ${WRKSRC}/includes/defaults.inc.php
	find ${WRKSRC} -type f -print0 | xargs -r0 perl -pi -e '$R'
	sed -i \
	    -e 's, librenms *, _librenms ,' \
	    -e 's,/var/www/librenms/cronic,-n,' \
	    ${WRKSRC}/librenms.nonroot.cron

do-configure:
	${SUBST_CMD} ${WRKSRC}/.env.example

do-install:
	${INSTALL_DATA_DIR} ${INSTDIR}
	cd ${WRKSRC}; pax -rw . ${INSTDIR}
	find ${INSTDIR} -name '*.orig' -delete
	mkdir -p ${INSTDIR}/{rrd,logs}
	cd ${INSTDIR}; \
	   sed -i 's,%PHP%,${MODPHP_BIN},' daily.sh *-wrapper.py *-service.py validate.php LibreNMS/Validations/Php.php html/includes/output/capture.inc.php scripts/composer_wrapper.php; \
	   sed -i 's,%LNMS_VERSION%,${DISTNAME:S/librenms-//},' includes/common.php
	cp /usr/share/snmp/mibs/OPENBSD-* ${INSTDIR}/mibs/
	rm -rf ${INSTDIR}/tests ${INSTDIR}/vendor/xjtuwangke/passwordhash/.git

# maintainer convenience target
dist: /usr/ports/distfiles/librenms-${GH_TAGNAME}.tar.gz
	t=`mktemp -d /tmp/librenms.XXXXXXXXXX`; \
	f=$$t/librenms-vendor-${GH_TAGNAME}.tar.xz; \
	cd $$t; \
	tar xzf ${FULLDISTDIR}/${DISTNAME}.tar.gz; \
	cd librenms-${GH_TAGNAME}; \
	[ -r .env ] || cp .env.example .env; \
	composer install --no-dev; \
	tar cf - vendor | xz -T 0 > $$f; \
	scp $$f naiad:mirrors/; \
	cd -; rm -rf $$t

.include <bsd.port.mk>
