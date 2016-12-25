#include "sortingsaladsui.h"

SortingSaladsUI::SortingSaladsUI(Table *table, QWidget *parent) : QWidget(parent)
{
    // create;

    ob_label_title = new QLabel("Сортировка");

    ob_cb_toMax = new QCheckBox("По возрастанию");

    ob_rb_byCalories = new QRadioButton("По калориям");
    ob_rb_byWeight = new QRadioButton("По весу");
    ob_rb_byName = new QRadioButton("По имени");

    ob_vlay_main = new QVBoxLayout;

    ob_table = table;

    // config;

    setLayout(ob_vlay_main);
    setStyleSheet("background: rgba(60,120,210,0.1); color: white; padding: 4px;");

    ob_vlay_main->addWidget(ob_label_title);
    ob_vlay_main->addWidget(ob_rb_byName);
    ob_vlay_main->addWidget(ob_rb_byCalories);
    ob_vlay_main->addWidget(ob_rb_byWeight);
    ob_vlay_main->addWidget(ob_cb_toMax);
    ob_vlay_main->setSpacing(0);

    ob_label_title->setAlignment(Qt::AlignCenter);

    connect(ob_rb_byName,SIGNAL(clicked(bool)),SLOT(clicked(bool)));
    connect(ob_rb_byCalories,SIGNAL(clicked(bool)),SLOT(clicked(bool)));
    connect(ob_rb_byWeight,SIGNAL(clicked(bool)),SLOT(clicked(bool)));
    connect(ob_cb_toMax,SIGNAL(clicked(bool)),SLOT(clicked(bool)));
}

void SortingSaladsUI::setTable(Table *table) {
    ob_table = table;
}

void SortingSaladsUI::clicked(bool _) {
    TableManager::SortingBy sortBy;

    if(ob_rb_byCalories->isChecked()) {
        sortBy = TableManager::Calories;
    } else if(ob_rb_byName->isChecked()) {
        sortBy = TableManager::Name;
    } else if(ob_rb_byWeight->isChecked()) {
        sortBy = TableManager::Weight;
    }

    TableManager::sortTable(ob_table, sortBy, ob_cb_toMax->isChecked());
    emit sorted();
    qDebug() << "End";
}
