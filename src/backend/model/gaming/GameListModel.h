// Pegasus Frontend
// Copyright (C) 2017-2022  Mátyás Mustoha
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.


#pragma once

#include <QAbstractListModel>
#include <QVariantList>

namespace model { class Game; }


namespace model {
class GameListModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit GameListModel(QObject* parent = nullptr);
    GameListModel& update(std::vector<model::Game*>&&);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    const std::vector<model::Game*>& entries() const { return m_entries; }
    int count() const { return m_entries.size(); }

    Q_INVOKABLE QVariantList toVarArray() const;
    Q_INVOKABLE model::Game* get(int idx) const;

signals:
    void countChanged();

private:
    std::vector<model::Game*> m_entries;

    void onGamePropertyChanged(const QVector<int>& roles);
};
} // namespace model