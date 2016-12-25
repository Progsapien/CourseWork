#ifndef SORTINGSALADSUI_H
#define SORTINGSALADSUI_H

#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QLabel>
#include "../managers/tablemanager.h"
#include "../data/table.h"
#include <QDebug>

class SortingSaladsUI : public QWidget
{
    Q_OBJECT
public:
    explicit SortingSaladsUI(Table *table, QWidget *parent = 0);
    void setTable(Table *table);

private:
    QCheckBox *ob_cb_toMax;

    QRadioButton *ob_rb_byName;
    QRadioButton *ob_rb_byCalories;
    QRadioButton *ob_rb_byWeight;

    QLabel *ob_label_title;

    QVBoxLayout *ob_vlay_main;

    Table *ob_table;

private slots:

    void clicked(bool _);
signals:
    void sorted();
};

#endif // SORTINGSALADSUI_H
