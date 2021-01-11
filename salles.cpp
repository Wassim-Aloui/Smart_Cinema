#include "salles.h"
#include <QSqlQuery>


Salles::Salles()
{
    id=0;
    nomsalle="";
    capacite=0;
    numbloc=0;
}
Salles::Salles(int id,QString nomsalle,int capacite,int numbloc )
{
    this->id=id;
    this->nomsalle=nomsalle;
     this->capacite=capacite;
    this->numbloc=numbloc;
}
Salles::~Salles()
{

}


QString Salles::getnomsalle(){
    return nomsalle;
}
void Salles::setnomsalle(QString nomsalle){
    this->nomsalle=nomsalle;
}

int Salles::getId(){
    return id;
}
void Salles::setId(int id){
    this->id=id;
}
int Salles::getnumbloc(){
    return numbloc;
}
void Salles::setnumbloc(int numbloc){
    this->numbloc=numbloc;
}
int Salles::getcapacite(){
    return capacite;
}
void Salles::setcapacite(int capacite){
    this->capacite=capacite;
}





bool Salles::ajouter(){
    QSqlQuery query;
    query.prepare("insert into salles (id,nomsalle,numbloc,capacite) values (:id,:nomsalle,:numbloc,:capacite)");
    query.bindValue(":id",id);
    query.bindValue(":nomsalle",nomsalle);
    query.bindValue(":numbloc",numbloc);
    query.bindValue(":capacite",capacite);

    return query.exec();
}

bool Salles::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from salles where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from salles where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Salles::modifier(int idc ,QString nomsalle,int capacite,int numbloc){
    QSqlQuery query;
    query.prepare("update salles set nomsalle=:nomsalle,numbloc=:numbloc,capacite=:capacite where id=:idc");
    query.bindValue(":id",id);

    query.bindValue(":nomsalle",nomsalle);
    query.bindValue(":numbloc",numbloc);
    query.bindValue(":capacite",capacite);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Salles::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from salles");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));


    return model;
}


QSqlQueryModel * Salles::chercher_Salle_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salles WHERE NOMSALLE like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }

 }

QSqlQueryModel *Salles::chercher_Salle_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salles WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }
}
QSqlQueryModel * Salles::chercher_Salle_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salles WHERE capacite like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }

 }

QSqlQueryModel* Salles:: trier()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salles order by nomsalle ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}

QSqlQueryModel* Salles:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salles order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}
QSqlQueryModel* Salles:: trier2()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salles order by capacite ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}
QSqlQueryModel* Salles::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Salles WHERE NOMSALLE like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
    return model ;
}


 bool Salles::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from salles where NOMSALLE= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}


QStringList Salles::listeSalle(){
    QSqlQuery query;
    query.prepare("select * from Salles");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
QStringList Salles::listSalle1(){
    QSqlQuery query;
    query.prepare("select * from Salles");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(5).toString());
    }

    return list;

}


