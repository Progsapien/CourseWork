#ifndef VEGETABLE_H
#define VEGETABLE_H

#include <QObject>
#include <QJsonObject>

class Vegetable : public QObject
{

    Q_OBJECT

public:
    explicit Vegetable();
    ~Vegetable();

    // get

    QString title();
    QString icon();
    double weight();
    double calories();
    QJsonObject toJSON();

    // set

    void setWeight(double weight);
    void setTitle(QString title);
    void setCalories(double calories);
    void setIcon(QString iconPath);
    void fromJSON(QJsonObject json);

protected:

    QString _title;
    QString _icon;
    double _weight;
    double _calories;

};

#endif // VEGETABLE_H
