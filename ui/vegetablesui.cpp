#include "vegetablesui.h"

VegetablesUI::VegetablesUI(QWidget *parent) : QWidget(parent)
{
    // create;

    ob_button_add = new Button("","qrc:/resources/img/add_salad_button.png", Button::Top);
    ob_button_back = new Button("Назад");
    ob_button_delete = new Button("", "qrc:/resources/img/delete_salad_button.png", Button::Top);

    ob_vlay_main = new QVBoxLayout;

    ob_hlay_buttons = new QHBoxLayout;

    ob_label_listVegetables = new QLabel("Список овощей");

    ob_list_vegetables = new QListWidget;

    // config;

    setLayout(ob_vlay_main);

    ob_vlay_main->addWidget(ob_label_listVegetables);
    ob_vlay_main->addWidget(ob_list_vegetables);
    ob_vlay_main->addLayout(ob_hlay_buttons);
    ob_vlay_main->setContentsMargins(0, 0, 0, 0);
    ob_vlay_main->setSpacing(0);

    ob_hlay_buttons->addWidget(ob_button_back,1);
    ob_hlay_buttons->addWidget(ob_button_add, 5);
    ob_hlay_buttons->addWidget(ob_button_delete,5);
    ob_hlay_buttons->setSpacing(1);

    ob_button_back->setFixedHeight(70);

    ob_label_listVegetables->setAlignment(Qt::AlignCenter);
    ob_label_listVegetables->setStyleSheet("color: white;");

    ob_list_vegetables->setStyleSheet("border: none");

    connect(ob_button_back,SIGNAL(clicked()),SIGNAL(backToInfo()));

}

void VegetablesUI::onAdd() {

}

void VegetablesUI::onDelete() {

}
