#ifndef SALADBUTTON_H
#define SALADBUTTON_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>


class SaladButton : public QLabel
{
    Q_OBJECT
public:
    SaladButton(QString defaultCaption, QString enterCaption, QString defaultImg, QString enterImg);
private:
    QString defaultImg,
            enterImg,
            defaultCaption,
            enterCaption;
protected:
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
signals:
    void clicked();
};

#endif // SALADBUTTON_H
