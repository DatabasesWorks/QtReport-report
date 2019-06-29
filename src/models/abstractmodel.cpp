#include "abstractmodel.h"

LEAF_BEGIN_NAMESPACE

int AbstractModel::index() const
{
    return _index;
}

void AbstractModel::setIndex(int index)
{
    _index = index;
}

AbstractModel::AbstractModel() : _index(0)
{

}

bool AbstractModel::moveNext()
{
    if (_index < count() - 1)
        _index++;
    return true;
}

LEAF_END_NAMESPACE
