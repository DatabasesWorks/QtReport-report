#include "barcode.h"

#include <QFontDatabase>

LEAF_BEGIN_NAMESPACE

Barcode::Barcode(QGraphicsItem *parent) : Rectangle(parent)
{
    QFontDatabase::addApplicationFont(":/fonts/code-39");
    setText("123456789");
}

void Barcode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QString t = "*" + m_text + "*";
    Rectangle::paint(painter, option, widget);
    QFont font("Code-39-Logitogo");
    QFontMetrics metrics(font);
    qreal w = width() / metrics.width(t);
    qreal h = height() / metrics.height();
    font.setPointSizeF(font.pointSizeF() * qMin(w, h));
    painter->setFont(font);
    painter->setPen(Qt::black);
    painter->drawText(boundingRect(), t, QTextOption(Qt::AlignCenter));
}

QString Barcode::text() const
{
    return m_text;
}

void Barcode::setText(QString text)
{
    m_text = text;
}

LEAF_END_NAMESPACE
