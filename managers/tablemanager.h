#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include "../data/table.h"
#include "saladmanager.h"

class TableManager
{
public:
    TableManager();

    static QJsonArray toJSON(Table *table);
    static Table *fromJSON(QJsonArray json);
};

#endif // TABLEMANAGER_H
