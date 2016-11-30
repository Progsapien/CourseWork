#ifndef VEGETABLE_H
#define VEGETABLE_H

#include <QObject>

class Vegetable : public QObject
{

    Q_OBJECT

public:
    explicit Vegetable();
    ~Vegetable();

    // get

    QString title();
    double weight();
    double calories();

    // set

    void setWeight(double weight);
    void setTitle(QString title);
    void setCalories(double calories);

protected:

    QString _title;
    double _weight;
    double _calories;

};

#endif // VEGETABLE_H
