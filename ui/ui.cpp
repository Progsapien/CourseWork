#include "ui/ui.h"

UI::UI(QWidget *parent)
    : QWidget(parent)
{
    // create;
    ob_window_login = new Login;
    ob_window_main = new MainUI;

    ob_timer_main = new QTimer;

    // config;

    setStyleSheet("background: rgb(54, 66, 86);");
    setFixedSize(800,600);

    connect(ob_timer_main,SIGNAL(timeout()),SLOT(onTimer()));
    changeWidget(ob_window_login);
}

UI::~UI()
{

}

void UI::resizeEvent(QResizeEvent *event) {
    event->accept();
    if(new_widget != NULL) {
        new_widget->setFixedSize(size());
    }
}

void UI::changeWidget(QWidget *new_widget) {
    this->new_widget = new_widget;
    new_widget->setParent(this);
    new_widget->raise();
    new_widget->move(this->width()/2, 0);
    new_widget->show();

    ob_timer_main->start(1);
}

void UI::onTimer() {
    if(new_widget->x() > 0) {
        new_widget->move(new_widget->x()-4, 0);
    } else {
        new_widget->move(0, 0);
        ob_timer_main->stop();
    }
    new_widget->setFixedSize(size());
}
