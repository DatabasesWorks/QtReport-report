#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <QVariant>
#include "../qtreportglobal.h"

LEAF_BEGIN_NAMESPACE

class AbstractModel
{
    int _index;

protected:
    int index() const;
    void setIndex(int index);
public:
    AbstractModel();
    virtual ~AbstractModel() = default;

    virtual int count() = 0;
    virtual QVariant data(const QString &key) const = 0;
    virtual bool moveNext();
};

LEAF_END_NAMESPACE

#endif // ABSTRACTMODEL_H
