#ifndef GENERALMANAGER_H
#define GENERALMANAGER_H

#include <QFile>
#include <iostream>
#include <QTextStream>

class GeneralManager
{

    private:
        QFile myfile;



        QString firstName;
        QString lastName;
        QString address;
        QString city;
        QString state;
        QString zipCode;
        QString phoneNumber;
        QString emailAddress;
        QString username;
        QString password;

    public:

        GeneralManager();
        ~GeneralManager();

        void editGeneralManager();

};

#endif // GENERALMANAGER_H
