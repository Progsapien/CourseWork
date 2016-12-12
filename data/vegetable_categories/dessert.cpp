#include "dessert.h"

Dessert::Dessert()
{
    this->_category = "Дессертные";
}

QString Dessert::getCategory() {
    return this->_category;
}
