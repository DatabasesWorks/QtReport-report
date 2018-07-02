#ifndef MODELTREEVIEW_H
#define MODELTREEVIEW_H

#include <QTreeView>
#include "qtreportglobal.h"

class QMenu;

LEAF_BEGIN_NAMESPACE

class DocumentDesigner;
class Report;
class ModelTreeView : public QTreeView
{
    Q_OBJECT
    Report *_report;
    QMenu *menu;
    bool m_enableDrag;

    QAction *actionNew;
    QAction *actionEdit;
    QAction *actionDelete;

    DocumentDesigner *_designer;

    int _selectedType;

public:
    ModelTreeView(QWidget *parent = Q_NULLPTR);
    ModelTreeView(Report *report, QWidget *parent = Q_NULLPTR);
    ModelTreeView(Report *report, DocumentDesigner *designer, QWidget *parent = Q_NULLPTR);

    // QWidget interface
    bool enableDrag() const;
    void setEnableDrag(bool enableDrag);

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void setupUi();

    // QAbstractItemView interface
protected slots:
    void currentChanged(const QModelIndex &current, const QModelIndex &previous) Q_DECL_OVERRIDE;
    void on_actionNew_triggered();
    void on_actionEdit_triggered();
    void on_actionDelete_triggered();

};

LEAF_END_NAMESPACE

#endif // MODELTREEVIEW_H
