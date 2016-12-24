#ifndef TABLEUI_H
#define TABLEUI_H

#include <QWidget>
#include <QListWidget>
#include "button.h"
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "../data/table.h"
#include "../managers/profilemanager.h"
#include "../managers/saladmanager.h"
#include "addui.h"
#include "../managers/tablemanager.h"
#include "saladbutton.h"
#include "saladinfoui.h"
#include "vegetablesui.h"

class TableUI : public QWidget
{
    Q_OBJECT
public:
    explicit TableUI(QWidget *parent = 0);
private:
    QLabel *ob_label_listSalads;
    QVBoxLayout *ob_vlay_list,
                *ob_vlay_operations;

    QHBoxLayout *ob_hlay_main;

    Button *ob_button_addSalad,
           *ob_button_deleteSalad,
           *ob_button_searchSalad;

    QListWidget *ob_list_salads;

    Table *ob_table;

    ProfileManager *ob_profile_man;

    AddUI *ob_window_addui;

    SaladButton *ob_sbutton_add;

    SaladInfoUI *ob_window_info;

    VegetablesUI *ob_window_veg;

    bool TABLE_UI_SHOWED;

    void refreshTable();

private slots:
    void onAddClick();
    void onLogin(QString username);
    void onCreateSalad(QString saladName);
    void onDoubleClick(QListWidgetItem *item);
    void backToTable();
    void ingredientsCall();
    void backToInfo();
signals:
    void changeWidget(QWidget *widget);
};

#endif // TABLEUI_H
