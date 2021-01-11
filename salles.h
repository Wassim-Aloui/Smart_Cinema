#ifndef SALLES_H
#define SALLES_H
#include <QString>
#include <QSqlQueryModel>

class Salles
{
    int id;
    QString nomsalle;
    int numbloc;
    int capacite;
    public:
    Salles();
       Salles(int,QString,int,int);
       ~Salles();

       int getId();
       void setId(int);
       QString getnomsalle();
       void setnomsalle(QString);
       int getnumbloc();
       void setnumbloc(int);
       int getcapacite();
       void setcapacite(int);

       bool ajouter();
       bool supprimer(int);
       bool modifier(int,QString,int,int);
       QSqlQueryModel* afficher();
       QSqlQueryModel* recherche_nom(QString);
       Salles recherche_mail(QString);
       bool verifierExnoms(QString);

       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();
       QSqlQueryModel* trier2();
       QSqlQueryModel * chercher_Salle_par_nom(QString m);
       QSqlQueryModel * chercher_Salle_par_capacite(QString m);

       QSqlQueryModel * chercher_Salle_par_id(QString idd);
        QSqlQueryModel* Filter(int);

       QStringList listeSalle();
       QStringList listSalle1();
       int calcul_Salle(int,int);


};

#endif // SALLES_H
