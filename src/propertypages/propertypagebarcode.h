#ifndef PROPERTYPAGEBARCODE_H
#define PROPERTYPAGEBARCODE_H

#include "propertypages/propertypagebase.h"
#include "ui_propertypagebarcode.h"

LEAF_BEGIN_NAMESPACE

class PropertyPageBarcode : public PropertyPageBase, private Ui::PropertyPageBarcode
{
    Q_OBJECT

public:
    explicit PropertyPageBarcode(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);

    // PropertyPageBase interface
public:
    void load() Q_DECL_OVERRIDE;
    void save() Q_DECL_OVERRIDE;
};

LEAF_END_NAMESPACE

#endif // PROPERTYPAGEBARCODE_H
