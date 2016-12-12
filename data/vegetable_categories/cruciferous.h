#ifndef CABBAGE_H
#define CABBAGE_H

#include "../vegetable.h"

class Cruciferous : public Vegetable
{

public:
    Cruciferous();

    QString getCategory();
protected:
    QString _category;
};

#endif // CABBAGE_H
