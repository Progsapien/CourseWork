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

Salad* SaladManager::fromJSON(QJsonObject json) {
    Salad *new_salad = new Salad;
    QString vegetable_name;
    new_salad->setTitle(json.value("title").toString());

    foreach(QJsonValue value, json["vegetables"].toArray()) {
        vegetable_name = value.toObject()["title"].toString();
        qDebug() << vegetable_name;
        if(vegetable_name == "Помидор") {
            Tomato *vegetable = new Tomato;
            vegetable->fromJSON(value.toObject());
            SaladManager::addVegetable(new_salad, vegetable);
            qDebug() << "PP " << new_salad->allVegetables()->count();
        } else if(vegetable_name == "...") {
            // ..... !!!!
        }

    }
    return new_salad;
}

double SaladManager::totalCalories(Salad *salad) {
    double calories = 0;

    for(int i = 0; i < salad->allVegetables()->count(); i++) {
        calories += salad->allVegetables()->at(i)->calories();
    }

    return calories;
}

double SaladManager::totalWeight(Salad *salad) {
    double weight = 0;

    for(int i = 0; i < salad->allVegetables()->count(); i++) {
        weight += salad->allVegetables()->at(i)->weight();
    }

    return weight;
}

void SaladManager::addVegetable(Salad *salad, Vegetable *vegetable) {
    salad->allVegetables()->append(vegetable);
}
