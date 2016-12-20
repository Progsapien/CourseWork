#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QDebug>
#include "login.h"
#include "mainui.h"
#include <QTimer>

class UI : public QWidget
{
    Q_OBJECT

public:
    UI(QWidget *parent = 0);
    ~UI();

    void changeWidget(QWidget *new_widget);

private:
    Login *ob_window_login;
    MainUI *ob_window_main;

    QTimer *ob_timer_main;

    QWidget *new_widget,
            *current_widget;

protected:
    virtual void resizeEvent(QResizeEvent *event);
private slots:
    void onTimer();
    void onLogin(QString username);
};

#endif // UI_H
