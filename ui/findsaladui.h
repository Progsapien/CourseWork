#ifndef FINDSALADUI_H
#define FINDSALADUI_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../data/table.h"
#include "../data/salad.h"
#include <QDebug>

class FindSaladUI : public QWidget
{
    Q_OBJECT
public:
    explicit FindSaladUI(QWidget *parent = 0);
    void setTable(Table *table);
private:
    QLabel *ob_label_findByName,
           *ob_label_findByVegetable;

    QLineEdit *ob_line_name,
              *ob_line_vegetable;

    QVBoxLayout *ob_vlay_titles,
                *ob_vlay_lines;

    QHBoxLayout *ob_hlay_main;

    Table *ob_table;

private slots:
    void onFind(QString text);

signals:
    void onFounded(QStringList list);
    void clearList();

};

#endif // FINDSALADUI_H
