#ifndef CABBAGE_H
#define CABBAGE_H

#include "../vegetable.h"

class Cabbage : public Vegetable
{

public:
    Cabbage();

    QString getCategory();
protected:
    QString _category;
};

#endif // CABBAGE_H
