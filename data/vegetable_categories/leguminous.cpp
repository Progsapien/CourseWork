#include "leguminous.h"

Leguminous::Leguminous()
{
    this->_category = "Бобовые";
}

QString Leguminous::getCategory() {
    return this->_category;
}
