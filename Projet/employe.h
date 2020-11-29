#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>

class employe
{
    int id;
    QString nom;
    QString prenom;
    QDate date_naissance;
    double salaire;
    QString email;

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
    QSqlQueryModel* trier();
    QSqlQueryModel* trier1();
    QSqlQueryModel* trier2();
    QSqlQueryModel * chercher_employe_par_nom(QString m);
    QSqlQueryModel * chercher_employe_par_prenom(QString p);
    QSqlQueryModel * chercher_employe_par_id(QString idd);
     QSqlQueryModel* Filter(int);
    //QSqlQueryModel* rechercher(QString str,QString str1,int i); ///const QString & QString
    QStringList listemploye();
    QStringList listemploye1();
    int calcul_employe(int,int);

};

#endif // EMPLOYE_H
