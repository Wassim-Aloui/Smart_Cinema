#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class commande
{
public:
    commande();
    commande(int,QString,QString,int);
    //getters
    int get_reference(){return  reference;}
    QString get_etat_commande(){return  etat_commande;}
    QString get_disc_commande(){return description;}
    int get_nombre_commande(){return  nombre_commande;}
   //setters
    int set_reference();
    QString set_etat_commande();
    QString set_disc_commande();
    int set_nombre_commande();
    //fct bdd
    bool ajouter_commande();
    bool  supprimer_commande(int);
    QSqlQueryModel * afficher_commande();
    bool modifier_commande(int,QString,QString,int);
    bool recherche(int);
   // QSqlQueryModel * rechercher_commande(int new_reference,int new_nombre);
    QSqlQueryModel * chercher_commande_reference(int new_ref);
    QSqlQueryModel * chercher_commande_nombre(int new_nombre);
    QSqlQueryModel * chercher_commande_etat(QString new_etat);
    QSqlQueryModel * tri_commande_reference();
    QSqlQueryModel * tri_commande_quantite();
    QSqlQueryModel * tri_commande_etat();


private:
    int reference,nombre_commande;
    QString etat_commande,description;

  };

#endif // COMMANDE_H
