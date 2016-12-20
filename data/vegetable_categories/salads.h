#ifndef SALAD_H
#define SALAD_H

#include "../vegetable.h"

class Salads : public Vegetable
{
public:
    Salads();

    QString getCategory();
protected:
    QString _category;
};

#endif // SALAD_H
