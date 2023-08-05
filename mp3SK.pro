QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia
CONFIG += c++17 qsa

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtlocalpeer.cpp \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtlockedfile.cpp \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtlockedfile_unix.cpp \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtlockedfile_win.cpp \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtsingleapplication.cpp \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtsinglecoreapplication.cpp \
    main.cpp \
    mainwindow.cpp \
    playlist.cpp \

HEADERS += \
    ../../libs/qt-solutions-master/qtsingleapplication/src/QtLockedFile \
    ../../libs/qt-solutions-master/qtsingleapplication/src/QtSingleApplication \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtlocalpeer.h \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtlockedfile.h \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtsingleapplication.h \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtsinglecoreapplication.h \
    main.h \
    mainwindow.h \
    playlist.h \



FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    mp3SK_uk_UA.ts
CONFIG += lrelease
CONFIG += embed_translations
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtsingleapplication.pri \
    ../../libs/qt-solutions-master/qtsingleapplication/src/qtsinglecoreapplication.pri \
    ./resource/background.png \
    ./resource/cursor.png \
    ./resource/nexts.png \
    ./resource/pause.png \
    ./resource/play.png \
    ./resource/preds.png \
    resource/pointer.png \
    resource/slider.png \
    slider.qss \
    soundSlider.qss

INCLUDEPATH += ..\..\libs\qt-solutions-master\qtsingleapplication\src
INCLUDEPATH += ./resource
