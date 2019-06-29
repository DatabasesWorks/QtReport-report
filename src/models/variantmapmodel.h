#ifndef VARIANTMAPMODEL_H
#define VARIANTMAPMODEL_H

#include "abstractmodel.h"

LEAF_BEGIN_NAMESPACE

class VariantMapModel : public AbstractModel
{
    QVariantList _list;

public:
    VariantMapModel();

    void setSource(const QVariantList &list);

    int count() override;
    QVariant data(const QString &key) const override;
};

LEAF_END_NAMESPACE

#endif // VARIANTMAPMODEL_H
