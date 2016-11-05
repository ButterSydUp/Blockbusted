#include "emp_verification.h"
#include "ui_emp_verification.h"
#include <QLabel>
#include <QWidget>
#include <QDesktopWidget>
#include <iostream>
#include <QFont>

emp_verification::emp_verification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emp_verification)
{
    QRect rec = QApplication::desktop()->screenGeometry();
    const int scrnHeight = rec.height(); // returns the height of the screen.
    const int scrnWidth = rec.width(); // returns the width of the screen.
    double boxWidth = scrnWidth * .20;
    double boxHeight = scrnHeight * .15;
    double fontSize = (boxWidth) * .02;
    int innerFrameX = boxWidth*.8;
    int innerFrameY = boxHeight*.8;
    ui->setupUi(this);
    this->resize(boxWidth,boxHeight);
    ui->centralWidget->resize(innerFrameX,innerFrameY);
    ui->centralWidget->move(boxWidth/2-innerFrameX/2,boxHeight/2-innerFrameY*.6);
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
