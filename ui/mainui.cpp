#include "mainui.h"

MainUI::MainUI(QWidget *parent) : QWidget(parent)
{
    // create;
    ob_sbutton_status = new SaladButton("Готовых салатов нет!", "Приготовить салат", "qrc:/resources/img/salad_empty.png", "qrc:/resources/img/salad.png");

    ob_vlay_main = new QVBoxLayout;

    ob_list_salads = new QListWidget;

    // config;

    setLayout(ob_vlay_main);
    setStyleSheet("background: rgb(54, 66, 86); color: white;");

    ob_vlay_main->addWidget(ob_sbutton_status);
    ob_vlay_main->addWidget(ob_list_salads);
    ob_vlay_main->setContentsMargins(0, 0, 0, 0);
    //ob_vlay_main->setAlignment(Qt::AlignCenter);

    ob_list_salads->hide();
}
