#ifndef SALADMANAGER_H
#define SALADMANAGER_H

#include <QObject>

class SaladManager : public QObject
{
    Q_OBJECT
public:
    explicit SaladManager(QObject *parent = 0);

signals:

public slots:
};

#endif // SALADMANAGER_H