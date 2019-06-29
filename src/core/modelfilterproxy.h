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

#ifndef MODELFILTERPROXY_H
#define MODELFILTERPROXY_H

#include "qtreportglobal.h"
#include <QSortFilterProxyModel>

LEAF_BEGIN_NAMESPACE

class ReportModel;
class ModelFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT

    Q_PROPERTY(bool showConnections READ showConnections WRITE setShowConnections NOTIFY showConnectionsChanged)
    Q_PROPERTY(bool showWidgets READ showWidgets WRITE setShowWidgets NOTIFY showWidgetsChanged)
    Q_PROPERTY(bool showParameteres READ showParameteres WRITE setShowParameteres NOTIFY showParameteresChanged)
    Q_PROPERTY(bool showVariables READ showVariables WRITE setShowVariables NOTIFY showVariablesChanged)

    bool m_showConnections;
    bool m_showWidgets;
    bool m_showParameteres;
    bool m_showVariables;

    void resetFilter();

public:
    ModelFilterProxy(ReportModel *model, QObject *parent = nullptr);
    bool showConnections() const;
    bool showWidgets() const;
    bool showParameteres() const;
    bool showVariables() const;

public slots:
    void setShowConnections(bool showConnections);
    void setShowWidgets(bool showWidgets);
    void setShowParameteres(bool showParameteres);
    void setShowVariables(bool showVariables);

signals:
    void showConnectionsChanged(bool showConnections);
    void showWidgetsChanged(bool showWidgets);
    void showParameteresChanged(bool showParameteres);
    void showVariablesChanged(bool showVariables);

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const Q_DECL_OVERRIDE;
};

LEAF_END_NAMESPACE

#endif // MODELFILTERPROXY_H
