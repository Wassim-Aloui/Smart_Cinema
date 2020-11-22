#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include<QString>
#include<QSqlQuery>
#include <QSqlQueryModel>
class Abonnement
{
public:
 Abonnement();
 Abonnement(int,int,int,QString,QString);
       int get_num();
       int get_prix();
       int get_id();
        QString get_duree();
        QString get_type();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifiera(int,int,QString,QString,int);
        bool rech(int y);
        QSqlQueryModel * triduree();
        QSqlQueryModel * tritype();
        QSqlQueryModel * triprix();
private :
         int num,prix,id;
         QString  duree,type;
};

#endif // ABONNEMENT_H
