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
    enum SortingBy {
        Name, Calories, Weight
    };

    TableManager();

    static QJsonArray toJSON(Table *table);
    static Table *fromJSON(QJsonArray json);
    static void sortTable(Table *table, SortingBy sortingMode, bool toMax);
};

#endif // TABLEMANAGER_H
