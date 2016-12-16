#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "button.h"

class MainUI : public QWidget
{
    Q_OBJECT
public:
    explicit MainUI(QWidget *parent = 0);

signals:

public slots:
};

#endif // MAINUI_H
