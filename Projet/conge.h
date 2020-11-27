#ifndef CONGE_H
#define CONGE_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
class Conge
{
    int ref;
    int duree;
    QDate date_c;
    QString type;


public:
    Conge();
     Conge(int,int,QDate,QString);
     ~Conge();

     int getref();
     void setref(int);
     int getduree();
     void setduree(int);
     QDate getdate();
     void setdate(QDate);
     QString gettype();
     void settype(QString);


     bool ajouter1();
     bool supprimer(int);
     bool modifier(int);
     QSqlQueryModel* afficher();
     Conge recherche_ref(int);
};

#endif // CONGE_H
