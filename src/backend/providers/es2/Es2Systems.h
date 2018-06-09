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

#include "utils/FwdDeclModelData.h"
#include "utils/HashMap.h"

#include <QObject>
#include <QXmlStreamReader>


namespace providers {
namespace es2 {

class SystemsParser : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(SystemsParser)

public:
    SystemsParser(QObject* parent);

    void find(HashMap<QString, modeldata::GamePtr>& games,
              HashMap<QString, modeldata::Collection>& collections);

signals:
    void gameCountChanged(int count);
    void romDirFound(QString dir_path);

private:
    void readSystemsFile(QXmlStreamReader&,
                         HashMap<QString, modeldata::GamePtr>&,
                         HashMap<QString, modeldata::Collection>&);
    void readSystemEntry(QXmlStreamReader&,
                         HashMap<QString, modeldata::GamePtr>&,
                         HashMap<QString, modeldata::Collection>&);
};

} // namespace es2
} // namespace providers
