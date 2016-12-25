#include "vegetablecreatorui.h"

VegetableCreatorUI::VegetableCreatorUI(QWidget *parent) : QWidget(parent)
{
    // create;

    ob_label_selectVeg = new QLabel("Помидор");
    ob_label_img = new QLabel;

    ob_button_next = new Button("", "qrc:/resources/img/next.png", Button::Top);
    ob_button_prev = new Button("", "qrc:/resources/img/prev.png", Button::Top);
    ob_button_select = new Button("Добавить");
    ob_button_back = new Button("Назад");

    ob_vlay_main = new QVBoxLayout;

    ob_hlay_selectVeg = new QHBoxLayout;
    ob_hlay_buttons = new QHBoxLayout;

    ob_hash_vegs = new QHash<QString, QString>();

    // config;

    setLayout(ob_vlay_main);

    ob_vlay_main->addWidget(ob_label_selectVeg);
    ob_vlay_main->addLayout(ob_hlay_selectVeg);
    ob_vlay_main->addLayout(ob_hlay_buttons);
    ob_vlay_main->setContentsMargins(0, 0, 0, 0);
    ob_vlay_main->setSpacing(0);

    ob_hlay_selectVeg->addWidget(ob_button_prev,1);
    ob_hlay_selectVeg->addWidget(ob_label_img,10);
    ob_hlay_selectVeg->addWidget(ob_button_next,1);

    ob_hlay_buttons->setSpacing(1);
    ob_hlay_buttons->addWidget(ob_button_back,1);
    ob_hlay_buttons->addWidget(ob_button_select, 5);

    ob_button_next->setDefaultOpacity(0);
    ob_button_prev->setDefaultOpacity(0);
    ob_button_select->setFixedHeight(70);

    ob_label_img->setMinimumSize(400,400);
    ob_label_img->setAlignment(Qt::AlignCenter);
    ob_label_img->setText("<img src=\"qrc:/resources/img/vegetables/tomatos/tomato.png\">");

    ob_label_selectVeg->setStyleSheet("background: rgba(60,120,210,0.1); color: white;");
    ob_label_selectVeg->setAlignment(Qt::AlignCenter);
    ob_label_selectVeg->setFixedHeight(50);

    connect(ob_button_back,SIGNAL(clicked()),SIGNAL(backClicked()));
    connect(ob_button_prev,SIGNAL(clicked()),SLOT(onPrevClicked()));
    connect(ob_button_next,SIGNAL(clicked()),SLOT(onNextClicked()));

    // hash config;

    Asparagus aspargus;
    Bow bow;
    Cucumber cuc;
    Garlic garlic;
    Gourd gourd;
    Tomato tomato;

    ob_hash_vegs->insert(aspargus.title(), aspargus.icon());
    ob_hash_vegs->insert(bow.title(), bow.icon());
    ob_hash_vegs->insert(cuc.title(), cuc.icon());
    ob_hash_vegs->insert(garlic.title(), garlic.icon());
    ob_hash_vegs->insert(gourd.title(), gourd.icon());
    ob_hash_vegs->insert(tomato.title(), tomato.icon());

    updateHash();

    connect(ob_button_select,SIGNAL(clicked()),SLOT(onSelected()));
}

void VegetableCreatorUI::updateHash() {
    vegetable_iterator = 0;
    ob_label_img->setText("<img src=\""+ob_hash_vegs->value(ob_hash_vegs->keys().at(0))+"\">");
    ob_label_selectVeg->setText(ob_hash_vegs->keys().at(0));
}

void VegetableCreatorUI::onNextClicked() {
    if(++vegetable_iterator == ob_hash_vegs->keys().count()) {
        vegetable_iterator = 0;
    };
    ob_label_img->setText("<img src=\""+ob_hash_vegs->value(ob_hash_vegs->keys().at(vegetable_iterator))+"\">");
    ob_label_selectVeg->setText(ob_hash_vegs->keys().at(vegetable_iterator));
}

void VegetableCreatorUI::onPrevClicked() {
    if(--vegetable_iterator == -1) {
        vegetable_iterator = ob_hash_vegs->keys().count()-1;
    }
    ob_label_img->setText("<img src=\""+ob_hash_vegs->value(ob_hash_vegs->keys().at(vegetable_iterator))+"\">");
    ob_label_selectVeg->setText(ob_hash_vegs->keys().at(vegetable_iterator));
}

void VegetableCreatorUI::onSelected() {
    if(ob_label_selectVeg->text() == "Спаржа") {
        emit selected(new Asparagus);
    } else if(ob_label_selectVeg->text() == "Лук") {
        emit selected(new Bow);
    } else if(ob_label_selectVeg->text() == "Огурец") {
        emit selected(new Cucumber);
    } else if(ob_label_selectVeg->text() == "Чеснок") {
        emit selected(new Garlic);
    } else if(ob_label_selectVeg->text() == "Тыква") {
        emit selected(new Gourd);
    } else if(ob_label_selectVeg->text() == "Помидор") {
        emit selected(new Tomato);
    }
}
