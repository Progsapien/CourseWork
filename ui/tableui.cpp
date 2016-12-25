#include "tableui.h"
#include "../data/vegetables/tomato.h"
#include "../data/salad.h"

TableUI::TableUI(QWidget *parent) : QWidget(parent)
{
    // create;

    ob_table = new Table;

    ob_label_listSalads = new QLabel("Список салатов");

    ob_button_addSalad = new Button("","qrc:/resources/img/add_salad_button.png", Button::Top);
    ob_button_deleteSalad = new Button("", "qrc:/resources/img/delete_salad_button.png", Button::Top);
    ob_button_searchSalad = new Button("", "qrc:/resources/img/search_salad_button.png", Button::Top);

    ob_vlay_main = new QVBoxLayout;

    ob_hlay_buttons = new QHBoxLayout;

    ob_list_salads = new QListWidget;

    ob_profile_man = new ProfileManager;

    ob_window_addui = new AddUI;

    ob_window_info = new SaladInfoUI;

    ob_window_veg = new VegetablesUI;

    ob_window_vegCreator = new VegetableCreatorUI;

    ob_sbutton_add = new SaladButton("Салатов нет", "Добавить салат", "qrc:/resources/img/salad_empty.png", "qrc:/resources/img/salad.png");

    // config;
    setLayout(ob_vlay_main);
    setWindowTitle("Шеф-повар");
    setStyleSheet("background: rgb(54, 66, 86);");

    ob_vlay_main->addWidget(ob_sbutton_add);
    ob_vlay_main->addWidget(ob_label_listSalads);
    ob_vlay_main->addWidget(ob_list_salads);
    ob_vlay_main->addLayout(ob_hlay_buttons);
    ob_vlay_main->setContentsMargins(0, 0, 0, 0);
    ob_vlay_main->setSpacing(0);

    ob_hlay_buttons->setSpacing(1);
    ob_hlay_buttons->addWidget(ob_button_addSalad);
    ob_hlay_buttons->addWidget(ob_button_deleteSalad);
    ob_hlay_buttons->addWidget(ob_button_searchSalad);

    ob_label_listSalads->setAlignment(Qt::AlignCenter);
    ob_label_listSalads->setStyleSheet("background: rgb(54, 66, 86); color: white");
    ob_label_listSalads->setMinimumHeight(50);
    ob_label_listSalads->hide();

    ob_list_salads->setStyleSheet("QListView { border: none; background: rgb(54, 66, 86); color: white;} "
                                  "QListView::item:selected { background: rgb(75, 83, 97); border: none; color: white;  } "
                                  "QListView::item { color: white; border: none; } ");
    ob_list_salads->hide();

    ob_button_addSalad->hide();

    ob_button_deleteSalad->hide();

    ob_button_searchSalad->hide();
    ob_button_searchSalad->setFixedHeight(60);

    connect(ob_button_addSalad,SIGNAL(clicked()),SLOT(onAddClick()));
    connect(ob_button_deleteSalad,SIGNAL(clicked()),SLOT(onDeleteClick()));
    connect(ob_window_addui,SIGNAL(createSalad(QString)),SLOT(onCreateSalad(QString)));
    connect(ob_sbutton_add,SIGNAL(clicked()),SLOT(onAddClick()));
    connect(ob_list_salads,SIGNAL(itemDoubleClicked(QListWidgetItem*)),SLOT(onDoubleClick(QListWidgetItem*)));
    connect(ob_window_info,SIGNAL(backToTable()),SLOT(backToTable()));
    connect(ob_window_info,SIGNAL(ingredients()),SLOT(ingredientsCall()));
    connect(ob_window_veg,SIGNAL(backToInfo()),SLOT(backToInfo()));
    connect(ob_window_vegCreator,SIGNAL(backClicked()),SLOT(backToIngredients()));
    connect(ob_window_veg,SIGNAL(addVegetable()),SLOT(onAddVegetable()));
    connect(ob_window_vegCreator,SIGNAL(selected(Vegetable*)),SLOT(onVegetableSelected(Vegetable*)));
    connect(ob_window_veg,SIGNAL(deleteVegetable()),SLOT(onDeleteVegetable()));
}

void TableUI::onAddClick() {
    emit changeWidget(ob_window_addui);
}

void TableUI::onDeleteClick() {
    if(ob_list_salads->selectedItems().count() != 0) {
        ob_table->getSalads()->removeOne(ob_table->getSalads()->at(ob_list_salads->row(ob_list_salads->selectedItems().at(0))));
        ob_profile_man->dumpProfile(TableManager::toJSON(ob_table));
        refreshTable();
    }
}

void TableUI::refreshTable() {
    ob_list_salads->clear();
    for(int i = 0; i < ob_table->getSalads()->count(); i++) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(1, 40));
        item->setText(ob_table->getSalads()->at(i)->title());
        ob_list_salads->addItem(item);
    }
    ob_profile_man->dumpProfile(TableManager::toJSON(ob_table));
    if(!TABLE_UI_SHOWED && ob_table->getSalads()->count() != 0) {
        ob_sbutton_add->hide();
        ob_label_listSalads->show();
        ob_list_salads->show();
        ob_button_addSalad->show();
        ob_button_deleteSalad->show();
        ob_button_searchSalad->show();
        TABLE_UI_SHOWED = true;
    }
}

void TableUI::onLogin(QString username) {
    ob_profile_man->setUsername(username);
    ob_table = TableManager::fromJSON(ob_profile_man->loadProfile());
    if(ob_table->getSalads()->count() != 0) {
        ob_sbutton_add->hide();
        ob_label_listSalads->show();
        ob_list_salads->show();
        ob_button_addSalad->show();
        ob_button_deleteSalad->show();
        ob_button_searchSalad->show();
        TABLE_UI_SHOWED = true;
    }
    refreshTable();
}

void TableUI::onCreateSalad(QString saladName) {
    for(int i = 0; i < ob_table->getSalads()->count(); i++) {
        if(ob_table->getSalads()->at(i)->title() == saladName) {
            changeWidget(this);
            return;
        }
    }
    Salad *new_salad = new Salad;
    new_salad->setTitle(saladName);
    ob_table->getSalads()->append(new_salad);
    refreshTable();
    changeWidget(this);
}

void TableUI::onDoubleClick(QListWidgetItem *item) {
    current_salad = ob_table->getSalads()->at(ob_list_salads->row(item));
    ob_window_veg->updateList(current_salad);
    ob_window_info->showInfo(current_salad);
    changeWidget(ob_window_info);
}

void TableUI::backToTable() {
    emit changeWidget(this);
}

void TableUI::ingredientsCall() {
    emit changeWidget(ob_window_veg);
}

void TableUI::backToInfo() {
    ob_window_info->showInfo(current_salad);
    emit changeWidget(ob_window_info);
}

void TableUI::backToIngredients() {
    emit changeWidget(ob_window_veg);
}

void TableUI::onVegetableSelected(Vegetable *veg) {
    SaladManager::addVegetable(current_salad, veg);
    ob_window_veg->updateList(current_salad);
    ob_profile_man->dumpProfile(TableManager::toJSON(ob_table));
    changeWidget(ob_window_veg);
}

void TableUI::onDeleteVegetable() {
    ob_profile_man->dumpProfile(TableManager::toJSON(ob_table));
}

void TableUI::onAddVegetable() {
    emit changeWidget(ob_window_vegCreator);
}
