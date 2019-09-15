#include "panel.h"

LEAF_BEGIN_NAMESPACE

Panel::Panel(QGraphicsItem *parent):
    Rectangle(parent)
{
    setMinimumSize(20, 20);
}

void Panel::reorderChilds()
{
    foreach(WidgetBase  *widget, _childs) {
        QPointF pt = mapToScene(widget->childPos());
        widget->setPos(pt);
    }//foreach
}

QList<WidgetBase*> Panel::childs()
{
    return _childs;
}

WidgetBase *Panel::child(int n)
{
    return _childs.at(n);
}

void Panel::appendChild(WidgetBase *child)
{
    _childs.append(child);
}

void Panel::removeChild(WidgetBase *child)
{
    _childs.removeOne(child);
}

LEAF_END_NAMESPACE
