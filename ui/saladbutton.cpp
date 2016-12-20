#include "saladbutton.h"

SaladButton::SaladButton(QString defaultCaption, QString enterCaption, QString defaultImg, QString enterImg)
{
    this->defaultImg = defaultImg;
    this->enterImg = enterImg;
    this->defaultCaption = defaultCaption;
    this->enterCaption = enterCaption;

    setStyleSheet("color: white;");
    setAlignment(Qt::AlignCenter);
    setCursor(Qt::PointingHandCursor);
}

void SaladButton::enterEvent(QEvent *event) {
    event->accept();
    this->setText("<img src=\""+this->enterImg+"\"><br><br>"+this->enterCaption);
}

void SaladButton::leaveEvent(QEvent *event) {
    event->accept();
    this->setText("<img src=\""+this->defaultImg+"\"><br><br>"+this->defaultCaption);
}

void SaladButton::mouseReleaseEvent(QMouseEvent *event) {
    event->accept();
    emit clicked();
}
