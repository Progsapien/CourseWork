#include "cruciferous.h"

Cruciferous::Cruciferous()
{
    this->_category = "Капустные";
}

QString Cruciferous::getCategory() {
    return this->_category;
}
