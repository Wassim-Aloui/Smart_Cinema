#include "test.h"
#include<QSqlQuery>
#include<QString>
#include <QSqlQueryModel>
#include <QDebug>
test::test()
{
       QSqlQuery query;
       int i= 30;
       QString b="mariem";
       QString c="mazouz";
       query.prepare("select nom from Abonnee where ID = :id, nom=:nom ,prenom=:prenom;");
       query.bindValue(":id",i);
       query.bindValue(":nom", b);
       query.bindValue(":prenom",c);
       /*while (query.next()) {
               QString c = query.value(0).toString();*/

               int amount = 100;
               qDebug() << "You have obtained" << amount << "apples!";
return ;
}

