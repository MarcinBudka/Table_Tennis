TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        bloczek.cpp \
        element_sceny.cpp \
        licznik.cpp \
        main.cpp \
        paletka.cpp \
        pila.cpp \
        scena.cpp \
        trybb.cpp

HEADERS += \
    bloczek.h \
    element_sceny.h \
    licznik.h \
    paletka.h \
    pila.h \
    scena.h \
    trybb.h
