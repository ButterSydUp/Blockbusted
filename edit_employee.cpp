#include "edit_employee.h"
#include "ui_edit_employee.h"

edit_employee::edit_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_employee)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("Employee");
    model->setFilter("EmpID != 1000");
    model->select();

    ui->tableView->setModel(model);
}

edit_employee::~edit_employee()
{
    delete ui;
}
