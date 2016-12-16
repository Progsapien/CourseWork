#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T19:17:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chef
TEMPLATE = app


SOURCES += main.cpp\
    ui/ui.cpp \
    data/vegetable.cpp \
    data/vegetable_categories/salad.cpp \
    data/vegetable_categories/tomatos.cpp \
    data/vegetable_categories/leguminous.cpp \
    data/vegetables/tomato.cpp \
    data/vegetable_categories/dessert.cpp \
    data/vegetable_categories/cruciferous.cpp \
    ui/login.cpp \
    ui/button.cpp \
    ui/mainui.cpp

HEADERS  += ui/ui.h \
    data/vegetable.h \
    data/vegetable_categories/salad.h \
    data/vegetable_categories/tomatos.h \
    data/vegetable_categories/leguminous.h \
    data/vegetables/tomato.h \
    data/vegetable_categories/dessert.h \
    data/vegetable_categories/cruciferous.h \
    ui/login.h \
    ui/button.h \
    libusb.h \
    ui/mainui.h

RESOURCES += \
    resources.qrc
