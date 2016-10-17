#include "dbmanager.h"

//Constructor
//Sets up the database connection and opens it
DbManager::DbManager()
{
    blockbusted_db = QSqlDatabase::addDatabase("QSQLITE");
    blockbusted_db.setDatabaseName("C:/Users/Josh/Desktop/BlockBusted/blockbusted_db.db");

    if(!blockbusted_db.open())
        qDebug() << "Error: Failed to connect to database.";
    else
        qDebug() << "Connected to database.";
}


//Deconstructor
//Closes the connection
DbManager::~DbManager()
{
    blockbusted_db.close();
    blockbusted_db.removeDatabase("blockbusted_db.db");
    qDebug() << "Connection closed.";
}


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

