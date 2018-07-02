SOURCES += main.cpp
TEMPLATE = app

QT += sql xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

INCLUDEPATH += ../../src

win32{
    LIBS += ../../src/debug/QtReport.lib
    RC_FILE = win.rc
}
unix{
    LIBS +=  ../../src/libQtReport.a
    TARGETDEPS += ../../src/libQtReport.a
}

