#include "addemployee.h"
#include "ui_addemployee.h"


//new line
addEmployee::addEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEmployee)
{
    ui->setupUi(this);
}

addEmployee::~addEmployee()
{
    delete ui;
}

//Cancels out of sign in window
void addEmployee::on_cancelButton_clicked()
{
    QWidget::close();
}

void addEmployee::on_signInButton_clicked()
{

}

