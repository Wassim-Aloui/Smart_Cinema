#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include"conge.h"

class employe
{
    int id;
    QString nom;
    QString prenom;
    QDate date_naissance;
    double salaire;
    QString email;


    Conge tmpconge;

public:
    employe();
    employe(int,QString,QString,QDate,double,QString);
    ~employe();

    int getId();
    void setId(int);
    QString getNom();
    void setNom(QString);
    QString getprenom();
    void setPrenom(QString);
    QDate getDate_naissance();
    void setDate_naissance(QDate);
    double getSalaire();
    void setSalaire(double);
    QString getEmail();
    void setEmail(QString);

    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher();
    employe recherche_Id(int);
    employe recherche_mail(QString);
    QSqlQueryModel * chercher_emp_avancee(QString nom,QString prenom,QString mail);
    QSqlQueryModel* trier();
    QSqlQueryModel* trier1();
    QSqlQueryModel* trier2();
    QSqlQueryModel * recherche_emp(const QString&);
    QSqlQueryModel * chercher_emp_nom_id(const QString &str);
     QSqlQueryModel * chercher_emp_nom_prenom(const QString &str);
      QSqlQueryModel * chercher_emp_id_prenom(const QString &str);
    QSqlQueryModel * chercher_employe_par_nom( QString);
    QSqlQueryModel * chercher_employe_par_prenom(QString);
    QSqlQueryModel * chercher_employe_par_id( int);
     QSqlQueryModel* Filter(int);
    QSqlQueryModel* rechercher(QString str,QString str1,int i); ///const QString & QString
    QStringList listemploye();
    QStringList listemploye1();
    int calcul_employe(int,int);

};

#endif // EMPLOYE_H
