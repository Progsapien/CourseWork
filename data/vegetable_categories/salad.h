#ifndef SALAD_H
#define SALAD_H

#include "../vegetable.h"

class Salad : public Vegetable
{
public:
    Salad();

    QString getCategory();
protected:
    QString _category;
};

#endif // SALAD_H
