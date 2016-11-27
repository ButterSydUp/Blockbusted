#include "viewinventory.h"
#include "ui_viewinventory.h"

ViewInventory::ViewInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewInventory)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("Inventory");
    model->select();

    //ui->displayInventory->setModel(model);
}

ViewInventory::~ViewInventory()
{
    delete ui;
}
