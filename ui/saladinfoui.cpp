#include "saladinfoui.h"

SaladInfoUI::SaladInfoUI(QWidget *parent) : QWidget(parent)
{
    // create;

    ob_label_info = new QLabel;

    ob_button_ingredients = new Button("Ингредиенты..");
    ob_button_back = new Button("Назад");

    ob_vlay_main = new QVBoxLayout;

    ob_hlay_buttons = new QHBoxLayout;

    // config;

    setLayout(ob_vlay_main);

    ob_vlay_main->addWidget(ob_label_info);
    ob_vlay_main->addLayout(ob_hlay_buttons);
    ob_vlay_main->setContentsMargins(0, 0, 0, 0);

    ob_hlay_buttons->addWidget(ob_button_back, 1);
    ob_hlay_buttons->addWidget(ob_button_ingredients, 5);
    ob_hlay_buttons->setSpacing(1);

    ob_button_ingredients->setFixedHeight(70);

    ob_label_info->setAlignment(Qt::AlignCenter);
    ob_label_info->setStyleSheet("color: white");

    connect(ob_button_back,SIGNAL(clicked()),SIGNAL(backToTable()));
    connect(ob_button_ingredients,SIGNAL(clicked()),SIGNAL(ingredients()));

}

void SaladInfoUI::showInfo(Salad *salad) {
    ob_label_info->setText("<img src=\"qrc:/resources/img/salad_add.png\"><br><br><br>"
                           "Салат \""+salad->title()+"\"<br><br>Суммарная калорийность:  "+QString::number(SaladManager::totalCalories(salad))
                           +" калорий<br><br>Суммарный вес:  "+QString::number(SaladManager::totalWeight(salad))
                           +" грамм<br><br>Количество ингредиентов:  "+QString::number(salad->allVegetables()->count()));
}
