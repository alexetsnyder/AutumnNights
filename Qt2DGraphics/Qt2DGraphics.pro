TEMPLATE = app
TARGET = Qt2DGraphics

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    canvas.cpp \
    main.cpp \
    window.cpp

HEADERS += \
    canvas.h \
    window.h
