#ifndef BARCODE_H
#define BARCODE_H

#include "rectanglebase.h"

LEAF_BEGIN_NAMESPACE

class Barcode : public Rectangle
{
    Q_OBJECT
    REGISTER_PROPERTY_PAGE(text)
    REGISTER_PROPERTY_PAGE(align)

    Q_PROPERTY( QString text READ text WRITE setText DESIGNABLE true USER true )

    QString m_text;

public:
    Barcode(QGraphicsItem *parent = nullptr);

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QString text() const;
public slots:
    void setText(QString text);
};

LEAF_END_NAMESPACE

#endif // BARCODE_H
