#include "tablemanager.h"

TableManager::TableManager()
{

}

void TableManager::fromJSON(QJsonArray json) {

}

QJsonArray TableManager::toJSON(Table *table) {
    QJsonArray json;
    for(int i = 0; i < table->getSalads()->count(); i++) {
        json.append(SaladManager::toJSON(table->getSalads()->at(i)));
    }
    return json;
}
