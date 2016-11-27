#include "edit_employee.h"
#include "ui_edit_employee.h"

//Create Window and Automatically load Employee Table to view
//Excludes GM from being loaded and thus
//Prevents GM from being altered or removed
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
