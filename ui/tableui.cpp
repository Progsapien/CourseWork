#include "tableui.h"
#include "../data/vegetables/tomato.h"
#include "../data/salad.h"

TableUI::TableUI(QWidget *parent) : QWidget(parent)
{
    // create;

    ob_table = new Table;

    ob_label_listSalads = new QLabel("Список салатов");

    ob_button_addSalad = new Button("Добавить","qrc:/resources/img/add_salad_button.png", Button::Top);
    ob_button_deleteSalad = new Button("Удалить", "qrc:/resources/img/delete_salad_button.png", Button::Top);
    ob_button_searchSalad = new Button("Поиск", "qrc:/resources/img/search_salad_button.png", Button::Top);
    ob_vlay_list = new QVBoxLayout;
    ob_vlay_operations = new QVBoxLayout;

    ob_hlay_main = new QHBoxLayout;

    ob_list_salads = new QListWidget;

    ob_profile_man = new ProfileManager;

    ob_window_addui = new AddUI;

    ob_sbutton_add = new SaladButton("Салатов нет", "Добавить салат", "qrc:/resources/img/salad_empty.png", "qrc:/resources/img/salad.png");

    // config;
    setLayout(ob_hlay_main);
    setStyleSheet("background: rgb(54, 66, 86);");

    ob_hlay_main->addWidget(ob_sbutton_add);
    //ob_hlay_main->addLayout(ob_vlay_list);
    //ob_hlay_main->addLayout(ob_vlay_operations);
    ob_hlay_main->setSpacing(0);
    ob_hlay_main->setContentsMargins(0, 0, 0, 0);

    ob_vlay_list->addWidget(ob_label_listSalads);
    ob_vlay_list->addWidget(ob_list_salads);
    ob_vlay_list->setSpacing(0);

    ob_vlay_operations->addWidget(ob_button_addSalad);
    ob_vlay_operations->addWidget(ob_button_deleteSalad);
    ob_vlay_operations->addWidget(ob_button_searchSalad);
    ob_vlay_operations->setSpacing(0);

    ob_label_listSalads->setAlignment(Qt::AlignCenter);
    ob_label_listSalads->setStyleSheet("background: rgb(54, 66, 86); color: white");
    ob_label_listSalads->setMinimumHeight(50);

    ob_list_salads->setStyleSheet("QListView { border: none; background: rgb(54, 66, 86); color: white;} "
                                  "QListView::item:selected { background: rgb(75, 83, 97); border: none; color: white;  } "
                                  "QListView::item { color: white; border: none; } ");

    ob_button_addSalad->setFixedWidth(90);

    connect(ob_button_addSalad,SIGNAL(clicked()),SLOT(onAddClick()));
    connect(ob_window_addui,SIGNAL(createSalad(QString)),SLOT(onCreateSalad(QString)));
    connect(ob_sbutton_add,SIGNAL(clicked()),SLOT(onAddClick()));
}

void TableUI::onAddClick() {
    emit changeWidget(ob_window_addui);
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
        ob_hlay_main->addLayout(ob_vlay_list);
        ob_hlay_main->addLayout(ob_vlay_operations);
        TABLE_UI_SHOWED = true;
        ob_sbutton_add->hide();
    }
}

void TableUI::onLogin(QString username) {
    ob_profile_man->setUsername(username);
    ob_table = TableManager::fromJSON(ob_profile_man->loadProfile());
    if(ob_table->getSalads()->count() != 0) {
        ob_sbutton_add->hide();
        ob_hlay_main->addLayout(ob_vlay_list);
        ob_hlay_main->addLayout(ob_vlay_operations);
        TABLE_UI_SHOWED = true;
    }
    refreshTable();
}

void TableUI::onCreateSalad(QString saladName) {
    Salad *new_salad = new Salad;
    new_salad->setTitle(saladName);
    ob_table->getSalads()->append(new_salad);
    refreshTable();
    changeWidget(this);
}

