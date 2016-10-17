#include "addcustomer.h"
#include "ui_addcustomer.h"

addCustomer::addCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCustomer)
{
    ui->setupUi(this);
}

addCustomer::~addCustomer()
{
    delete ui;
}

//Cancels out of sign in window
void addCustomer::on_cancelButton_clicked()
{
    QWidget::close();
}

void addCustomer::on_addButton_clicked()
{
    QString fName, lName, addr, cit, zCode, sta, pNum, emailA;

    fName = ui->cusfirstName->text();
    lName = ui->cuslastName->text();
    addr = ui->cusaddress->text();
    cit = ui->cuscity->text();
    zCode = ui->cuszipCode->text();
    sta = ui->cusstate->text();
    pNum = ui->cusphoneNumber->text();
    emailA = ui->cusemail->text();

    if ((fName==NULL)||(lName==NULL)||(addr==NULL)||(cit==NULL)||(zCode==NULL)||(sta==NULL)||(pNum==NULL)||(emailA==NULL))
    {
        ui->errorLabel->setText("Please fill all the requiered fields.");
        ui->errorLabel2->setText(NULL);
    }
    else
    {
        DbManager dataBase;
        dataBase.addCustomerToDB(fName, lName, addr, cit, sta, zCode, pNum, emailA);
        ui->errorLabel->setText("Customer was added to the database, click 'add'");
        ui->errorLabel2->setText("to add another customer or cancel to exit.");
        ui->cusfirstName->setText(NULL);
        ui->cuslastName->setText(NULL);
        ui->cusaddress->setText(NULL);
        ui->cuscity->setText(NULL);
        ui->cuszipCode->setText(NULL);
        ui->cusstate->setText(NULL);
        ui->cusphoneNumber->setText(NULL);
        ui->cusemail->setText(NULL);
    }
}
