#-------------------------------------------------
#
# Project created by QtCreator 2013-07-31T16:02:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myMdi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mdichild.cpp

HEADERS  += mainwindow.h \
    mdichild.h

FORMS    += mainwindow.ui
