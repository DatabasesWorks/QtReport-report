TEMPLATE = lib
TARGET = QtReport
CONFIG += staticlib

QT += sql xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

contains(CONFIG,zint){
    message(zint)
    ZINT_PATH=$$PWD/../3rdparty/zint/
    INCLUDEPATH += $$ZINT_PATH/backend $$ZINT_PATH/backend_qt
    DEPENDPATH += $$ZINT_PATH/backend $$ZINT_PATH/backend_qt
    LIBS += -lpng
    DEFINES += QZINT_LIBRARY
    LIBS += -L$${DEST_LIBS} -lQtZint
}

TRANSLATIONS = ../translations/qtreport_en.ts \
               ../translations/qtreport_fa.ts

INCLUDEPATH += \
    $$PWD/designer \
    $$PWD/core \
    $$PWD/propertypages

SOURCES +=  \
    core/reportprinter.cpp \
    designer/databaseinfodialog.cpp \
    designer/databasetablesdialog.cpp \
    core/datatable.cpp \
    designer/colorpicker.cpp \
    designer/designeraboutdialog.cpp \
    designer/designerfactory.cpp \
    designer/designerwindow.cpp \
    designer/documentdesigner.cpp \
    models/abstractmodel.cpp \
    models/sqlquerymodel.cpp \
    models/variantmapmodel.cpp \
    widgets/displaybase.cpp \
    designer/docpage.cpp \
    designer/documentview.cpp \
    core/parametere.cpp \
    designer/parameteredialog.cpp \
    propertypages/propertydialog.cpp \
    propertypages/propertypagealign.cpp \
    propertypages/propertypagebarcode.cpp \
    propertypages/propertypagebase.cpp \
    propertypages/propertypagefont.cpp \
    propertypages/propertypageformat.cpp \
    propertypages/propertypageimage.cpp \
    propertypages/propertypagelinetype.cpp \
    propertypages/propertypagepage.cpp \
    propertypages/propertypagepos.cpp \
    propertypages/propertypagerectangle.cpp \
    propertypages/propertypagerichtext.cpp \
    propertypages/propertypagetext.cpp \
    propertypages/propertypagewidget.cpp \
    propertypages/sectiondataproperties.cpp \
    propertypages/sectionsproperties.cpp \
    designer/querybuilderdialog.cpp \
    core/report.cpp \
    designer/ruler.cpp \
    designer/scene.cpp \
    typehelper.cpp \
    designer/undocommands.cpp \
    designer/widgetresizer.cpp \
    widgets/horizontalline.cpp \
    widgets/image.cpp \
    widgets/linebase.cpp \
    widgets/panel.cpp \
    widgets/rectanglebase.cpp \
    widgets/textbox.cpp \
    widgets/verticalline.cpp \
    widgets/widget.cpp \
    widgets/widgetbase.cpp \
    core/dataconnection.cpp \
    designer/datatabledialog.cpp \
    designer/newconnectionwizard.cpp \
    propertypages/propertyband.cpp \
    propertypages/propertyfilter.cpp \
    propertypages/propertysort.cpp \
    widgets/band.cpp \
    core/reportprintsettings.cpp \
    core/reportmodel.cpp \
    designer/seriazbleobject.cpp \
    designer/modeltreeview.cpp \
    core/variable.cpp \
    widgets/barcode.cpp \
    propertypages/propertypagebarcode.cpp \
    core/modelfilterproxy.cpp

HEADERS +=  \
    core/reportdata.h \
    core/reportprinter.h \
    designer/colorpicker.h \
    designer/databaseinfodialog.h \
    designer/databasetablesdialog.h \
    core/dataconnection.h \
    core/datatable.h \
    designer/datatabledialog.h \
    designer/designeraboutdialog.h \
    designer/designerfactory.h \
    designer/designerwindow.h \
    designer/documentdesigner.h \
    models/abstractmodel.h \
    models/sqlquerymodel.h \
    models/variantmapmodel.h \
    widgets/displaybase.h \
    designer/docpage.h \
    designer/documentview.h \
    core/event.h \
    designer/newconnectionwizard.h \
    core/parametere.h \
    designer/parameteredialog.h \
    propertypages/propertyband.h \
    propertypages/propertydialog.h \
    propertypages/propertyfilter.h \
    propertypages/propertypagealign.h \
    propertypages/propertypagebarcode.h \
    propertypages/propertypagebase.h \
    propertypages/propertypagefont.h \
    propertypages/propertypageformat.h \
    propertypages/propertypageimage.h \
    propertypages/propertypagelinetype.h \
    propertypages/propertypagepage.h \
    propertypages/propertypagepos.h \
    propertypages/propertypagerectangle.h \
    propertypages/propertypagerichtext.h \
    propertypages/propertypagetext.h \
    propertypages/propertypagewidget.h \
    propertypages/propertysort.h \
    propertypages/sectiondataproperties.h \
    propertypages/sectionsproperties.h \
    QtReport \
    qtreportglobal.h \
    designer/querybuilderdialog.h \
    core/report.h \
    designer/ruler.h \
    designer/scene.h \
    typehelper.h \
    designer/undocommands.h \
    designer/widgetresizer_p.h \
    widgets/band.h \
    widgets/horizontalline.h \
    widgets/image.h \
    widgets/linebase.h \
    widgets/panel.h \
    widgets/rectanglebase.h \
    widgets/textbox.h \
    widgets/verticalline.h \
    widgets/widget.h \
    widgets/widgetbase.h \
    core/reportprintsettings.h \
    core/reportmodel.h \
    designer/seriazbleobject.h \
    designer/modeltreeview.h \
    core/variable.h \
    widgets/barcode.h \
    propertypages/propertypagebarcode.h \
    core/modelfilterproxy.h

FORMS += \
    designer/databaseinfodialog.ui \
    designer/databasetablesdialog.ui \
    designer/datatabledialog.ui \
    designer/designeraboutdialog.ui \
    designer/designerwindow.ui \
    designer/newconnectionwizard.ui \
    designer/parameteredialog.ui \
    propertypages/propertyband.ui \
    propertypages/propertyfilter.ui \
    propertypages/propertypagealign.ui \
    propertypages/propertypagebarcode.ui \
    propertypages/propertypagefont.ui \
    propertypages/propertypageformat.ui \
    propertypages/propertypageimage.ui \
    propertypages/propertypagepage.ui \
    propertypages/propertypagepos.ui \
    propertypages/propertypagerectangle.ui \
    propertypages/propertypagerichtext.ui \
    propertypages/propertypagewidget.ui \
    propertypages/propertysort.ui \
    propertypages/sectiondataproperties.ui \
    propertypages/sectionsproperties.ui \
    designer/querybuilderdialog.ui \
    propertypages/propertypagetext.ui \
    propertypages/propertybarcode.ui \
    propertypages/propertypagebarcode.ui

OTHER_FILES += \
    main.dox

RESOURCES += \
    resources.qrc \
    win_resource.qrc \
    linux_resource.qrc \
    mac_resource.qrc
