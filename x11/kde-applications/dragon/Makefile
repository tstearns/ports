# $OpenBSD: Makefile,v 1.1.1.1 2018/07/20 04:33:51 rsadowski Exp $

COMMENT =	simple video player for KDE
DISTNAME =	dragon-${VERSION}
CATEGORIES =	multimedia

KDE5 =		Yes

WANTLIB += ${COMPILER_LIBCXX} KF5Auth KF5Codecs KF5Completion
WANTLIB += KF5ConfigCore KF5ConfigGui KF5ConfigWidgets KF5CoreAddons
WANTLIB += KF5Crash KF5DBusAddons KF5I18n KF5JobWidgets KF5KIOCore
WANTLIB += KF5KIOWidgets KF5Notifications KF5Parts KF5Service
WANTLIB += KF5Solid KF5SonnetUi KF5TextWidgets KF5WidgetsAddons
WANTLIB += KF5WindowSystem KF5XmlGui Qt5Concurrent Qt5Core Qt5DBus
WANTLIB += Qt5Gui Qt5Network Qt5Widgets Qt5Xml c m

MODULES =	multimedia/phonon

BUILD_DEPENDS +=devel/gettext-tools \
		devel/kf5/kdoctools

RUN_DEPENDS =	devel/desktop-file-utils \
		misc/shared-mime-info \
		devel/kf5/kdoctools \
		x11/gtk+3,-guic

LIB_DEPENDS =	devel/kf5/kauth \
		devel/kf5/kcodecs \
		devel/kf5/kcompletion \
		devel/kf5/kconfig \
		devel/kf5/kconfigwidgets \
		devel/kf5/kcoreaddons \
		devel/kf5/kcrash \
		devel/kf5/kdbusaddons \
		devel/kf5/ki18n \
		devel/kf5/kjobwidgets \
		devel/kf5/kio \
		devel/kf5/knotifications \
		devel/kf5/kparts \
		devel/kf5/kservice \
		devel/kf5/solid \
		devel/kf5/sonnet \
		devel/kf5/ktextwidgets \
		devel/kf5/kwidgetsaddons \
		devel/kf5/kwindowsystem \
		devel/kf5/kxmlgui

TEST_IS_INTERACTIVE =	X11

.include <bsd.port.mk>
