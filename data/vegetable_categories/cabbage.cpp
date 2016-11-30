#include "cabbage.h"

Cabbage::Cabbage()
{
    this->_category = "Капустные";
}

QString Cabbage::getCategory() {
    return this->_category;
}
