SUBDIRS += src \
 tools/QtReportDesigner

TEMPLATE = subdirs 
CONFIG += warn_on \
          qt \
          thread 

#contains(CONFIG, zint){
#    SUBDIRS += 3rdparty/zint/backend_qt
#}
