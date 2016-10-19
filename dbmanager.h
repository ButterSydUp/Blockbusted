#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QDebug>
#include <QFileInfo>

class DbManager
{
public:

    DbManager();
    ~DbManager();
    QSqlDatabase *blockbusted_db;
    void dataClose();
    bool dataOpen();
    //Adds a customer to the database
    //Takes in first and last name, address, phone number, and email address as arguments
    void addCustomerToDB(QString firstName, QString lastName, QString address, QString city,
                         QString state, QString zipCode, QString phoneNumber, QString emailAddress);

};

#endif // DBMANAGER_H
