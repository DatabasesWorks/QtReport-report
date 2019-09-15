#ifndef REPORTDATA_H
#define REPORTDATA_H

#include "qtreportglobal.h"

#include <QExplicitlySharedDataPointer>
#include <QMap>
#include <QSizeF>

LEAF_BEGIN_NAMESPACE

class AbstractModel;
class Report;
class Band;
class WidgetBase;
class DataConnection;
class DataTable;
class Parametere;
class ReportModel;
class ReportPrivate : public QSharedData
{
public:
    ReportPrivate(Report *parent);

    QList<Band*>           bands;
    QList<WidgetBase*>     widgets;
    QList<DataConnection*> connections;

    qreal marginLeft;
    qreal marginBottom;
    qreal marginTop;
    qreal marginRight;

    QSizeF pageSize;

    QString filePath;

    QList<DataTable*> tables;
    QList<Parametere*> parameters;

    ReportModel *model;
    QMap<QString, AbstractModel*> models;
};

LEAF_END_NAMESPACE

#endif // REPORTDATA_H
