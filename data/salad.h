#ifndef SALAD_H
#define SALAD_H

#include <QObject>
#include <QList>
#include "vegetable.h"
#include <QDebug>

class Salad : public QObject
{
    Q_OBJECT
public:
    explicit Salad(QObject *parent = 0);

    // get;

    double totalCalories();
    double totalWeight();
    QString title();
    QList<Vegetable *> *allVegetables();

    // set;

    void setTotalCalories(double calories);
    void setTotalWeight(double weight);
    void setVegetables(QList<Vegetable*> allVegetables);
    QJsonArray toJSON();
    void fromJSON(QJsonArray json);
    void setTitle(QString title);

private:

    QList<Vegetable*> *ob_list_vegetables;
    double _totalCalories;
    double _totalWeight;
    QString _title;
};

#endif // SALAD_H
