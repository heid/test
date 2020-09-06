#-------------------------------------------------
#
# Project created by QtCreator 2020-08-30T09:50:27
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp \
    imagethread.cpp \
    tcpworker.cpp

HEADERS  += server.h \
    imagethread.h \
    tcpworker.h

FORMS    += server.ui
