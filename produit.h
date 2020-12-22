#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class produit
{
public:
    produit();
    produit(int,QString,QString,int);
    //getters
    int get_id_produit();
    QString get_nom_produit();
    QString get_type_produit();
    int get_nombre_produit();
    //setters
    int set_id_produit();
    QString set_nom_produit();
    QString set_type_produit();
    int set_nombre_produit();
    //fct BDD
    bool ajouter_Produit();
    bool  supprimer_produit(int);
    bool modifier_produit(int,QString,QString,int);
    QSqlQueryModel * afficher_produit();
    bool recherche(int);
    //QSqlQueryModel * rechercher_produit(int new_id,QString new_nom);
    QSqlQueryModel * chercher_produit_id(int new_id);
    QSqlQueryModel * chercher_produit_nom(QString new_nom);
    QSqlQueryModel * chercher_produit_type(QString new_type);
    QSqlQueryModel * tri_produit_id();
    QSqlQueryModel * tri_produit_nom();
    QSqlQueryModel * tri_produit_nombre();
    int calcul_produit(int,int);



private:
    int id_produit,nombre_produit;
    QString nom_produit,type_produit;
};

#endif // PRODUIT_H
