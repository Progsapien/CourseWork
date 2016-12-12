#ifndef DESSERT_H
#define DESSERT_H

#include "../vegetable.h"

class Dessert : public Vegetable
{
public:
    Dessert();

    QString getCategory();

private:
    QString _category;
};

#endif // DESSERT_H
