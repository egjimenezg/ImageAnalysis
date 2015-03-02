#-------------------------------------------------
#
# Project created by QtCreator 2015-03-01T15:31:34
#
#-------------------------------------------------
QMAKE_MAC_SDK = macosx10.9

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Decompression
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    qcustomplot.cpp \
    histogram.cpp

HEADERS  += mainwindow.h \
    image.h \
    qcustomplot.h \
    histogram.h

FORMS    += mainwindow.ui
