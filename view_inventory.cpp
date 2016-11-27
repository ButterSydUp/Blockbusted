#include "view_inventory.h"
#include "ui_view_inventory.h"

View_inventory::View_inventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::View_inventory)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("Inventory");
    model->select();

    ui->tableView->setModel(model);
}

View_inventory::~View_inventory()
{
    delete ui;
}
