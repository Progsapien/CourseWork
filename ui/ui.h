#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QDebug>
#include "login.h"
#include <QTimer>
#include "tableui.h"

class UI : public QWidget
{
    Q_OBJECT

public:
    UI(QWidget *parent = 0);
    ~UI();
public slots:
    void changeWidget(QWidget *new_widget);
private:
    Login *ob_window_login;

    TableUI *ob_window_table;

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
