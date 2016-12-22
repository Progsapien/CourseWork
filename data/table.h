#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include "../data/salad.h"

class Table : public QObject
{
    Q_OBJECT
public:
    explicit Table();

    // get
    QList<Salad *> *getSalads();

    // set
    void setSalads(QList<Salad *> *salads);

private:
    QList<Salad*> *ob_list_salads;
};

#endif // TABLE_H
