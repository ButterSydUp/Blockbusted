#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "emp_verification.h"
#include "edit_inventory.h"
#include "addemployee.h"
#include "addcustomer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase blockbusted_db;
    void dataClose()
    {
        blockbusted_db.close();
        blockbusted_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool dataOpen()
    {
        blockbusted_db = QSqlDatabase::addDatabase("QSQLITE");
        blockbusted_db.setDatabaseName("/Users/FF/Documents/CSUSM/2016 Fall/1CS 441 Software Engineering  Mon 0915 - 1115/Blockbusted-master/Updated-Files/blockbusted_db.db");

        //Checks to see if database opened
        if(!blockbusted_db.open())
        {
            qDebug() << ("Failed to connect to database...");
            return false;
        }
        else
        {
            qDebug() << ("Connected to database...");
            return true;
        }
    }


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_fts_clicked();

    void on_add_emp_clicked();

    void on_remove_emp_clicked();

    void on_view_emp_clicked();

    void on_edit_Inv_clicked();
    
    void on_check_in_clicked();

    void on_check_out_clicked();

    void on_add_Customer_clicked();

    void on_remove_Customer_clicked();

    void on_view_Customers_clicked();

    void on_view_Inv_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
