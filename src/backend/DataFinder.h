// Pegasus Frontend
// Copyright (C) 2017  Mátyás Mustoha
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

#include "providers/Provider.h"
#include "utils/FwdDeclModelData.h"
#include "utils/HashMap.h"

#include <QObject>
#include <QVector>
#include <memory>


class DataFinder : public QObject {
    Q_OBJECT

public:
    explicit DataFinder(QObject* parent = nullptr);

    std::vector<modeldata::Collection> find();

signals:
    void totalCountChanged(int);
    void metadataSearchStarted();

private:
    void runListProviders(HashMap<QString, modeldata::GamePtr>&,
                          HashMap<QString, modeldata::Collection>&);
    void runMetadataProviders(const HashMap<QString, modeldata::GamePtr>&,
                              const HashMap<QString, modeldata::Collection>&);

    using ProviderPtr = std::unique_ptr<providers::Provider>;
    std::vector<ProviderPtr> m_providers;

private slots:
    void onRomDirFound(QString);
};
