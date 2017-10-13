QT += core
QT -= gui

TARGET = testcv
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
LIBS += -L/root/sources/opencv-2-4-9-1/build/__install/lib/  -lopencv_core  -lopencv_highgui  -lopencv_objdetect -lopencv_imgproc -lopencv_ml -lopencv_video
QMAKE_LFLAGS+="-Wl,--rpath=/root/sources/opencv-2-4-9-1/build/__install/lib/"
HEADERS += \
    test.h

