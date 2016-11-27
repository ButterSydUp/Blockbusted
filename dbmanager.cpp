#include "dbmanager.h"
QString databasepath = "/home/mcviking/Documents/cs441/Blockbusted-Progress/Progress/blockbusted_db.db";
//Constructor
//Sets up the database connection and opens it
DbManager::DbManager(){
    blockbusted_db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    blockbusted_db->setDatabaseName(databasepath);
    if(blockbusted_db->open())
        qDebug() << "Database is open...";
    else
        qDebug() << "Database did not open...";
}

void DbManager::dataClose(){
    //qDebug() << blockbusted_db.connectionName();
    blockbusted_db->close();
    QString connection = blockbusted_db->connectionName();
    delete blockbusted_db;
    QSqlDatabase::removeDatabase(connection);
    qDebug() << "Database connection removed";

}

DbManager::~DbManager(){
    dataClose();
}

/*
//Adds a customer to the database
//Takes in first and last name, address, phone number, and email address as arguments
void DbManager::addCustomerToDB(QString firstName, QString lastName, QString address, QString city,
                                QString state, QString zipCode, QString phoneNumber, QString emailAddress)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Customer (FirstName, LastName, Address, City, State, ZipCode, PhoneNumber, EmailAddress)"
                  "VALUES (:FirstName, :LastName, :Address, :City, :State, :ZipCode, :PhoneNumber, :EmailAddress)");
    query.bindValue(":FirstName", firstName);
    query.bindValue(":LastName", lastName);
    query.bindValue(":Address", address);
    query.bindValue(":City", city);
    query.bindValue(":State", state);
    query.bindValue(":ZipCode", zipCode);
    query.bindValue(":PhoneNumber", phoneNumber);
    query.bindValue(":EmailAddress", emailAddress);
    if(!query.exec())
    {
        qDebug() << "Add Person Error: "
                 << query.lastError();
    }
}
*/
