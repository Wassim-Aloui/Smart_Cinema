#include "connexion.h"
#include "QSqlDatabase"

connexion::connexion()
{

}

bool connexion::createConnexion(){
    bool test=false;
    QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("data");
    db.setUserName("wassim");
    db.setPassword("esprit2020");

    if(db.open())
        test=true;
    return  test;



}
