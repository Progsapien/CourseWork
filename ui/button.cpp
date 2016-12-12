#include "button.h"

Button::Button(QString text)
{
    this->setText(text);
    this->setStyleSheet("background: rgba(60,120,210,1); border: none; color: white");
    this->setFixedSize(100,100);
}

Button::Button(QString text, QString imgPath, int position) {
    switch (position) {
    case ImagePosition::Left:
        this->setText("<img src=\""+imgPath+"\"> "+text);
        break;
    case ImagePosition::Top:
        this->setText("<img src=\""+imgPath+"\"><br><br>"+text);
        break;
    default:
        this->setText(text+" <img src=\""+imgPath+"\">");
    }

    this->setOpacity(1);
}

void Button::setOpacity(float opacity) {
    this->setStyleSheet("background: rgba(60,120,210,"+QString::number(opacity)+"); border: none; color: white");
}

void Button::mousePressEvent(QMouseEvent *event) {
    event->accept();
    this->setOpacity(0.4);
}

void Button::mouseReleaseEvent(QMouseEvent *event) {
    event->accept();
    this->setOpacity(0.7);
}

void Button::enterEvent(QEvent *event) {
    event->accept();
    this->setOpacity(0.7);
}

void Button::leaveEvent(QEvent *event) {
    event->accept();
    this->setOpacity(1);
}
