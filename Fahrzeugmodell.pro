TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        statemachine.cpp \
        vehicle.cpp

HEADERS += \
    statemachine.h \
    vehicle.h
