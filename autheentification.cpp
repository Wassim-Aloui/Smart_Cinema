#include "autheentification.h"
#include "ui_autheentification.h"

autheentification::autheentification(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::autheentification)
{
    ui->setupUi(this);
}

autheentification::~autheentification()
{
    delete ui;
}
