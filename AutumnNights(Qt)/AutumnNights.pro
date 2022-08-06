TEMPLATE = app
TARGET = AutumnNights

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    canvas.cpp \
    coordinate.cpp \
    grid3d.cpp \
    main.cpp \
    tile.cpp \
    window.cpp

HEADERS += \
    canvas.h \
    coordinate.h \
    grid3d.h \
    tile.h \
    window.h
