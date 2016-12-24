#ifndef SALADINFOUI_H
#define SALADINFOUI_H

#include <QWidget>
#include <QLabel>
#include "button.h"
#include <QVBoxLayout>
#include "../data/salad.h"
#include "../managers/saladmanager.h"
#include <QDebug>

class SaladInfoUI : public QWidget
{
    Q_OBJECT
public:
    explicit SaladInfoUI(QWidget *parent = 0);
    void showInfo(Salad *salad);
private:
    QLabel *ob_label_info;

    QVBoxLayout *ob_vlay_main;
    QHBoxLayout *ob_hlay_buttons;

    Button *ob_button_ingredients;
    Button *ob_button_back;

signals:
    void backToTable();
    void ingredients();

};

#endif // SALADINFOUI_H
