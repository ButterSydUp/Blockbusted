#ifndef VIEWINVENTORY_H
#define VIEWINVENTORY_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QDebug>
#include <QtGui>
#include <mainwindow.h>

namespace Ui {
class ViewInventory;
}

class ViewInventory : public QWidget
{
    Q_OBJECT

public:
    explicit ViewInventory(QWidget *parent = 0);
    ~ViewInventory();

private:
    Ui::ViewInventory *ui;
    QSqlTableModel *model;
};

#endif // VIEWINVENTORY_H
