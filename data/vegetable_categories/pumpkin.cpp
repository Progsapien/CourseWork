#include "pumpkin.h"

Pumpkin::Pumpkin()
{
    this->_category = "Тыквенные";
}

QString Pumpkin::getCategory() {
    return this->_category;
}
