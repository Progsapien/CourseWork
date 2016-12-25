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
    data/vegetable_categories/tomatos.cpp \
    data/vegetables/tomato.cpp \
    data/vegetable_categories/dessert.cpp \
    ui/login.cpp \
    ui/button.cpp \
    managers/saladmanager.cpp \
    ui/saladbutton.cpp \
    data/salad.cpp \
    data/table.cpp \
    ui/tableui.cpp \
    ui/addui.cpp \
    managers/profilemanager.cpp \
    managers/tablemanager.cpp \
    ui/saladinfoui.cpp \
    ui/vegetablesui.cpp \
    ui/vegetablecreatorui.cpp \
    data/vegetables/asparagus.cpp \
    data/vegetable_categories/bulbous.cpp \
    data/vegetables/bow.cpp \
    data/vegetables/garlic.cpp \
    data/vegetable_categories/pumpkin.cpp \
    data/vegetables/cucumber.cpp \
    data/vegetables/gourd.cpp

HEADERS  += ui/ui.h \
    data/vegetable.h \
    data/vegetable_categories/tomatos.h \
    data/vegetables/tomato.h \
    data/vegetable_categories/dessert.h \
    ui/login.h \
    ui/button.h \
    managers/saladmanager.h \
    ui/saladbutton.h \
    data/salad.h \
    data/table.h \
    ui/tableui.h \
    ui/addui.h \
    managers/profilemanager.h \
    managers/tablemanager.h \
    ui/saladinfoui.h \
    ui/vegetablesui.h \
    ui/vegetablecreatorui.h \
    data/vegetables/asparagus.h \
    data/vegetable_categories/bulbous.h \
    data/vegetables/bow.h \
    data/vegetables/garlic.h \
    data/vegetable_categories/pumpkin.h \
    data/vegetables/cucumber.h \
    data/vegetables/gourd.h

RESOURCES += \
    resources.qrc
