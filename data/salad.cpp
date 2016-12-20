#include "salad.h"

Salad::Salad(QObject *parent) : QObject(parent)
{
    // create;
    ob_list_vegetables = new QList<Vegetable*>();
    ob_tomato = new Tomato;

    // config;

    ob_list_vegetables->append(ob_tomato);
}
