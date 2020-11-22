#ifndef ABONNEE_H
#define ABONNEE_H
#include<QString>
#include<QSqlQuery>
#include <QSqlQueryModel>
#include<QtCharts>
#include<QVBarModelMapper>
#include<QSqlRelationalTableModel>


class Abonnee
{
public:
    Abonnee();
    Abonnee(int,QString,QString,QString,QString);
   int get_id();
    QString get_nom();
     QString get_prenom();
       QString get_tarif();
        QString get_ville();

        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
       bool modifier(int,QString,QString,QString,QString);
        bool rech(int x);
        void setid(int i) { id = i; }
QSqlQueryModel * search(int,QString,QString);
 QSqlQueryModel * tri();
  QSqlQueryModel * tritarif();
 QSqlQueryModel * triville();
 QSqlQueryModel * stat();
private :
         int id;
         QString  nom,prenom,tarif,ville;

};
#endif // ABONNEE_H
