#include "authentification.h"
#include "ui_authentification.h"
#include "Admin.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

#include <QMessageBox>
#include <QColor>
#include <QPalette>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableWidget>
#include <QPixmap>
authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
}

authentification::~authentification()
{
    delete ui;
}


