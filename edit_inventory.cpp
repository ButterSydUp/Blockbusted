#include "edit_inventory.h"
#include "ui_edit_inventory.h"
#include <QMessageBox>

edit_inventory::edit_inventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_inventory)
{
    ui->setupUi(this);

}

edit_inventory::~edit_inventory()
{
    delete ui;
}

void edit_inventory::on_add_product_clicked()
{
    QString pid, name, genre, rating, price;
    pid = ui->pid_input->text();
    name = ui->pname_input->text();
    genre = ui->pgenre_input->text();
    rating = ui->prating_input->text();
    price = ui->pprice_input->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO Inventory (ProductID, ProductName, Genre, Rating, Price) VALUES (:pid, :name, :genre, :rating, :price)");
    qry.bindValue(":pid", pid);
    qry.bindValue(":name", name);
    qry.bindValue(":genre", genre);
    qry.bindValue(":rating", rating);
    qry.bindValue(":price", price);

    if(qry.exec())
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
    else
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
}

void edit_inventory::on_edit_product_clicked()
{
    QString pid, name, genre, rating, price;
    pid = ui->pid_input->text();
    name = ui->pname_input->text();
    genre = ui->pgenre_input->text();
    rating = ui->prating_input->text();
    price = ui->pprice_input->text();

    QSqlQuery qry;
    qry.prepare("UPDATE Inventory SET ProductID='"+pid+"', ProductName='"+name+"', Genre='"+genre+"', Rating='"+rating+"', Price='"+price+"' WHERE ProductID='"+pid+"'");

    if(qry.exec())
        QMessageBox::critical(this, tr("Edit"), tr("Updated!"));
    else
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
}

void edit_inventory::on_load_inv_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("SELECT * FROM Inventory");
    qry->exec();
    model->setQuery(*qry);
    ui->inv_view->setModel(model);
    qDebug() << (model->rowCount());
}

void edit_inventory::on_inv_view_clicked(const QModelIndex &index)
{
    QString val = ui->inv_view->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM Inventory WHERE ProductID='"+val+"' OR ProductName='"+val+"' OR Genre='"+val+"' OR Rating='"+val+"' OR Price='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->pid_input->setText(qry.value(0).toString());
            ui->pname_input->setText(qry.value(1).toString());
            ui->pgenre_input->setText(qry.value(2).toString());
            ui->prating_input->setText(qry.value(3).toString());
            ui->pprice_input->setText(qry.value(4).toString());
        }
    }
    else {
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
}

void edit_inventory::on_remove_product_clicked()
{
    QString pid, name, genre, rating, price;
    pid = ui->pid_input->text();
    //name = ui->pname_input->text();
    //genre = ui->pgenre_input->text();
    //rating = ui->prating_input->text();
    //price = ui->pprice_input->text();

    QSqlQuery qry;
    qry.prepare("DELETE FROM Inventory WHERE ProductID='"+pid+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Delete"), tr("Deleted!"));
    }
    else
    {
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
}
