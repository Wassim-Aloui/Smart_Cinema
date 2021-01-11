#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"user_interface.h"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    user_interface u;
    login l;
    Connection c;
    c.createconnect();
    l.show();

    return a.exec();
}
