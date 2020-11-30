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
    int get_id();
    QString get_nom();
    QString get_date_sortie();
    QString get_duree();
    int get_note();
    QString get_genre();
    void setId(int);
    void setNom(QString);
    void setDate_sortie(QString);
    void setDuree(QString);
    void setNote(int);
    void setGenre(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int);
    bool modifier(int);
    bool rech(int x);
    QSqlQueryModel * chercher_film_avancee(QString id,QString nom,QString genre);
    QSqlQueryModel * trier(QString);
    void exporter(QTableView *table);
    QStringList listfilm();
     film recherche_Id(int);
private:
    QString nom,date_sortie,duree,genre;
    int id,note;
};

#endif // FILM_H
