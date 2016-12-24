#include "salad.h"

Salad::Salad(QObject *parent) : QObject(parent)
{
    // create;
    ob_list_vegetables = new QList<Vegetable*>();

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
