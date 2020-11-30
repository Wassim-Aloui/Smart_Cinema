#include "conge.h"
#include<QtDebug>
Conge::Conge()
{
    ref=duree=0;
    date_c=QDate(2000,01,01);
    type="";
    id_emp=0;
}

QStringList Conge::listconge(){
    QSqlQuery query;
    query.prepare("select * from conge");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
QStringList Conge::listconge1(){
    QSqlQuery query;
    query.prepare("select * from conge");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(5).toString());
    }

    return list;

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
QSqlQueryModel* Conge:: trier()
{

    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from conge order by id_emp ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID EMPLOYE"));

    return model;
}

QSqlQueryModel* Conge:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from conge order by duree ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID EMPLOYE"));
    return model;
}
QSqlQueryModel* Conge:: trier2()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from conge order by type ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID EMPLOYE"));

    return model;
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

QSqlQueryModel * Conge::chercher_conge_par_duree( int d)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        QString res=QString::number(d);
        model->setQuery("SELECT * FROM Conge WHERE duree like '"+res+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID EMPLOYE"));
        return model;
    }

 }
QSqlQueryModel* Conge::chercher_conge_par_type( QString t)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM conge WHERE type like '"+t+"%'  ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID EMPLOYE"));
        return model;
    }

 }


QSqlQueryModel *Conge::chercher_cng_avancee(QString  r,QString  r1,QString r2)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
          QString res=QString::number(ref);
        QString res1=QString::number(duree);

        model->setQuery("SELECT * FROM conge WHERE upper(res) Like upper('"+r+"%') and upper(res1) Like upper('"+r1+"%') and upper(type) like upper('"+r2+"%') ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID EMPLOYE"));
        qDebug() << model;
        return model ;
    }
}





QSqlQueryModel *Conge::chercher_conge_par_ref(int reff)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        QString res=QString::number(reff);
        model->setQuery("SELECT * FROM Conge WHERE ref like '"+res+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID EMPLOYE"));
        return model;
    }
}
bool Conge::supprimer(int ref){

    QSqlQuery q;
    q.prepare("select * from conge where ref=:id");
    q.bindValue(":id",ref);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from Conge where ref=:ref");
        query.bindValue(":ref",ref);

        return query.exec();
    }
    else{
        return false;
    }

}

bool Conge::modifier(int refc){
    QSqlQuery query;
    query.prepare("update Conge set duree=:duree,date_c=:date,type=:type where ref=:refc");
    query.bindValue(":duree",duree);
    query.bindValue(":date",date_c);
    query.bindValue(":type",type);
    query.bindValue(":refc",refc);

    return query.exec();
}



QSqlQueryModel * Conge::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ref,duree,date_c,type,id,nom from Conge inner join employe on conge.id_emp=employe.id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr(" ID EMPLOYE"));

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
int Conge::calcul_conge(int min, int max){
    QSqlQuery query;
    query.prepare("select *from conge where duree between :min and :max");
    query.bindValue(":min",min);
    query.bindValue(":max",max);
    query.exec();

    int total=0;
    while(query.next()){
        total++;
    }

    return total;
}
