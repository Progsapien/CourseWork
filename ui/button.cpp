#include "button.h"

Button::Button(QString text)
{
    this->setText(text);
    this->setStyleSheet("background: rgba(60,120,210,1); border: none; color: white");
    this->setAlignment(Qt::AlignCenter);
    this->setDefaultOpacity(0.1);
}

Button::Button(QString text, QString imgPath, int position) {
    switch (position) {
   case ImagePosition::Left:
        this->setText("<p align='center'><img src=\""+imgPath+"\"> "+text);
        break;
    case ImagePosition::Top:
        this->setText("<p align='center'><img src=\""+imgPath+"\">"+text);
        break;
    default:
        this->setText("<p align='center'>"+text+" <img src=\""+imgPath+"\">");
    }

    this->setDefaultOpacity(0.1);
}

void Button::setOpacity(float opacity) {
    this->setStyleSheet("background: rgba(60,120,210,"+QString::number(opacity)+"); border: none; color: white");
}

void Button::setDefaultOpacity(float opacity) {
    this->default_opacity = opacity >= 0 ? opacity : 0.1;
    qDebug() << default_opacity;
    setOpacity(this->default_opacity);
}

void Button::mousePressEvent(QMouseEvent *event) {
    event->accept();
    this->setOpacity(1);
}

void Button::mouseReleaseEvent(QMouseEvent *event) {
    event->accept();
    this->setOpacity(0.8);
    emit clicked();
}

void Button::enterEvent(QEvent *event) {
    event->accept();
    this->setOpacity(0.8);
}

void Button::leaveEvent(QEvent *event) {
    event->accept();
    this->setOpacity(this->default_opacity);
}
