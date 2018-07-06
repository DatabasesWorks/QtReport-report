#include "propertypagebarcode.h"

#include <QMetaEnum>

#include <widgets/barcode.h>

LEAF_BEGIN_NAMESPACE

PropertyPageBarcode::PropertyPageBarcode(QWidget *parent) :
    PropertyPageBase(parent)
{
    setupUi(this);
    _title = tr("Barcode");

    QMetaEnum e = QMetaEnum::fromType<Barcode::BarcodeType>();
    for (int i = 0; i < e.keyCount(); ++i) {
        comboBoxBarcodeType->addItem(e.key(i), e.value(i));
    }
}

void PropertyPageBarcode::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void PropertyPageBarcode::load()
{
    int type = _designer->widgetProperty("barcodeType").toInt();
    comboBoxBarcodeType->setCurrentIndex(comboBoxBarcodeType->findData(type));
    spinBox->setValue(_designer->widgetProperty("whitespace").toInt());
}

void PropertyPageBarcode::save()
{
    _designer->setWidgetProperty("barcodeType", comboBoxBarcodeType->currentData().toInt());
    _designer->setWidgetProperty("whitespace", spinBox->value());
}

LEAF_END_NAMESPACE
