#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QDebug>
#include "button.h"

class UI : public QWidget
{
    Q_OBJECT

public:
    UI(QWidget *parent = 0);
    ~UI();
private:
    Button *ob_button_login;
};

#endif // UI_H
