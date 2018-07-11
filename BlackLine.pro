#-------------------------------------------------
#
# Project created by QtCreator 2018-07-01T19:36:51
#
#-------------------------------------------------

QT       += core gui
QT       += xml
TARGET = BlackLine
TEMPLATE = app


SOURCES += main.cpp\
        blackline.cpp \
    scriptcreator.cpp \
    runningthread.cpp \
    runnerman.cpp

HEADERS  += blackline.h \
    scriptcreator.h \
    runningthread.h \
    runnerman.h

FORMS    += blackline.ui

RESOURCES += \
    img.qrc

OTHER_FILES += \
    rsc/auto.xml \
    rsc/x86.exe \
    rsc/x64.exe \
    rsc/system.xml \
    rsc/other.xml \
    rsc/network.xml \
    rsc/memory.xml \
    rsc/disk.xml \
    rsc/ramBackup.xml



















