#include "connection.h"
//test 3
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");//inserer le nom de la source de données ODBC
db.setUserName("mariem");//inserer nom de l'utilisateur
db.setPassword("esprit17");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
