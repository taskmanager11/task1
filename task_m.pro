#-------------------------------------------------
#
# Project created by QtCreator 2015-02-07T14:20:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_m
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    My1.cpp \
    taskmodel.cpp \
    Task_entity.cpp

HEADERS  += mainwindow.h \
    My1.h \
    Task_entity.h \
    taskmodel.h

FORMS    += mainwindow.ui
