#include "tablemanager.h"

TableManager::TableManager()
{

}

Table* TableManager::fromJSON(QJsonArray json) {
    Table *new_table = new Table;
    if(json.count() != 0) {
        Salad *salad;

        foreach (QJsonValue json_array, json) {
            salad = SaladManager::fromJSON(json_array.toObject());
            qDebug() << "SALAD TITLE " << salad->title();
            qDebug() << "SALAD VEGETABLES COUNT" << salad->allVegetables()->count();
            new_table->getSalads()->append(salad);
        }
        qDebug() << new_table->getSalads()->at(0)->allVegetables()->count();
    }
    return new_table;
}

QJsonArray TableManager::toJSON(Table *table) {
    QJsonArray json;
    for(int i = 0; i < table->getSalads()->count(); i++) {
        json.append(SaladManager::toJSON(table->getSalads()->at(i)));
    }
    return json;
}
