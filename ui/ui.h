#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QDebug>

class UI : public QWidget
{
    Q_OBJECT

public:
    UI(QWidget *parent = 0);
    ~UI();
};

#endif // UI_H
