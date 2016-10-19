#include "emp_verification.h"
#include "ui_emp_verification.h"

emp_verification::emp_verification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emp_verification)
{
    ui->setupUi(this);
}

emp_verification::~emp_verification()
{
    qDebug() << "EMPLOYEE DONE";
    delete ui;
}

//Cancels out of sign in window
void emp_verification::on_cancelButton_clicked()
{
    QWidget::close();
}


//Requests verification when prompted
//User provides username (employee ID) and password
//If manager, signs in no problem
//If not a manager, returns saying "Insufficient privileges"
void emp_verification::on_signInButton_clicked()
{
    QString username, password;
    username = ui->lineEdit_Username->text();
    password = ui->lineEdit_Password->text();
    QSqlQuery qry;
    if(qry.exec("SELECT * FROM Employee WHERE EmpID = '"+ username +"' AND Password = '"+ password +"'"))
    {
        int count = 0;
        int managerFlag = 0;

        while(qry.next())
        {
            count++;
            managerFlag = qry.value(3).toInt();
        }

        if(count == 1 && managerFlag == 1)
        {
            ui->label->setText("Signed in");
            isSignedIn = true;
            this->close();
        }
        else if(count == 1 && managerFlag != 1)
            ui->label->setText("Insufficient privileges");
        else if(count < 1)
            ui->label->setText("Incorrect username or password");
    }
}
