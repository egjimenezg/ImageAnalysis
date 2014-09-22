#-------------------------------------------------
#
# Project created by QtCreator 2014-09-07T18:22:12
#
#-------------------------------------------------

QMAKE_MAC_SDK = macosx10.9

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Histograma
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    image.cpp \
    histogram.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    image.h \
    histogram.h

FORMS    += mainwindow.ui
