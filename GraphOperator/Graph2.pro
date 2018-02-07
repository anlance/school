#-------------------------------------------------
#
# Project created by QtCreator 2018-01-01T18:56:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graph2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    dialog.cpp \
    graph.cpp

HEADERS  += widget.h \
    dialog.h \
    graph.h

FORMS    += widget.ui \
    dialog.ui

RESOURCES += \
    image.qrc
