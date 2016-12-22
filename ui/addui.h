#ifndef ADDUI_H
#define ADDUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "button.h"

class AddUI : public QWidget
{
    Q_OBJECT
public:
    explicit AddUI(QWidget *parent = 0);
private:
    QLabel *ob_label_name;

    QVBoxLayout *ob_vlay_main;

    QLineEdit *ob_line_name;

    Button *ob_button_create;

signals:
    void createSalad(QString saladName);
private slots:
    void onClick();
};

#endif // ADDUI_H
