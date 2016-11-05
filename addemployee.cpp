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

void addEmployee::on_addButton_clicked()
{
    QString fName, lName, addr, cit, zCode, sta, pNum, emailA, passWord;
    int manaOrEmp;

    fName = ui->empFname->text();
    lName = ui->empLname->text();
    manaOrEmp = ui->empOrMana->isChecked();
    passWord = ui->empPass->text();
    addr = ui->empAddress->text();
    cit = ui->empCity->text();
    zCode = ui->empZip->text();
    sta = ui->empState->text();
    emailA = ui->empEmail->text();
    pNum = ui->empPhone->text();

    if ((fName==NULL)||(lName==NULL)||(addr==NULL)||(cit==NULL)||(zCode==NULL)||(sta==NULL)||(pNum==NULL)||(emailA==NULL)||(passWord==NULL))
    {
        ui->errorLabel->setText("Please fill all the requiered fields.");
        ui->errorLabel2->setText(NULL);
    }
    else
    {
        //DbManager dataBase;
        //dataBase.addEmployeeToDB(fName, lName, addr, cit, sta, zCode, pNum, emailA);

        QSqlQuery query;
        query.prepare("INSERT INTO Employee (FirstName, LastName, Manager, Password, Address, City, State, ZipCode, EmailAddress, PhoneNumber)"
                      "VALUES (:FirstName, :LastName, :Manager, :Password, :Address, :City, :State, :ZipCode, :EmailAddress, :PhoneNumber)");
        query.bindValue(":FirstName", fName);
        query.bindValue(":LastName", lName);
        query.bindValue(":Manager", manaOrEmp);
        query.bindValue(":Password", passWord);
        query.bindValue(":Address", addr);
        query.bindValue(":City", cit);
        query.bindValue(":State", sta);
        query.bindValue(":ZipCode", zCode);
        query.bindValue(":EmailAddress", emailA);
        query.bindValue(":PhoneNumber", pNum);

        if(!query.exec())
        {
            qDebug() << "Add Employee Error: "
                     << query.lastError();
        }

        ui->errorLabel->setText("Employee was added to the database, click 'add'");
        ui->errorLabel2->setText("to add another employee or cancel to exit.");
        ui->empFname->setText(NULL);
        ui->empLname->setText(NULL);
        ui->empPass->setText(NULL);
        //ui->empOrMana->isChecked();
        ui->empAddress->setText(NULL);
        ui->empCity->setText(NULL);
        ui->empZip->setText(NULL);
        ui->empState->setText(NULL);
        ui->empPhone->setText(NULL);
        ui->empEmail->setText(NULL);
    }
}
