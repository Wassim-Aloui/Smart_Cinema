#include "film.h"

film::film()
{
    id=note=0;
    nom=date_sortie=duree=genre="";
}
film::film(int id ,QString nom,QString date_sortie,QString duree,int note,QString genre)
{
    this->id=id;
    this->nom=nom;
    this->date_sortie=date_sortie;
    this->duree=duree;
    this->note=note;
    this->genre=genre;
}
int film::get_id(){return id;}
QString film::get_nom(){return nom ;}
QString film::get_date_sortie(){return date_sortie;}
QString film::get_duree(){return duree;}
int film::get_note(){return note;}
QString film::get_genre(){return genre;}

bool film::ajouter()
{
QSqlQuery query;
QString res=QString::number(id);
QString ress=QString::number(note);
query.prepare("INSERT INTO FILM (ID,NOM,DATE_SORTIE,DUREE,NOTE,GENRE) "
              "VALUES (:id,:nom,:date_sortie,:duree,:note,:genre)");

query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":date_sortie", date_sortie);
query.bindValue(":duree", duree);
query.bindValue(":note", ress);
query.bindValue(":genre", genre);

return    query.exec();
}

bool film::supprimer(int idd)
{
QSqlQuery query;
QString res=QString::number(idd);
query.prepare("Delete from film where ID = :id ");
query.bindValue(":id", res);
return    query.exec();

}
bool film::modifier(int a,QString b,QString c,QString d, int e,QString f){
    QSqlQuery query;
    QString res=QString::number(a);
    query.prepare("UPDATE film set nom=:nom ,date_sortie=:date_sortie,duree=:duree,note=:note,genre=:genre  where id ='"+res+"'");
    query.bindValue(":id",a);
    query.bindValue(":nom", b);
    query.bindValue(":date_sortie", c);
    query.bindValue(":duree", d);
    query.bindValue(":note", e);
    query.bindValue(":genre", f);

    return query.exec();
}
bool film::rech(int x){
    QSqlQuery query;
    query.prepare("select * from film where ID = :id;");
    query.bindValue(":id", x);
    return query.exec();
}
QSqlQueryModel* film::rechercher(QString a,QString b , QString c )
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FILM where ID ='"+a+"' and NOM ='"+b+"' and GENRE ='"+c+"' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_sortie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("note"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
        return model;

}

