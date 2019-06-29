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
#    LIBS +=  ../../3rdparty/zint/backend_qt/libQtZint.a
    LIBS += -lpng
#    DEFINES += QZINT_LIBRARY
    TARGETDEPS += ../../src/libQtReport.a
}

