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
    data/vegetable_categories/cabbage.cpp \
    data/vegetable_categories/salad.cpp \
    data/vegetable_categories/tomatos.cpp

HEADERS  += ui/ui.h \
    data/vegetable.h \
    data/vegetable_categories/cabbage.h \
    data/vegetable_categories/salad.h \
    data/vegetable_categories/tomatos.h
