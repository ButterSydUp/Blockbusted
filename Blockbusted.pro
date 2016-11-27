#-------------------------------------------------
#
# Project created by QtCreator 2016-10-05T10:48:28
#
#-------------------------------------------------

QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Blockbusted
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    emp_verification.cpp \
    addcustomer.cpp \
    dbmanager.cpp \
    edit_inventory.cpp \
    remove_employee.cpp \
    edit_employee.cpp \
    edit_customer.cpp \
    remove_customer.cpp

HEADERS  += mainwindow.h \
    emp_verification.h \
    addcustomer.h \
    dbmanager.h \
    edit_inventory.h \
    remove_employee.h \
    edit_employee.h \
    edit_customer.h \
    remove_customer.h

FORMS    += mainwindow.ui \
    emp_verification.ui \
    addcustomer.ui \
    edit_inventory.ui \
    remove_employee.ui \
    edit_employee.ui \
    edit_customer.ui \
    remove_customer.ui

DISTFILES +=
