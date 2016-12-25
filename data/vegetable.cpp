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

QJsonObject Vegetable::toJSON() {
    QJsonObject json;
    json["weight"] = this->_weight;
    json["calories"] = this->_calories;
    json["title"] = this->_title;
    json["icon"] = this->_icon;
    return json;
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

void Vegetable::setIcon(QString iconPath) {
    this->_icon = !iconPath.isEmpty() ? iconPath : "";
}

void Vegetable::fromJSON(QJsonObject json) {
    this->_calories = json["calories"].toDouble();
    this->_icon = json["icon"].toString();
    this->_title = json["title"].toString();
    this->_weight = json["weight"].toDouble();
}

QString Vegetable::icon() {
    return this->_icon;
}

Vegetable::~Vegetable() {

}
