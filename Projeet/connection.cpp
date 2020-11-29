#include "connection.h"

Connection::Connection()
{}

bool Connection::createconnect()
{bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet");//inserer le nom de la source de données ODBC
db.setUserName("wassim");//inserer nom de l'utilisateur
db.setPassword("esprit2020");//inserer mot de passe de cet utilisateur

if (db.open())  // si la database s'ouvre correctement
    test=true;

 return  test;

}

void Connection::closeconnexion()//fermer la database
{db.close();}












