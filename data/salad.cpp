#include "salad.h"

Salad::Salad(QObject *parent) : QObject(parent)
{
    // create;
    ob_list_vegetables = new QList<Vegetable*>();

}

void Salad::setTotalCalories(double calories) {
    this->_totalCalories = calories >= 0 ? calories : 0;
}

void Salad::setTotalWeight(double weight) {
    this->_totalWeight = weight >= 0 ? weight : 0;
}

double Salad::totalCalories() {
    return this->_totalCalories;
}

double Salad::totalWeight() {
    return this->_totalWeight;
}

QList<Vegetable*>* Salad::allVegetables() {
    return ob_list_vegetables;
}

void Salad::setTitle(QString title) {
    this->_title = !title.isEmpty() ? title : "";
}

QString Salad::title() {
    return this->_title;
}
