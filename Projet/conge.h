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
    int id_emp;


public:
     int calcul_conge(int,int);
    Conge();
     Conge(int,int,QDate,QString,int);
     ~Conge();
     QSqlQueryModel* trier();
     QSqlQueryModel* trier1();
     QSqlQueryModel* trier2();
     QStringList listconge();
     QStringList listconge1();
     int getref();
     void setref(int);
     int getduree();
     void setduree(int);
     QDate getdate();
     void setdate(QDate);
     QString gettype();
     void settype(QString);
     int getid_emp();
     void setid_emp(int);

     bool ajouter1();
     bool supprimer(int);
     bool modifier(int);
     QSqlQueryModel * chercher_cng_avancee(QString ,QString  ,QString );
     QSqlQueryModel* afficher();
     Conge recherche_ref(int);
     QSqlQueryModel * chercher_conge_par_duree( int);
     QSqlQueryModel * chercher_conge_par_type(QString);
     QSqlQueryModel * chercher_conge_par_ref( int);
};

#endif // CONGE_H
