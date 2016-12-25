#include "bulbous.h"

Bulbous::Bulbous()
{
    this->_category = "Луковичные";
}

QString Bulbous::getCategory() {
    return this->_category;
}
