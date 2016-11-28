#include "inventory_count.h"
#include "ui_inventory_count.h"
#include <QMessageBox>
#include <QWidget>
#include <QDesktopWidget>
#include <iostream>


inventory_count::inventory_count(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inventory_count)
{
    QRect rec = QApplication::desktop()->screenGeometry();
    const int scrnHeight = rec.height(); // returns the height of the screen.
    const int scrnWidth = rec.width(); // returns the width of the screen.
    double boxWidth = scrnWidth * .50;
    double boxHeight = scrnHeight * .50;
    int innerFrameX = boxWidth*.90;
    int innerFrameY = boxHeight*.75;
    ui->setupUi(this);

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT * FROM InventoryCount");
    query->exec();
    model->setQuery(*query);
    ui->inventoryCount->setModel(model);
    qDebug() << (model->rowCount());
    this->setFixedSize(boxWidth,boxHeight);
    ui->inventoryCount->resize(innerFrameX,innerFrameY);
    ui->exit->resize(innerFrameX*.20,innerFrameY*.12);
    ui->exit->move(boxWidth/2-innerFrameX*.10,boxHeight*.85);

}

inventory_count::~inventory_count()
{
    delete ui;
}
