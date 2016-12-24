#ifndef VEGETABLESUI_H
#define VEGETABLESUI_H

#include <QWidget>
#include <QListWidget>
#include "button.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class VegetablesUI : public QWidget
{
    Q_OBJECT
public:
    explicit VegetablesUI(QWidget *parent = 0);
private:
    QLabel *ob_label_listVegetables;

    QListWidget *ob_list_vegetables;

    QVBoxLayout *ob_vlay_main;

    QHBoxLayout *ob_hlay_buttons;

    Button *ob_button_back,
           *ob_button_add,
           *ob_button_delete;

private slots:
    void onAdd();
    void onDelete();

signals:
    void backToInfo();
};

#endif // VEGETABLESUI_H
