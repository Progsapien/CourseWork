#include "salad.h"

Salad::Salad()
{
    this->_category = "Салатные";
}

QString Salad::getCategory() {
    return this->_category;
}
