#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "gestionabonne.h"
#include"abonnee.h"
#include"abonnement.h"
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

gestionabonne g;
    Connection c;
    bool test=c.createconnect();

    if(test)
    {g.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

     return a.exec();
}
