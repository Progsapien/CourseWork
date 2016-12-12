#include "tomatos.h"

Tomatos::Tomatos()
{
    this->_category = "Томатные";
}

QString Tomatos::getCategory() {
    return this->_category;
}
