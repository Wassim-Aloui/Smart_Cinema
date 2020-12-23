#ifndef ABONNEE_H
#define ABONNEE_H
#include<QString>
#include<QSqlQuery>
#include <QSqlQueryModel>
#include<QtCharts>
#include<QVBarModelMapper>
#include<QSqlRelationalTableModel>
#include<QVariant>

class Abonnee
{
public:
    Abonnee();
    Abonnee(int,QString,QString,QString,QString);
   int get_id();
    void setId(int);
   QString get_nom();
     void setnom(QString);
   QString get_prenom();
    void setprenom(QString);
   QString get_tarif();
    void settarif(QString);
   QString get_ville();
    void setville(QString);

        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int,QString,QString,QString,QString);
        bool rech(int x);
        void setid(int i) { id = i; }

QSqlQueryModel * searchid(int);
QSqlQueryModel * searchnom(QString);
QSqlQueryModel * searchprenom(QString);

QSqlQueryModel * tri();
QSqlQueryModel * tritarif();
QSqlQueryModel * triville();
QSqlQueryModel * stat();

int calculer(int);
int calculerenfant(int);
int calculertarif(int);



private :
         int id;
         QString  nom,prenom,tarif,ville;

};
#endif // ABONNEE_H
