#-------------------------------------------------
#
# Project created by QtCreator 2022-07-06T15:38:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = csSubway_transfer_system
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    station.cpp \
    subwaygraph.cpp \
    graphics_view_zoom.cpp \
    transferinquiryform.cpp \
    subwaymapview.cpp \
    addstationdialog.cpp \
    addlinesdialog.cpp \
    apphelpdialog.cpp \
    attractioninquirydialog.cpp \
    addialog.cpp





HEADERS += \
        mainwindow.h \
    station.h \
    line.h \
    subwaygraph.h \
    graphics_view_zoom.h \
    transferinquiryform.h \
    subwaymapview.h \
    addstationdialog.h \
    addlinesdialog.h \
    apphelpdialog.h \
    attractioninquirydialog.h \
    addialog.h




FORMS += \
        mainwindow.ui \
    transferinquiryform.ui \
    subwaymapview.ui \
    addstationdialog.ui \
    addlinesdialog.ui \
    apphelpdialog.ui \
    attractioninquirydialog.ui \
    addialog.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

