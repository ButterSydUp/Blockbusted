#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QMainWindow>
#include <QScreen>
#include <iostream>
#include <QVBoxLayout>
using namespace std;

//stuffffff
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    QRect rec = QApplication::desktop()->screenGeometry();
    const int height1 = rec.height(); // returns the height of the screen.
    const int width1 = rec.width(); // returns the width of the screen.
    this->setFixedSize(width1,height1); // Sets the size of the window to the dimensions of the screen.
    const int adminB = (width1 * .78); // How far the right column sticks out to the right of the screen.
    const int xsize = adminB * .25; // The width of the buttons
    int ysize = height1 * .50; // The height of the buttons are 30% of the total screen height

    ui->setupUi(this);

    // multiply the xsize and ysize by any number to increase the scaling of the buttons size.
    ui->splitter->resize(xsize,ysize);  // splitter refers to the normal employee buttons.
    ui->splitter_2->resize(xsize,ysize); // splitter_2 refers to the admin buttons.

    cout << width1 << endl;
    cout << height1 << endl;
    cout << adminB << endl;
    cout << height1 * .10 << endl;
    cout << ysize << endl;
    ui->groupBox_3->resize(xsize*1.2,ysize*1.2);
    ui->groupBox_2->move(adminB,10);
    ui->groupBox_3->move(10,10);
    ui->groupBox_2->resize(xsize*1.2,ysize*1.2);

    const int signInBox_xSize = width1*0.2;
    const int signInBox_ySize = height1*0.2;
    ui->signInBox->resize(signInBox_xSize, signInBox_ySize);


    ui->check_in->setEnabled(false);
    ui->check_out->setEnabled(false);
    ui->add_Customer->setEnabled(false);
    ui->remove_Customer->setEnabled(false);
    ui->view_Customers->setEnabled(false);
    ui->view_Inv->setEnabled(false);
    ui->add_emp->setEnabled(false);
    ui->remove_emp->setEnabled(false);
    ui->view_emp->setEnabled(false);
    ui->edit_Inv->setEnabled(false);

}


MainWindow::~MainWindow()
{
    delete ui;
}


//Button for quitting the program
void MainWindow::on_fts_clicked()
{
    database->dataClose();
    qApp->exit();
}

//Button for adding employee
//Asks for authentication
void MainWindow::on_add_emp_clicked()
{

        addEmployee addEmp;
        addEmp.setModal(true);
        addEmp.exec();
}

//Button for removing/terminating employee
//Asks for authentication
void MainWindow::on_remove_emp_clicked()
{

}

//Button for viewing/editting employee
//Asks for authentication
void MainWindow::on_view_emp_clicked()
{

}

//Button for editting inventory
//Can add to inventory
//Can remove from inventory
//Asks for authentication
void MainWindow::on_edit_Inv_clicked()
{

        edit_inventory editInv;
        editInv.setModal(true);
        editInv.exec();

}

//Button for checking in
//Does not require authentication
void MainWindow::on_check_in_clicked()
{

}

//Button for checking out
//Does not require authentication
void MainWindow::on_check_out_clicked()
{

}

//Button for adding customers to database
//Does not require authentication
void MainWindow::on_add_Customer_clicked()
{
    addCustomer addCus;
    addCus.setModal(true);
    addCus.exec();
}

//Button for removing customers from database
//Does not require authentication
void MainWindow::on_remove_Customer_clicked()
{

}

//Button for viewing/editting customers' information
//Does not require authentication
void MainWindow::on_view_Customers_clicked()
{

}

//Button ONLY for viewing inventory
//Cannot edit/remove/add to inventory
//Does not require authentication
void MainWindow::on_view_Inv_clicked()
{

}

void MainWindow::on_signInButton_clicked()
{
    emp_verification empVer;
    empVer.setModal(true);
    empVer.exec();

    if(empVer.generalManagerIsSignedIn == true)
    {
        ui->loggedInName->setText(empVer.firstName + " " + empVer.lastName);
        ui->empID->setText(empVer.empID);
        ui->emp_Position->setText("General Manager");

        ui->check_in->setEnabled(true);
        ui->check_out->setEnabled(true);
        ui->add_Customer->setEnabled(true);
        ui->remove_Customer->setEnabled(true);
        ui->view_Customers->setEnabled(true);
        ui->view_Inv->setEnabled(true);
        ui->add_emp->setEnabled(true);
        ui->remove_emp->setEnabled(true);
        ui->view_emp->setEnabled(true);
        ui->edit_Inv->setEnabled(true);
    }
    else if(empVer.assistantManagerIsSignedIn == true)
    {
        ui->loggedInName->setText(empVer.firstName + " " + empVer.lastName);
        ui->empID->setText(empVer.empID);
        ui->emp_Position->setText("Assistant Manager");

        ui->check_in->setEnabled(true);
        ui->check_out->setEnabled(true);
        ui->add_Customer->setEnabled(true);
        ui->remove_Customer->setEnabled(true);
        ui->view_Customers->setEnabled(true);
        ui->view_Inv->setEnabled(true);
        ui->add_emp->setEnabled(false);
        ui->remove_emp->setEnabled(false);
        ui->view_emp->setEnabled(true);
        ui->edit_Inv->setEnabled(false);
    }
    else if(empVer.employeeIsSignedIn == true)
    {
        ui->loggedInName->setText(empVer.firstName + " " + empVer.lastName);
        ui->empID->setText(empVer.empID);
        ui->emp_Position->setText("Employee");

        ui->check_in->setEnabled(true);
        ui->check_out->setEnabled(true);
        ui->add_Customer->setEnabled(true);
        ui->remove_Customer->setEnabled(true);
        ui->view_Customers->setEnabled(true);
        ui->view_Inv->setEnabled(true);
        ui->add_emp->setEnabled(false);
        ui->remove_emp->setEnabled(false);
        ui->view_emp->setEnabled(false);
        ui->edit_Inv->setEnabled(false);
    }
}

void MainWindow::on_signOutButton_clicked()
{
    ui->loggedInName->setText("No user logged in");
    ui->empID->setText("Not available");
    ui->emp_Position->setText("Not available");

    ui->check_in->setEnabled(false);
    ui->check_out->setEnabled(false);
    ui->add_Customer->setEnabled(false);
    ui->remove_Customer->setEnabled(false);
    ui->view_Customers->setEnabled(false);
    ui->view_Inv->setEnabled(false);
    ui->add_emp->setEnabled(false);
    ui->remove_emp->setEnabled(false);
    ui->view_emp->setEnabled(false);
    ui->edit_Inv->setEnabled(false);
}


