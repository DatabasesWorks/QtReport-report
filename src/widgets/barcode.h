#ifndef BARCODE_H
#define BARCODE_H

#include "rectanglebase.h"

LEAF_BEGIN_NAMESPACE

class Barcode : public Rectangle
{
    Q_OBJECT
    REGISTER_PROPERTY_PAGE(text)
    REGISTER_PROPERTY_PAGE(align)
    REGISTER_PROPERTY_PAGE(barcode)

    Q_PROPERTY(QString text READ text WRITE setText  NOTIFY textChanged DESIGNABLE true USER true)
    Q_PROPERTY(BarcodeType barcodeType READ barcodeType WRITE setBarcodeType NOTIFY barcodeTypeChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int whitespace READ whitespace WRITE setWhitespace NOTIFY whitespaceChanged)

public:
    Barcode(QGraphicsItem *parent = nullptr);

    enum BarcodeType {
        CODE11 = 1,
        C25MATRIX = 2,
        C25INTER = 3,
        C25IATA = 4,
        C25LOGIC = 6,
        C25IND = 7,
        CODE39 = 8,
        EXCODE39 = 9,
        EANX = 13,
        EANX_CHK = 14,
        EAN128 = 16,
        CODABAR = 18,
        CODE128 = 20,
        DPLEIT = 21,
        DPIDENT = 22,
        CODE16K = 23,
        CODE49 = 24,
        CODE93 = 25,
        FLAT = 28,
        RSS14 = 29,
        RSS_LTD = 30,
        RSS_EXP = 31,
        TELEPEN = 32,
        UPCA = 34,
        UPCA_CHK = 35,
        UPCE = 37,
        UPCE_CHK = 38,
        POSTNET = 40,
        MSI_PLESSEY = 47,
        FIM = 49,
        LOGMARS = 50,
        PHARMA = 51,
        PZN = 52,
        PHARMA_TWO = 53,
        PDF417 = 55,
        PDF417TRUNC = 56,
        MAXICODE = 57,
        QRCODE = 58,
        CODE128B = 60,
        AUSPOST = 63,
        AUSREPLY = 66,
        AUSROUTE = 67,
        AUSREDIRECT = 68,
        ISBNX = 69,
        RM4SCC = 70,
        DATAMATRIX = 71,
        EAN14 = 72,
        VIN = 73,
        CODABLOCKF = 74,
        NVE18 = 75,
        JAPANPOST = 76,
        KOREAPOST = 77,
        RSS14STACK = 79,
        RSS14STACK_OMNI = 80,
        RSS_EXPSTACK = 81,
        PLANET = 82,
        MICROPDF417 = 84,
        ONECODE = 85,
        PLESSEY = 86,

        /* Tbarcode 8 codes */
        TELEPEN_NUM = 87,
        ITF14 = 89,
        KIX = 90,
        AZTEC = 92,
        DAFT = 93,
        MICROQR = 97,

        /* Tbarcode 9 codes */
        HIBC_128 = 98,
        HIBC_39 = 99,
        HIBC_DM = 102,
        HIBC_QR = 104,
        HIBC_PDF = 106,
        HIBC_MICPDF = 108,
        HIBC_BLOCKF = 110,
        HIBC_AZTEC = 112,

        /* Tbarcode 10 codes */
        DOTCODE = 115,
        HANXIN = 116,

        /*Tbarcode 11 codes*/
        MAILMARK = 121,

        /* Zint specific */
        AZRUNE = 128,
        CODE32 = 129,
        EANX_CC = 130,
        EAN128_CC = 131,
        RSS14_CC = 132,
        RSS_LTD_CC = 133,
        RSS_EXP_CC = 134,
        UPCA_CC = 135,
        UPCE_CC = 136,
        RSS14STACK_CC = 137,
        RSS14_OMNI_CC = 138,
        RSS_EXPSTACK_CC = 139,
        CHANNEL = 140,
        CODEONE = 141,
        GRIDMATRIX = 142,
        UPNQR = 143,
    };
    Q_ENUM(BarcodeType)

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QString text() const;
    BarcodeType barcodeType() const;

    QColor color() const;

    int whitespace() const;

public slots:
    void setText(QString text);
    void setBarcodeType(BarcodeType type);
    void setColor(QColor color);

    void setWhitespace(int whitespace);

signals:
    void barcodeTypeChanged(BarcodeType type);
    void textChanged(QString text);
    void colorChanged(QColor color);

    void whitespaceChanged(int whitespace);

private:
    QString m_text;
    BarcodeType m_type;
    QColor m_color;
    int m_whitespace;
};

LEAF_END_NAMESPACE

#endif // BARCODE_H
