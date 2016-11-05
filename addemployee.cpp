#include "addemployee.h"
#include "ui_addemployee.h"
#include <QLabel>
#include <QWidget>
#include <QDesktopWidget>
#include <iostream>
#include <QFont>

using namespace std;

addEmployee::addEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEmployee)
{
    QRect rec = QApplication::desktop()->screenGeometry();
    const int scrnHeight = rec.height(); // returns the height of the screen.
    const int scrnWidth = rec.width(); // returns the width of the screen.
    double boxWidth = scrnWidth * .35;
    double boxHeight = scrnHeight * .65;
    double fontSize = (boxWidth) * .02;
    int innerFrameX = boxWidth*.6;
    int innerFrameY = boxHeight*.6;
    ui->setupUi(this);
    QFont f("Arial", fontSize, QFont::Normal);
    this->resize(boxWidth,boxHeight);
    ui->frame_2->resize(innerFrameX,innerFrameY);
    ui->frame_2->move(boxWidth/2-innerFrameX/2,boxHeight/2-innerFrameY/2);
    ui->label->setFont(f); ui->label_2->setFont(f);ui->label_3->setFont(f);ui->label_6->setFont(f);ui->label_8->setFont(f);ui->label_9->setFont(f);ui->label_10->setFont(f);ui->label_11->setFont(f);
    ui->label->resize(innerFrameX*.3,innerFrameY*.2); ui->label->move(boxHeight/2-(innerFrameX*.3)/2,innerFrameY*.1);
}

addEmployee::~addEmployee()
{
    delete ui;
}

//Cancels out of sign in window
void addEmployee::on_cancelButton_clicked()
{
    QWidget::close();
}

void addEmployee::on_signInButton_clicked()
{

}

