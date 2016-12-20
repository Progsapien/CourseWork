#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include "button.h"
#include "saladbutton.h"

class MainUI : public QWidget
{
    Q_OBJECT
public:
    explicit MainUI(QWidget *parent = 0);
private:
    SaladButton *ob_sbutton_status;

    QVBoxLayout *ob_vlay_main;

    QListWidget *ob_list_salads;
};

#endif // MAINUI_H
