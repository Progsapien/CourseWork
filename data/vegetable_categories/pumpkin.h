#ifndef PUMPKIN_H
#define PUMPKIN_H

#include "../vegetable.h"

class Pumpkin : public Vegetable
{
public:
    Pumpkin();
    QString getCategory();
protected:
    QString _category;
};

#endif // PUMPKIN_H
