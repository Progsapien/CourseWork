#include "saladmanager.h"

SaladManager::SaladManager(QObject *parent) : QObject(parent)
{

}

QJsonObject SaladManager::toJSON(Salad *salad) {
    QJsonObject json_object;
    QJsonArray json_array;

    json_object.insert("title",salad->title());

    for(int i = 0; i < salad->allVegetables()->count(); i++) {
        json_array.append(salad->allVegetables()->at(i)->toJSON());
    }

    json_object.insert("vegetables",json_array);
   // qDebug() << json_object;
    return json_object;
}

Salad* SaladManager::fromJSON(QJsonArray json) {
    Salad *new_salad = new Salad;
    QJsonArray array;

    foreach (QJsonValue value, json) {
        if(value.isArray()) {
            array = value.toArray();
            foreach (QJsonValue object, array) {
                if(object.isObject()) {
                    //qDebug() << object.toObject().value("title").toString();
                }
            }
        }
    }
    return new Salad;
}

void SaladManager::addVegetable(Salad *salad, Vegetable *vegetable) {
    salad->allVegetables()->append(vegetable);
}
