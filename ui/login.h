#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "button.h"

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);

private:
    QLabel *ob_label_welcome,
           *ob_label_name;

    QLineEdit *ob_line_name;

    QVBoxLayout *ob_vbox_main;

    Button *ob_button_login;
signals:
    void login(QString username);
private slots:
    void onButtonLoginClick();
};

#endif // LOGIN_H
