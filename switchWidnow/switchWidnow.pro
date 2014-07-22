QT += widgets core gui

TARGET = switchWidnow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cwidgeta.cpp \
    cwidgetb.cpp

HEADERS  += mainwindow.h \
    cwidgeta.h \
    cwidgetb.h

FORMS    += mainwindow.ui \
    cwidgetb.ui \
    cwidgeta.ui
