#ifndef SALADMANAGER_H
#define SALADMANAGER_H

#include <QObject>
#include "../data/salad.h"
#include "../data/vegetables/tomato.h"
#include <QJsonObject>
#include <QJsonArray>

class SaladManager : public QObject
{
    Q_OBJECT
public:
    explicit SaladManager(QObject *parent = 0);

    static void addVegetable(Salad *salad, Vegetable *vegetable);
    static void deleteVegetable(Salad *salad, Vegetable *vegetable);
    static QJsonObject toJSON(Salad *salad);
    static Salad *fromJSON(QJsonArray json);
};

#endif // SALADMANAGER_H
