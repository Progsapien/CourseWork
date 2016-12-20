#include "salads.h"

Salads::Salads()
{
    this->_category = "Салатные";
}

QString Salads::getCategory() {
    return this->_category;
}
