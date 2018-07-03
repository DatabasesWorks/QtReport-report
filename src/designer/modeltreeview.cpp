#include "modeltreeview.h"
#include "report.h"
#include "documentdesigner.h"

#include <QtWidgets/QMenu>
#include <QtCore/QDebug>
#include <QtGui/QMouseEvent>
#include <QDrag>
#include <QApplication>
#include <QMimeData>

#include "reportmodel.h"

LEAF_BEGIN_NAMESPACE

ModelTreeView::ModelTreeView(QWidget *parent) : QTreeView(parent)
{
    setupUi();
}

ModelTreeView::ModelTreeView(Report *report, QWidget *parent)
    : QTreeView(parent), _report(report)
{
    setModel(_report->model());
    setupUi();
}

ModelTreeView::ModelTreeView(Report *report, DocumentDesigner *designer, QWidget *parent)
    : QTreeView(parent), _report(report), _designer(designer)
{
    setModel(_report->model());
    setupUi();
}
void ModelTreeView::mousePressEvent(QMouseEvent *event)
{
    QTreeView::mousePressEvent(event);
    qApp->processEvents();

    if (event->button() == Qt::RightButton) {
        ReportModel::NodeType type = ReportModel::NodeType(
                    currentIndex().data(ReportModel::TypeRole).toInt());
        _selectedType = int(type);
        bool showMenu = true;

        switch (type) {
        case ReportModel::DataConnectionsRoot:
        case ReportModel::ParameteresRoot:
        case ReportModel::WidgetsRoot:
            actionNew->setVisible(true);
            actionEdit->setVisible(false);
            break;

        case ReportModel::DataConnectionItem:
            actionEdit->setVisible(true);
            actionNew->setVisible(true);
            actionDelete->setVisible(true);
            break;

        case ReportModel::DataTableItem:
        case ReportModel::ParametereItem:
            actionEdit->setVisible(true);
            actionNew->setVisible(false);
            break;

        case ReportModel::BandItem:
        case ReportModel::WidgetBaseItem:
            actionNew->setVisible(false);
            actionEdit->setVisible(false);
            break;

        default:
            showMenu = false;
        }

        if (showMenu)
            menu->exec(event->globalPos());
    } else if (event->button() == Qt::LeftButton) {
        ReportModel::NodeType type = ReportModel::NodeType(
                    currentIndex().data(ReportModel::TypeRole).toInt());

        if (m_enableDrag &&
                (type == ReportModel::ParametereItem
                 || type == ReportModel::VariableItem)) {
            QMimeData *mimeData = new QMimeData();
            mimeData->setText(QString("{%1}").arg(currentIndex()
                                                  .data(Qt::DisplayRole)
                                                  .toString()));

            QDrag *drag = new QDrag(this);
            drag->setMimeData(mimeData);

            drag->exec(Qt::CopyAction);
        }
    }
}

void ModelTreeView::setupUi()
{
    setHeaderHidden(true);

    menu = new QMenu(this);

    actionNew = new QAction(tr("New"), this);
    actionNew->setObjectName("actionNewConnection");
    actionNew->setIcon(QIcon(":/designer/add"));

    actionEdit= new QAction(tr("Edit"), this);
    actionEdit->setObjectName("actionEditConnection");
    actionEdit->setIcon(QIcon(":/designer/edit"));

    actionDelete= new QAction(tr("Delete"), this);
    actionDelete->setObjectName("actionDeleteConnection");
    actionDelete->setIcon(QIcon(":/designer/delete"));

    QAction *actionExpandAll = new QAction(tr("Expand all"), this);
    actionExpandAll->setObjectName("actionExpandAll");
    actionExpandAll->setIcon(QIcon(":/designer/expand"));

    QAction *actionCollapseAll = new QAction(tr("Collapse all"), this);
    actionCollapseAll->setObjectName("actionCollapseAll");
    actionCollapseAll->setIcon(QIcon(":/designer/collapse"));

    menu->addAction(actionNew);
    menu->addAction(actionEdit);
    menu->addAction(actionDelete);
    menu->addSeparator();
    menu->addAction(actionExpandAll);
    menu->addAction(actionCollapseAll);

    connect(actionNew, &QAction::triggered, this, &ModelTreeView::on_actionNew_triggered);
    connect(actionEdit, &QAction::triggered, this, &ModelTreeView::on_actionEdit_triggered);
    connect(actionDelete, &QAction::triggered, this, &ModelTreeView::on_actionDelete_triggered);
    connect(actionExpandAll, &QAction::triggered, this, &QTreeView::expandAll);
    connect(actionCollapseAll, &QAction::triggered, this, &QTreeView::collapseAll);
}

void ModelTreeView::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    if (!current.isValid())
        return;
}

void ModelTreeView::on_actionNew_triggered()
{
    switch (ReportModel::NodeType(_selectedType)) {
    case ReportModel::DataConnectionsRoot:
        _designer->addDataConnection();
        break;
    case ReportModel::DataConnectionItem:
        _designer->addDataTable(currentIndex().data(ReportModel::TextRole).toString());
        break;
    case ReportModel::ParameteresRoot:
        _designer->addParametere();
        break;
    }
}

void ModelTreeView::on_actionEdit_triggered()
{
    switch (ReportModel::NodeType(_selectedType)) {
    case ReportModel::DataTableItem:
        _designer->editDataTable(currentIndex().data(ReportModel::TextRole).toString());
        break;
    }
}

void ModelTreeView::on_actionDelete_triggered()
{

}



bool ModelTreeView::enableDrag() const
{
    return m_enableDrag;
}

void ModelTreeView::setEnableDrag(bool enableDrag)
{
    m_enableDrag = enableDrag;
}

LEAF_END_NAMESPACE

