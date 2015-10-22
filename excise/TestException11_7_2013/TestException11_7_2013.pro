#-------------------------------------------------
#
# Project created by QtCreator 2013-11-07T18:08:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = TestException11_7_2013
CONFIG   += console
CONFIG   -= app_bundle
CONFIG +=c++11

TEMPLATE = app


SOURCES += main.cpp \
    catcher.cpp \
    fileerror.cpp \
    fileopenerror.cpp \
    myexception.cpp

HEADERS += \
    catcher.h \
    fileerror.h \
    fileopenerror.h \
    myexception.h
