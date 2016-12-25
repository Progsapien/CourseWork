#ifndef VEGETABLECREATORUI_H
#define VEGETABLECREATORUI_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "button.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "../data/vegetables/asparagus.h"
#include "../data/vegetables/bow.h"
#include "../data/vegetables/cucumber.h"
#include "../data/vegetables/garlic.h"
#include "../data/vegetables/gourd.h"
#include "../data/vegetables/tomato.h"

#include "../data/vegetable.h"

class VegetableCreatorUI : public QWidget
{
    Q_OBJECT
public:
    explicit VegetableCreatorUI(QWidget *parent = 0);

    void updateHash();

private:
    Button *ob_button_prev,
           *ob_button_next,
           *ob_button_select,
           *ob_button_back;

    QLabel *ob_label_selectVeg,
           *ob_label_img;

    QVBoxLayout *ob_vlay_main;

    QHBoxLayout *ob_hlay_selectVeg,
                *ob_hlay_buttons;

    QHash<QString, QString> *ob_hash_vegs;

    int vegetable_iterator;
   // QTimer *ob_timer;
private slots:
    void onNextClicked();
    void onPrevClicked();
    void onSelected();
signals:
    void backClicked();
    void selected(Vegetable *vegetable);
};

#endif // VEGETABLECREATORUI_H
