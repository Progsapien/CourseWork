#ifndef LEGUMINOUS_H
#define LEGUMINOUS_H

#include "../vegetable.h"

class Bulbous : public Vegetable
{
public:
    Bulbous();

    QString getCategory();

protected:

    QString _category;
};

#endif // LEGUMINOUS_H
