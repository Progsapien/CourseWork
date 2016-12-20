#ifndef SALAD_H
#define SALAD_H

#include <QObject>
#include <QList>
#include "vegetable.h"
#include "vegetables/tomato.h"

class Salad : public QObject
{
    Q_OBJECT
public:
    explicit Salad(QObject *parent = 0);
private:
    QList<Vegetable*> *ob_list_vegetables;
    Tomato *ob_tomato;
};

#endif // SALAD_H
