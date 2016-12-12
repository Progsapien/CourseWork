#ifndef LEGUMINOUS_H
#define LEGUMINOUS_H

#include "../vegetable.h"

class Leguminous : public Vegetable
{
public:
    Leguminous();

    QString getCategory();

protected:

    QString _category;
};

#endif // LEGUMINOUS_H
