#include "login.h"

Login::Login(QWidget *parent) :
    QWidget(parent)
{
    // create;

    ob_button_login = new Button("Начать");

    ob_label_name = new QLabel("Введите Ваше имя, повар!");
    ob_label_welcome = new QLabel;

    ob_line_name = new QLineEdit;

    ob_vbox_main = new QVBoxLayout;

    // config;

    setLayout(ob_vbox_main);
    setStyleSheet("background: rgb(54, 66, 86);");

    ob_vbox_main->addWidget(ob_label_welcome);
    ob_vbox_main->addWidget(ob_label_name);
    ob_vbox_main->addWidget(ob_line_name);
    ob_vbox_main->addWidget(ob_button_login);
    ob_vbox_main->setContentsMargins(0,0,0,0);
   // ob_vbox_main->setAlignment(Qt::AlignCenter);

    ob_line_name->setMinimumHeight(30);
    ob_line_name->setStyleSheet("background: rgb(47, 58, 76); border: none; color: white;");
    ob_line_name->setAlignment(Qt::AlignCenter);

    ob_label_name->setStyleSheet("color: white");
    ob_label_name->setAlignment(Qt::AlignCenter);

    ob_label_welcome->setText("<br><br><br><br><img src=\"qrc:/resources/img/chef.png\">");
    ob_label_welcome->setAlignment(Qt::AlignCenter);

    ob_button_login->setFixedHeight(50);
    connect(ob_button_login,SIGNAL(clicked()),SLOT(onButtonLoginClick()));
}

void Login::onButtonLoginClick() {
    if(!ob_line_name->text().isEmpty()) {
        emit login(ob_line_name->text());
    }
}
