#ifndef TOMATOS_H
#define TOMATOS_H

#include "../vegetable.h"

class Tomatos : public Vegetable
{
public:
    Tomatos();

    QString getCategory();
protected:
    QString _category;
};

#endif // TOMATOS_H
