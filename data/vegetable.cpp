#include "data/vegetable.h"

Vegetable::Vegetable()
{
    this->_weight = 0;
    this->_calories = 0;
    this->_title = "";
}

// get

double Vegetable::weight() {
    return this->_weight;
}

double Vegetable::calories() {
    return this->_calories;
}

QString Vegetable::title() {
    return this->_title;
}



// set

void Vegetable::setCalories(double calories) {
    this->_calories = calories > -1 ? calories : 0;
}

void Vegetable::setWeight(double weight) {
    this->_weight = weight > -1 ? weight : 0;
}

void Vegetable::setTitle(QString title) {
    this->_title = !title.isEmpty() ? title : "";
}

Vegetable::~Vegetable() {

}
