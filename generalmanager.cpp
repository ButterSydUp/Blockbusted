#include "generalmanager.h"

using namespace std;

GeneralManager::GeneralManager()
{
    myfile.setFileName("C:/Users/Josh/Desktop/Blockbusted/generalmanager.txt");
    if(!myfile.open(QIODevice::ReadOnly | QIODevice::Text))
        cout << "Unable to open file" << endl;
    else
    {
        int count = 1;

        QTextStream in(&myfile);

        while(!in.atEnd())
        {
            QString line = in.readLine();

            switch(count)
            {
                case 1:
                    firstName = line;
                    break;
                case 2:
                    lastName = line;
                    break;
                case 3:
                    address = line;
                    break;
                case 4:
                    city = line;
                    break;
                case 5:
                    state = line;
                    break;
                case 6:
                    zipCode = line;
                    break;
                case 7:
                    phoneNumber = line;
                    break;
                case 8:
                    emailAddress = line;
                    break;
                case 9:
                    username = line;
                    break;
                case 10:
                    password = line;
                    break;
            }

            count++;
        }
    }
}

GeneralManager::~GeneralManager()
{
    myfile.close();
}

//Tests by printing out for now
void GeneralManager::editGeneralManager()
{
    cout << firstName.toStdString() << endl;
    cout << lastName.toStdString() << endl;
    cout << address.toStdString() << endl;
    cout << city.toStdString() << endl;
    cout << state.toStdString() << endl;
    cout << zipCode.toStdString() << endl;
    cout << phoneNumber.toStdString() << endl;
    cout << emailAddress.toStdString() << endl;
    cout << username.toStdString() << endl;
    cout << password.toStdString() << endl;
}
