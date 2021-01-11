#include "admin.h"
#include <QSqlQuery>
Admin::Admin()
{
    id=0;
    nom="";
    prenom="";
    username="";
    password="";
}
Admin::Admin(int id,QString nom,QString prenom,QString username,QString password )
{
    this->id=id;
    this->nom=nom;
     this->prenom=prenom;
    this->username=username;
    this->password=password;
}
Admin::~Admin()
{

}


QString Admin::getNom(){
    return nom;
}
void Admin::setNom(QString nom){
    this->nom=nom;
}

int Admin::getId(){
    return id;
}
void Admin::setId(int id){
    this->id=id;
}
QString Admin::getusername(){
    return username;
}
void Admin::setusername(QString username){
    this->username=username;
}
QString Admin::getpassword(){
    return password;
}
void Admin::setpassword(QString password){
    this->password=password;
}





bool Admin::ajouter(){
    QSqlQuery query;
    query.prepare("insert into compte (id,nom,prenom,username,password) values (:id,:nom,:prenom,:username,:password)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":username",username);
    query.bindValue(":password",password);

    return query.exec();
}

bool Admin::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from compte where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from compte where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Admin::modifier(int idc ,QString nom,QString prenom,QString username,QString password){
    QSqlQuery query;
    query.prepare("update compte set nom=:nom,prenom=:prenom,username=:username,password=:password where id=:idc");
    query.bindValue(":id",id);

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Admin::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from compte");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("USERNAME"));
    return model;
}

/*
QSqlQueryModel * Admin::chercher_Salle_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE NOMSALLE like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }

 }

QSqlQueryModel *Admin::chercher_Salle_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }
}
QSqlQueryModel * Admin::chercher_Salle_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE capacite like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));
        return model ;
    }

 }

QSqlQueryModel* Admin:: trier()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by nomsalle ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}

QSqlQueryModel* Admin:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}
QSqlQueryModel* Admin:: trier2()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by capacite ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMBLOC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CAPACITE"));

    return model;
}*/
QSqlQueryModel* Admin::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Compte WHERE NOM like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("USERNAME"));
    return model ;
}


 bool Admin::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from compte where NOM= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}

/*
QStringList Admin::listeSalle(){
    QSqlQuery query;
    query.prepare("select * from Salle");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
QStringList Admin::listSalle1(){
    QSqlQuery query;
    query.prepare("select * from Salle");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(5).toString());
    }

    return list;

}

*/
