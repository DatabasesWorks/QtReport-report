#include "sqlquerymodel.h"

LEAF_BEGIN_NAMESPACE

SqlQueryModel::SqlQueryModel() : AbstractModel()
{

}

void SqlQueryModel::setSource(const QSqlQuery &query)
{
    _query = query;
}

int SqlQueryModel::count()
{
    return _query.size();
}

QVariant SqlQueryModel::data(const QString &key) const
{
    return _query.value(key);
}

bool SqlQueryModel::moveNext()
{
    AbstractModel::moveNext();
    return _query.next();
}

LEAF_END_NAMESPACE
