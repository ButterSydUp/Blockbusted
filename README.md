# Blockbusted
This is the Blockbusted Video Project for CS433

stufffffff

There's a problem with adding .pro and .pro.user files
Therefore if you want to start from scratch you have to create a new project in Qt and love the files over.
Download the .zip, unzip it and move the files into your new project's location, replacing the prefabed 
main.cpp, mainwindow.cpp, mainwindow.h, and mainwindow.ui

Append "sql" to the provided (7th) line on your .pro:
"QT       += core gui"

Therefore it'll look like this:
"QT       += core gui sql "

Also the only other change necessary is in the dbmanager.cpp file
line 2 needs to be you specific absolute path to the blockbusted_db.db file
