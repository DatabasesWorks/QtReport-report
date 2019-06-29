#include "variantmapmodel.h"

LEAF_BEGIN_NAMESPACE

VariantMapModel::VariantMapModel()
{

}

void VariantMapModel::setSource(const QVariantList &list)
{
    _list = list;
}

int VariantMapModel::count()
{
    return _list.count();
}

QVariant VariantMapModel::data(const QString &key) const
{
    return _list.at(index()).toMap().value(key);
}

LEAF_END_NAMESPACE
