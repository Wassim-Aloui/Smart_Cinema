#include "conge.h"

Conge::Conge()
{
    ref=duree=0;
    date_c=QDate(2000,01,01);
    type="";
    id_emp=0;
}


Conge::Conge(int ref, int duree,QDate date,QString type,int id_emp)
{
    this->ref=ref;
    this->duree=duree;
    this->date_c=date;
    this->type=type;
    this->id_emp=id_emp;
}
Conge::~Conge()
{

}

int Conge::getref(){
    return ref; }
    void Conge::setref(int ref){
        this->ref=ref; }
    int Conge::getduree(){
        return duree;
}
    void Conge::setduree(int duree){
        this->duree=duree; }

    QDate Conge::getdate(){
        return date_c;
    }

void Conge::setdate(QDate date_c){
        this->date_c=date_c;
}

QString Conge::gettype(){
    return type;
}
void Conge::settype(QString type )
{
    this->type=type;
}

int Conge::getid_emp(){
    return id_emp;
}
void Conge::setid_emp(int id_emp){
    this->id_emp=id_emp;
}



bool Conge::ajouter1(){
    QSqlQuery query;
    query.prepare("insert into Conge (ref,duree,date_c,type,id_emp) values (:ref,:duree,:date,:type,:id_emp)");
    query.bindValue(":ref",ref);
    query.bindValue(":duree",duree);
    query.bindValue(":date",date_c);
    query.bindValue(":type",type);
    query.bindValue(":id_emp",id_emp);

    return query.exec();
}

bool Conge::supprimer(int ref){

    QSqlQuery query;
    query.prepare("delete from Conge where ref=:ref");
    query.bindValue(":ref",ref);

    return query.exec();
}

bool Conge::modifier(int refc){
    QSqlQuery query;
    query.prepare("update Conge set ref=:ref,duree=:duree,date=:date,type=:type,id_emp=:id_emp where ref=:refc");
    query.bindValue(":id",ref);
    query.bindValue(":duree",duree);
    query.bindValue(":date",date_c);
    query.bindValue(":type",type);
    query.bindValue(":refc",refc);
    query.bindValue(":id_emp",id_emp);

    return query.exec();
}

QSqlQueryModel * Conge::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ref,duree,date_c,type,nom from Conge inner join employe on conge.id_emp=employe.id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMPLOYE"));

    return model;
}

Conge Conge::recherche_ref(int ref){
    QSqlQuery query;
    query.prepare("select *from Conge where ref=:ref");
    query.bindValue(":ref",ref);
    query.exec();
    Conge c;
    while(query.next()){
        c.setref(query.value(0).toInt());
        c.setduree(query.value(1).toInt());
        c.setdate(query.value(2).toDate());
        c.settype(query.value(3).toString());
       // e.setSalaire(query.value(4).toDouble());
    }

    return c;
}
