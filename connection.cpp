#include "connection.h"
//test 3
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("lina");//inserer nom de l'utilisateur
db.setPassword("linaoracle");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
