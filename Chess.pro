#-------------------------------------------------
#
# Project created by QtCreator 2012-04-20T22:59:25
#
#-------------------------------------------------

QT       += core gui

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        qgameplace.cpp \
    qboardplace.cpp \
    qboard.cpp \
    qcell.cpp

HEADERS  += qgameplace.h \
    qboardplace.h \
    qboard.h \
    qcell.h

FORMS    += qgameplace.ui

RESOURCES = res.qrc
