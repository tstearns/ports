# $OpenBSD: Makefile,v 1.46 2018/07/01 18:33:38 espie Exp $

COMMENT =	libraries for KDE PIM services
DISTNAME =	kdepimlibs-4.14.10
REVISION =	6

DPB_PROPERTIES =	parallel

MASTER_SITES =	${MASTER_SITE_KDE:=Attic/applications/15.04.3/src/}

SHARED_LIBS =	kabc                 54.0      # .4.0
SHARED_LIBS +=	kabc_file_core       54.0      # .4.0
SHARED_LIBS +=	kalarmcal	     54.0      # 2.7
SHARED_LIBS +=	kcal                 54.0      # .4.0
SHARED_LIBS +=	kldap                54.0      # .4.0
SHARED_LIBS +=	kmime                54.0      # .4.0
SHARED_LIBS +=	kresources           54.0      # .4.0
SHARED_LIBS +=	ktnef                54.0      # .4.0
SHARED_LIBS +=	kxmlrpcclient        54.0      # .4.0
SHARED_LIBS +=	syndication          54.0      # .1.0
SHARED_LIBS +=	kblog                54.0      # .4.0
SHARED_LIBS +=	kimap                54.0      # .4.0
SHARED_LIBS +=	kpimidentities       54.0      # .4.0
SHARED_LIBS +=	kpimutils            54.0      # .4.0
SHARED_LIBS +=	mailtransport        54.0      # .4.0
SHARED_LIBS +=	akonadi-contact	     54.0      # .4.4
SHARED_LIBS +=	akonadi-kabc	     54.0      # .4.4
SHARED_LIBS +=	akonadi-kcal	     54.0      # .4.4
SHARED_LIBS +=	akonadi-kde	     54.0      # .4.4
SHARED_LIBS +=	akonadi-kmime	     54.0      # .4.4
SHARED_LIBS +=	akonadi-notes	     54.0      # 4.7
SHARED_LIBS +=	kholidays	     54.0      # .4.4
SHARED_LIBS +=	kontactinterface     54.0      # .4.4
SHARED_LIBS +=	kpimtextedit	     54.0      # .4.4
SHARED_LIBS +=	microblog	     54.0      # .4.4

SHARED_LIBS +=  akonadi-calendar	54.0 # 4.7
SHARED_LIBS +=  kcalcore		54.0 # 4.7
SHARED_LIBS +=  kcalutils		54.0 # 4.7
SHARED_LIBS +=  kmbox			54.0 # 4.7

SHARED_LIBS +=  akonadi-socialutils	54.0 # 4.10

SHARED_LIBS +=	akonadi-xml		2.0  # 4.13

SHARED_LIBS +=  qgpgme4                   0.0 # 1.0
SHARED_LIBS +=  gpgme4++-pthread          0.0 # 2.8
SHARED_LIBS +=  gpgme4++                  0.0 # 2.8

WANTLIB =  c m pthread
WANTLIB += ${COMPILER_LIBCXX}
WANTLIB += lib/qt4/QtDBus lib/qt4/QtGui lib/qt4/QtNetwork lib/qt4/QtSql
WANTLIB += lib/qt4/QtSvg lib/qt4/QtXml
WANTLIB += ${KDE4LIB}/kcmutils ${KDE4LIB}/kdeui ${KDE4LIB}/kemoticons
WANTLIB += ${KDE4LIB}/kio ${KDE4LIB}/kparts ${KDE4LIB}/nepomuk
WANTLIB += ${KDE4LIB}/nepomukutils ${KDE4LIB}/solid
WANTLIB += akonadiprotocolinternals assuan uuid gpg-error gpgme
WANTLIB += ical icalss iconv intl lber ldap prison qjson sasl2
WANTLIB += soprano xml2

MODULES =	multimedia/phonon

MODKDE4_USE =	libs

BUILD_DEPENDS =	devel/boost \
		misc/shared-mime-info \
		misc/shared-desktop-ontologies>=0.10

RUN_DEPENDS =	misc/shared-mime-info \
		misc/shared-desktop-ontologies>=0.10

LIB_DEPENDS =	databases/openldap \
		devel/qjson \
		graphics/prison \
		productivity/akonadi>=${MIN_AKONADI_VERSION} \
		security/cyrus-sasl2 \
		security/gpgme>=0.4.5 \
		sysutils/e2fsprogs>=1.42.7 \
		textproc/libical \
		textproc/libxml

TEST_IS_INTERACTIVE =	X11

# XXX Until issues with similar names for test targets are resolved.
NO_TEST =	Yes

post-extract:
	cp ${FILESDIR}/*.cmake ${WRKDIST}/cmake/modules

.include <bsd.port.mk>
