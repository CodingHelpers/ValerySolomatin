TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS="-O0 -std=c++98 -Wall -Wextra -pedantic"

SOURCES += main.cpp

HEADERS += \
    stack.hpp \
    fastsort.hpp
