#ifndef REPORTPRINTER_H
#define REPORTPRINTER_H

#include "reportdata.h"

#include <QExplicitlySharedDataPointer>

class Report;
class ReportPrinter
{
public:
    ReportPrinter(Report *report);

private:
    QExplicitlySharedDataPointer<ReportPrivate> d;
};

#endif // REPORTPRINTER_H
