#include "connection.h"
//test 3
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");//inserer le nom de la source de données ODBC
db.setUserName("wassim");//inserer nom de l'utilisateur
db.setPassword("esprit2020");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
