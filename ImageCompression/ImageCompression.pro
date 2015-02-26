#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T18:13:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageCompression
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    node.cpp \
    huffmantree.cpp

HEADERS  += mainwindow.h \
    image.h \
    huffmantree.h \
    node.h

FORMS    += mainwindow.ui
