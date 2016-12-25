#include "findsaladui.h"

FindSaladUI::FindSaladUI(QWidget *parent) : QWidget(parent)
{
    // create;

    ob_hlay_main = new QHBoxLayout;

    ob_vlay_lines = new QVBoxLayout;
    ob_vlay_titles = new QVBoxLayout;

    ob_label_findByName = new QLabel("Имя");
    ob_label_findByVegetable = new QLabel("Овощи");

    ob_line_name = new QLineEdit;
    ob_line_vegetable = new QLineEdit;

    // config;

    setLayout(ob_hlay_main);
    setStyleSheet("color: white; padding: 5px;");


    ob_hlay_main->addLayout(ob_vlay_titles);
    ob_hlay_main->addLayout(ob_vlay_lines);

    ob_vlay_lines->addWidget(ob_line_name);
    ob_vlay_lines->addWidget(ob_line_vegetable);
    ob_vlay_lines->setSpacing(0);

    ob_vlay_titles->addWidget(ob_label_findByName);
    ob_vlay_titles->addWidget(ob_label_findByVegetable);
    ob_vlay_titles->setSpacing(0);

    ob_line_name->setStyleSheet("border: none; color: white; background: rgb(47, 58, 76);");
    ob_line_vegetable->setStyleSheet(ob_line_name->styleSheet());

    connect(ob_line_name,SIGNAL(textChanged(QString)),SLOT(onFind(QString)));
    connect(ob_line_vegetable,SIGNAL(textChanged(QString)),SLOT(onFind(QString)));

}

void FindSaladUI::onFind(QString text) {
    QStringList list;
    if(sender() == ob_line_name) {
        for(int i = 0; i < ob_table->getSalads()->count(); i++) {
            if(ob_table->getSalads()->at(i)->title().contains(text)) {
                list.append(ob_table->getSalads()->at(i)->title());
            }
        }
        emit onFounded(list);
    } else {
        QStringList list_vegs = text.split(" ");
        list.clear();
        list_vegs.removeAll("");
        int counter = 0;
        emit clearList();
        for(int i = 0; i < ob_table->getSalads()->count(); i++) {
            counter = 0;
            for(int j = 0; j < ob_table->getSalads()->at(i)->allVegetables()->count(); j++) {
                for(int k = 0; k < list_vegs.count(); k++) {
                    if(list_vegs.at(k) == ob_table->getSalads()->at(i)->allVegetables()->at(j)->title()) {
                        counter++;
                        if(!list.contains(ob_table->getSalads()->at(i)->title())) {
                            list.append(ob_table->getSalads()->at(i)->title());
                        }
                        if(counter == list_vegs.count()) {
                            emit onFounded(list);
                        } else {
                            emit clearList();
                        }
                    }
                }
            }
        }
    }
}

void FindSaladUI::setTable(Table *table) {
    ob_table = table;
}
