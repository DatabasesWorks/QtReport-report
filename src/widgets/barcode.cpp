#include "barcode.h"

#include <QDebug>
#ifdef QZINT_LIBRARY
#include <../3rdparty/zint/backend_qt/qzint.h>
#endif

LEAF_BEGIN_NAMESPACE

Barcode::Barcode(QGraphicsItem *parent) : Rectangle(parent), m_type(CODE39)
{
    setText("123456789");
}

void Barcode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Rectangle::paint(painter, option, widget);

#ifdef QZINT_LIBRARY
    Zint::QZint bc;
    bc.setText(m_text);
    bc.setInputMode(UNICODE_MODE);
    bc.setSymbol(m_type);
    bc.setWhitespace(m_whitespace);
    bc.setFgColor(Qt::black);
    bc.setBgColor(Qt::transparent);
    bc.setWidth(width());
    bc.setSecurityLevel(0);
    bc.setPdf417CodeWords(928);

    bc.render(*painter, rect(false), Zint::QZint::KeepAspectRatio);
#endif
}

QString Barcode::text() const
{
    return m_text;
}

Barcode::BarcodeType Barcode::barcodeType() const
{
    return m_type;
}

QColor Barcode::color() const
{
    return m_color;
}

int Barcode::whitespace() const
{
    return m_whitespace;
}

void Barcode::setText(QString text)
{
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(m_text);
    update();
}

void Barcode::setBarcodeType(Barcode::BarcodeType type)
{
    if (m_type == type)
        return;

    m_type = type;
    emit barcodeTypeChanged(m_type);
}

void Barcode::setColor(QColor color)
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged(m_color);
}

void Barcode::setWhitespace(int whitespace)
{
    if (m_whitespace == whitespace)
        return;

    m_whitespace = whitespace;
    emit whitespaceChanged(m_whitespace);
}

LEAF_END_NAMESPACE
