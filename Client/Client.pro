#-------------------------------------------------
#
# Project created by QtCreator 2020-08-30T09:51:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    saveimagethread.cpp

HEADERS  += client.h \
    saveimagethread.h

FORMS    += client.ui
