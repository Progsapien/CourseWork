#include "table.h"
#include <QLabel>
#include "../data/salad.h"
#include "../data/vegetables/tomato.h"
Table::Table()
{
    // create;

    ob_list_salads = new QList<Salad*>();

}

// get

QList<Salad*>* Table::getSalads() {
    return ob_list_salads;
}

//set

void Table::setSalads(QList<Salad *> *salads) {
    ob_list_salads = salads;
}
