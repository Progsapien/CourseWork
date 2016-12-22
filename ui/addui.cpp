#include "addui.h"

AddUI::AddUI(QWidget *parent) : QWidget(parent)
{
    // create;
    ob_button_create = new Button("Создать салат");

    ob_label_name = new QLabel("Введите имя салата");

    ob_vlay_main = new QVBoxLayout;

    ob_line_name = new QLineEdit;

    // config;

    setLayout(ob_vlay_main);
    setStyleSheet("background: rgb(54, 66, 86);");

    ob_vlay_main->addWidget(ob_label_name);
    ob_vlay_main->addWidget(ob_line_name);
    ob_vlay_main->addWidget(ob_button_create);
    ob_vlay_main->setContentsMargins(0,0,0,0);
    ob_vlay_main->setAlignment(Qt::AlignCenter);

    ob_label_name->setStyleSheet("color: white;");
    ob_label_name->setAlignment(Qt::AlignCenter);

    ob_button_create->setFixedHeight(60);

    ob_line_name->setStyleSheet("background: rgb(47, 58, 76); border: none; color: white;");
    ob_line_name->setFixedHeight(30);
    ob_line_name->setAlignment(Qt::AlignCenter);

    connect(ob_button_create,SIGNAL(clicked()),SLOT(onClick()));
}

void AddUI::onClick() {
    if(!ob_line_name->text().isEmpty()) {
        emit createSalad(ob_line_name->text());
    }
}
