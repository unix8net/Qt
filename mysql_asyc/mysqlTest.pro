#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T10:56:53
#
#-------------------------------------------------

QT       += core gui sql
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
LIBS += -L"D:\Qt\Qt5.2.1\5.2.1\msvc2012\lib"
TARGET = mysqlTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    sql.cpp\
    sqlthread.cpp

HEADERS  += mainwindow.h\
    sql.h\
    sqlthread.h

FORMS    += mainwindow.ui
