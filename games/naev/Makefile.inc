# $OpenBSD: Makefile.inc,v 1.10 2018/04/26 09:10:08 kirby Exp $

VERSION = 		0.7.0

CATEGORIES = 		games x11

HOMEPAGE = 		http://blog.naev.org/

MAINTAINER = 		Kirill Bychkov <kirby@openbsd.org>

# GPLv3, GPLv2+, CC-by, CC-by-sa 3.0
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES = 		${MASTER_SITE_SOURCEFORGE:=naev/}
DIST_SUBDIR = 		naev
