#-------------------------------------------------
#
# Project created by QtCreator 2014-09-09T10:55:56
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = vernam
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    vernam.cpp \
    aleatorios.cpp

HEADERS += \
    funciones.h \
    vernam.h \
    archivo.h \
    aleatorios.h

OTHER_FILES += \
    ../build-vernam-Desktop_Qt_5_3_MinGW_32bit-Debug/key.vern
