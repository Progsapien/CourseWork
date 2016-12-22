#include "tableui.h"
#include "../data/vegetables/tomato.h"
#include "../data/salad.h"

TableUI::TableUI(QWidget *parent) : QWidget(parent)
{
    // create;

    ob_table = new Table;

    ob_label_listSalads = new QLabel("Список салатов");

    ob_button_addSalad = new Button("Добавить");
    ob_button_deleteSalad = new Button("Удалить");
    ob_button_searchSalad = new Button("Поиск");
    ob_button_sortSalad = new Button("Сортировать");
    ob_vlay_list = new QVBoxLayout;
    ob_vlay_operations = new QVBoxLayout;

    ob_hlay_main = new QHBoxLayout;

    ob_list_salads = new QListWidget;

    ob_profile_man = new ProfileManager;

    ob_window_addui = new AddUI;

    // config;
    setLayout(ob_hlay_main);
    setStyleSheet("background: rgb(54, 66, 86);");

    ob_hlay_main->addLayout(ob_vlay_list);
    ob_hlay_main->addLayout(ob_vlay_operations);
    ob_hlay_main->setSpacing(0);
    ob_hlay_main->setContentsMargins(0, 0, 0, 0);

    ob_vlay_list->addWidget(ob_label_listSalads);
    ob_vlay_list->addWidget(ob_list_salads);
    ob_vlay_list->setSpacing(0);

    ob_vlay_operations->addWidget(ob_button_addSalad);
    ob_vlay_operations->addWidget(ob_button_deleteSalad);
    ob_vlay_operations->addWidget(ob_button_searchSalad);
    ob_vlay_operations->addWidget(ob_button_sortSalad);
    ob_vlay_operations->setSpacing(0);

    ob_label_listSalads->setAlignment(Qt::AlignCenter);
    ob_label_listSalads->setStyleSheet("background: rgb(54, 66, 86); color: white");
    ob_label_listSalads->setMinimumHeight(50);

    ob_list_salads->setStyleSheet("border: none; background: rgb(54, 66, 86);");

    ob_button_addSalad->setFixedWidth(90);

    connect(ob_button_addSalad,SIGNAL(clicked()),SLOT(onAddClick()));
}

void TableUI::onAddClick() {
    emit changeWidget(ob_window_addui);
    Salad *s = new Salad;
    s->setTitle("sdfsdf");
    Tomato *t = new Tomato;
    Tomato *t1 = new Tomato;
    Salad *s1 = new Salad;
    s1->setTitle("НОвый саалат");

    SaladManager::addVegetable(s, t);
    SaladManager::addVegetable(s1, t1);
    SaladManager::addVegetable(s1,t);
    ob_table->getSalads()->append(s);
    ob_table->getSalads()->append(s1);
    QJsonArray array = TableManager::toJSON(ob_table);
    qDebug() << array;
    ob_profile_man->dumpProfile(array);
}

void TableUI::onLogin(QString username) {
    ob_profile_man->setUsername(username);
   // SaladManager::fromJSON(ob_profile_man->loadProfile());
}
