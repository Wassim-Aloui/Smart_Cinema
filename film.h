#ifndef FILM_H
#define FILM_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDebug>
#include<QFile>
#include <QFileDialog>
#include <QCoreApplication>
#include <QTextStream>
#include<QTableView>
class film
{
public:
    film();
    film(int,QString,QString,QString,int,QString);
    int get_id_film();
    QString get_nom_film();
    QString get_date_sortie();
    QString get_duree();
    int get_note();
    QString get_genre();
    void setId_film(int);
    void setNom_film(QString);
    void setDate_sortie(QString);
    void setDuree(QString);
    void setNote(int);
    void setGenre(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int);
    bool modifier(int);
    bool rech(int x);
    QSqlQueryModel * chercher_film_avancee(QString date_sortie,QString nom_film,QString genre);
    QSqlQueryModel * trier(QString);

    QStringList listfilm();
     film recherche_Id_film(int);
private:
    QString nom_film,date_sortie,duree,genre;
    int id_film,note;
};

#endif // FILM_H
