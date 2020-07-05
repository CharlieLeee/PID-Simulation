#-------------------------------------------------
#
# Project created based on QCustomplot examples
#
#-------------------------------------------------

QT       += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PID-sim
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp \
    pid/pid_incremental.cpp \
    pid/pid_position.cpp

HEADERS  += mainwindow.h \
         qcustomplot.h \
    pid/pid_incremental.h \
    pid/pid_position.h \
    ordersystem.h \
    pid/matlabpid.h

FORMS    += mainwindow.ui

