#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H

#include "abstractmodel.h"

#include <QSqlQuery>

LEAF_BEGIN_NAMESPACE

class SqlQueryModel : public AbstractModel
{
    QSqlQuery _query;

public:
    SqlQueryModel();
    void setSource(const QSqlQuery &query);

    int count();
    QVariant data(const QString &key) const;

    bool moveNext();
};

LEAF_END_NAMESPACE

#endif // SQLQUERYMODEL_H
