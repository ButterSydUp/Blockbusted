#include "inventory_count.h"
#include "ui_inventory_count.h"
#include <QMessageBox>

inventory_count::inventory_count(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inventory_count)
{
    ui->setupUi(this);

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT * FROM InventoryCount");
    query->exec();
    model->setQuery(*query);
    ui->inventoryCount->setModel(model);
    qDebug() << (model->rowCount());

}

inventory_count::~inventory_count()
{
    delete ui;
}
