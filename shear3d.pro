QT = core gui widgets opengl

TARGET = shear3d
TEMPLATE = app


SOURCES = \
    main.cpp \
    gui/MainWindow.cpp \
    core/Stl.cpp \
    core/Polyline.cpp \
    core/Cut.cpp \
    core/Test.cpp \
    core/Vertices.cpp \
    core/Triangle.cpp \
    tests/test_1.cpp \
    core/Line.cpp \
    tests/test_2.cpp

HEADERS = \
    gui/MainWindow.h \
    gui/MainWindow.h \
    core/Stl.h \
    core/Polyline.h \
    core/Cut.h \
    core/Test.h \
    core/Vertices.h \
    core/Triangle.h \
    tests/test_1.h \
    core/Line.h \
    tests/test_2.h

INCLUDEPATH = \
    core\
    gui\
    tests\

