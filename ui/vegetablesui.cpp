#include "vegetablesui.h"

VegetablesUI::VegetablesUI(QWidget *parent) : QWidget(parent)
{
    // create;

    ob_button_add = new Button("","qrc:/resources/img/add_salad_button.png", Button::Top);
    ob_button_back = new Button("", "qrc:/resources/img/prev.png", Button::Top);
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
    ob_label_listVegetables->setFixedHeight(50);

    ob_list_vegetables->setStyleSheet("QListView { border: none; background: rgb(54, 66, 86); color: white;} "
                                      "QListView::item:selected { background: rgb(75, 83, 97); border: none; color: white;  } "
                                      "QListView::item { color: white; border: none; } ");

    connect(ob_button_back,SIGNAL(clicked()),SIGNAL(backToInfo()));
    connect(ob_button_add,SIGNAL(clicked()),SIGNAL(addVegetable()));
    connect(ob_button_delete,SIGNAL(clicked()),SLOT(onDelete()));

}

void VegetablesUI::updateList(Salad *salad) {
    ob_list_vegetables->clear();
    current_salad = salad;
    for(int i = 0; i < salad->allVegetables()->count(); i++) {
        ob_list_vegetables->addItem(salad->allVegetables()->at(i)->title());
        ob_list_vegetables->item(ob_list_vegetables->count()-1)->setSizeHint(QSize(1, 50));
    }
}

void VegetablesUI::onDelete() {
    if(ob_list_vegetables->selectedItems().count() != 0) {
        SaladManager::deleteVegetable(current_salad, current_salad->allVegetables()->at(ob_list_vegetables->row(ob_list_vegetables->selectedItems().at(0))));
        updateList(current_salad);
    }
    emit deleteVegetable();
}
