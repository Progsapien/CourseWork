#include "ui/ui.h"

UI::UI(QWidget *parent)
    : QWidget(parent)
{
    ob_button_login = new Button("Начать");
    ob_button_login->show();
}

UI::~UI()
{

}
