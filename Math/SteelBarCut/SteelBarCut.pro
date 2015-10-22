#-------------------------------------------------
#
# Project created by QtCreator 2013-09-07T17:04:17
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = SteelBarCut
CONFIG   += console
CONFIG   -= app_bundle
CONFIG +=c++11

TEMPLATE = app


SOURCES += main.cpp \
    barpart.cpp \
    solver.cpp

HEADERS += \
    barpart.h \
    solver.h
