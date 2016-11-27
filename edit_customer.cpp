#include "edit_customer.h"
#include "ui_edit_customer.h"

edit_customer::edit_customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_customer)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("Customer");
    model->select();

    ui->tableView->setModel(model);
}

edit_customer::~edit_customer()
{
    delete ui;
}
