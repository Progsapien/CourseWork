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

void TableManager::sortTable(Table *table, SortingBy sortingMode, bool toMax) {
    if(sortingMode == Calories) {
        qSort(table->getSalads()->begin(), table->getSalads()->end(), [toMax](Salad *salad1, Salad *salad2) {
            if(toMax) {
                return SaladManager::totalCalories(salad1) < SaladManager::totalCalories(salad2);
            }
            return SaladManager::totalCalories(salad1) > SaladManager::totalCalories(salad2);
        });
    } else if(sortingMode == Weight) {
        qSort(table->getSalads()->begin(), table->getSalads()->end(), [toMax](Salad *salad1, Salad *salad2) {
            if(toMax) {
                return SaladManager::totalWeight(salad1) < SaladManager::totalWeight(salad2);
            }
            return SaladManager::totalWeight(salad1) > SaladManager::totalWeight(salad2);
        });
    } else if(sortingMode == Name) {
        qSort(table->getSalads()->begin(), table->getSalads()->end(), [toMax](Salad *salad1, Salad *salad2) {
            if(toMax) {
                return salad2->title().compare(salad1->title()) > 0;
            }
            return salad2->title().compare(salad1->title()) < 0;
        });
    }
}
