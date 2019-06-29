/***************************************************************************
 *   QtReport                                                              *
 *   Qt Report Builder Soultion                                            *
 *                                                                         *
 *   Copyright (C) 2010 by Hamed Masafi                                    *
 *   Hamed.Masafi@GMail.COM                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "modelfilterproxy.h"
#include "reportmodel.h"

LEAF_BEGIN_NAMESPACE

void ModelFilterProxy::resetFilter()
{

}

ModelFilterProxy::ModelFilterProxy(ReportModel *model, QObject *parent)
    : QSortFilterProxyModel(parent),
      m_showConnections(true), m_showParameteres(true),
      m_showVariables(true), m_showWidgets(true)
{
    setSourceModel(model);
    setFilterRole(ReportModel::TypeRole);
    setFilterKeyColumn(0);
    setFilterRegExp("3|4|5|6");
}

bool ModelFilterProxy::showConnections() const
{
    return m_showConnections;
}

bool ModelFilterProxy::showWidgets() const
{
    return m_showWidgets;
}

bool ModelFilterProxy::showParameteres() const
{
    return m_showParameteres;
}

bool ModelFilterProxy::showVariables() const
{
    return m_showVariables;
}

void ModelFilterProxy::setShowConnections(bool showConnections)
{
    if (m_showConnections == showConnections)
        return;

    m_showConnections = showConnections;
    resetFilter();
//    emit showConnectionsChanged(m_showConnections);
}

void ModelFilterProxy::setShowWidgets(bool showWidgets)
{
    if (m_showWidgets == showWidgets)
        return;

    m_showWidgets = showWidgets;
    resetFilter();
//    emit showWidgetsChanged(m_showWidgets);
}

void ModelFilterProxy::setShowParameteres(bool showParameteres)
{
    if (m_showParameteres == showParameteres)
        return;

    m_showParameteres = showParameteres;
    resetFilter();
//    emit showParameteresChanged(m_showParameteres);
}

void ModelFilterProxy::setShowVariables(bool showVariables)
{
    if (m_showVariables == showVariables)
        return;

    m_showVariables = showVariables;
    resetFilter();
//    emit showVariablesChanged(m_showVariables);
}

bool ModelFilterProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex idx = sourceModel()->index(source_row, 0, source_parent);
    ReportModel::NodeType type = ReportModel::NodeType(sourceModel()->data(idx, ReportModel::TypeRole).toInt());

    switch (type) {
    case ReportModel::Root:
        return true;

    case ReportModel::DataConnectionsRoot:
    case ReportModel::DataConnectionItem:
    case ReportModel::DataTableItem:
    case ReportModel::FieldItem:
        return m_showConnections;

    case ReportModel::ParameteresRoot:
    case ReportModel::ParametereItem:
        return m_showParameteres;

    case ReportModel::VariablesRoot:
    case ReportModel::VariableItem:
        return m_showVariables;

    case ReportModel::WidgetsRoot:
    case ReportModel::BandItem:
    case ReportModel::WidgetBaseItem:
        return m_showWidgets;
    }
}

LEAF_END_NAMESPACE

