#ifndef FILM_H
#define FILM_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class film
{
public:
    film();
    film(int,QString,QString,QString,int,QString);
    int get_id();
    QString get_nom();
    QString get_date_sortie();
    QString get_duree();
    int get_note();
    QString get_genre();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int);
    bool modifier(int,QString,QString,QString,int,QString);
    bool rech(int x);
    QSqlQueryModel*rechercher(QString a,QString b,QString c);
private:
    QString nom,date_sortie,duree,genre;
    int id,note;
};

#endif // FILM_H
