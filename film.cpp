#include "film.h"

film::film()
{
    id_film=note=0;
    nom_film=date_sortie=duree=genre="";
}
film::film(int id_film ,QString nom_film,QString date_sortie,QString duree,int note,QString genre)
{
    this->id_film=id_film;
    this->nom_film=nom_film;
    this->date_sortie=date_sortie;
    this->duree=duree;
    this->note=note;
    this->genre=genre;
}
void film::setId_film(int id_film){
    this->id_film=id_film;
}
void film::setNom_film(QString nom_film){
    this->nom_film=nom_film;
}
void film::setDate_sortie(QString date_sortie){
    this->date_sortie=date_sortie;
}
void film::setDuree(QString duree){
    this->duree=duree;
}
void film::setNote(int note ){
    this->note=note;
}
void film::setGenre(QString genre){
    this->genre=genre;
}
QStringList film::listfilm(){
    QSqlQuery query;
    query.prepare("select * from film");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
int film::get_id_film(){return id_film;}
QString film::get_nom_film(){return nom_film ;}
QString film::get_date_sortie(){return date_sortie;}
QString film::get_duree(){return duree;}
int film::get_note(){return note;}
QString film::get_genre(){return genre;}

bool film::ajouter()
{
QSqlQuery query;
QString res=QString::number(id_film);
QString ress=QString::number(note);
query.prepare("INSERT INTO FILM (ID_film,NOM_film,DATE_SORTIE,DUREE,NOTE,GENRE) "
              "VALUES (:id_film,:nom_film,:date_sortie,:duree,:note,:genre)");

query.bindValue(":id_film", res);
query.bindValue(":nom_film", nom_film);
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
query.prepare("Delete from film where ID_film = :id_film ");
query.bindValue(":id_film", res);
return    query.exec();

}
bool film::modifier(int idc){
    QSqlQuery query;
    query.prepare("update film set id_film=:id_film,nom_film=:nom_film,date_sortie=:date_sortie,duree=:duree,note=:note,genre=:genre where id_film=:idc");
    query.bindValue(":id_film",id_film);
    query.bindValue(":nom_film",nom_film);
    query.bindValue(":date_sortie",date_sortie);
    query.bindValue(":duree",duree);
    query.bindValue(":note",note);
    query.bindValue(":genre",genre);
    query.bindValue(":idc",idc);

    return query.exec();
}
bool film::rech(int x){
    QSqlQuery query;
    query.prepare("select * from film where ID_film = :id_film;");
    query.bindValue(":id_film", x);
    return query.exec();
}

QSqlQueryModel *film::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;
    if(x=="Nom")
        model->setQuery("select * from FILM order by nom_film ");
    else if(x=="Note")
        model->setQuery("select * from FILM order by note ");
    else if (x=="Duree")
        model->setQuery("select * from FILM order by duree ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_film"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_film"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_sortie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("note"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));

        return model;
}
QSqlQueryModel *film::chercher_film_avancee(QString date_sortie,QString nom_film,QString genre)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM film WHERE upper(date_sortie) Like upper('%"+date_sortie+"%') and upper(nom_film) Like upper('%"+nom_film+"%') and upper(genre) like upper('%"+genre+"%') ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_film"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_film"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_sortie"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("note"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
        qDebug() << model;
        return model ;
    }
}

film film::recherche_Id_film(int id_film){
    QSqlQuery query;
    query.prepare("select *from film where id_film=:id_film");
    query.bindValue(":id__film",id_film);
    query.exec();
    film f;
    while(query.next()){
        f.setId_film(query.value(0).toInt());
        f.setNom_film(query.value(1).toString());
        f.setDate_sortie(query.value(2).toString());
        f.setDuree(query.value(3).toString());
        f.setNote(query.value(4).toInt());
        f.setGenre(query.value(5).toString());
    }


    return f;
}


