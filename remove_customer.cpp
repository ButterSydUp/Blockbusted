#include "remove_customer.h"
#include "ui_remove_customer.h"
#include <QMessageBox>
remove_customer::remove_customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remove_customer)
{
    ui->setupUi(this);
}

remove_customer::~remove_customer()
{
    delete ui;
}

void remove_customer::on_view_customer_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT * FROM Customer");
    qry->exec();
    model->setQuery(*qry);
    ui->cus_view->setModel(model);
}

void remove_customer::on_rem_customer_clicked()
{
    QString customerID;
    customerID = ui->customerID->text();
    QSqlQuery qry;
    qry.prepare("DELETE FROM Customer WHERE CustomerID='"+customerID+"'");
    if(qry.exec()){
        QMessageBox::critical(this, tr("Delete"), tr("Deleted!"));
    }
    else {
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
}

void remove_customer::on_cus_view_clicked(const QModelIndex &index)
{
    QString cus_id = ui->cus_view->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Customer WHERE CustomerID='"+cus_id+"' OR FirstName='"+cus_id+"' OR LastName='"+cus_id+"'");

    if(qry.exec()){
        while(qry.next()){
            ui->customerID->setText(qry.value(0).toString());
            ui->customer_fn->setText(qry.value(1).toString());
            ui->customer_ln->setText(qry.value(2).toString());
        }
    }
}
