#include "employe.h"

employe::employe()
{
    id=0;
    date_naissance=QDate(2000,01,01);
    salaire=0;
}
//testt2

employe::employe(int id,QString nom,QString prenom,QDate date_naissance,double salaire)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->date_naissance=date_naissance;
    this->salaire=salaire;
}
employe::~employe()
{

}


QString employe::getNom(){
    return nom;
}
void employe::setNom(QString nom){
    this->nom=nom;
}
QString employe::getprenom(){
    return prenom;
}
int employe::getId(){
    return id;
}
void employe::setId(int id){
    this->id=id;
}
void employe::setPrenom(QString prenom){
    this->prenom=prenom;
}
QDate employe::getDate_naissance(){
    return date_naissance;
}
void employe::setDate_naissance(QDate date_naissance){
    this->date_naissance=date_naissance;
}
double employe::getSalaire(){
    return salaire;
}
void employe::setSalaire(double salaire){
    this->salaire=salaire;
}

bool employe::ajouter(){
    QSqlQuery query;
    query.prepare("insert into employe (id,nom,prenom,date_naissance,salaire) values (:id,:nom,:prenom,:date_naissance,:salaire)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":salaire",salaire);

    return query.exec();
}

bool employe::supprimer(int id){
    QSqlQuery query;
    query.prepare("delete from employe where id=:id");
    query.bindValue(":id",id);

    return query.exec();
}

bool employe::modifier(int idc){
    QSqlQuery query;
    query.prepare("update employe set id=:id,nom=:nom,prenom=:prenom,date_naissance=:date_naissance,salaire=:salaire where id=:idc");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":salaire",salaire);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * employe::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));

    return model;
}

/*QSqlQueryModel* employe::rechercher(QString str,QString str1,int i) ///const QString &str
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe where nom like '"+str+"%' or prenom like '"+str1+"%' or id=:i   ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));
    return model;
}*/
QSqlQueryModel * employe::chercher_employe_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM EMPLOYE WHERE NOM like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));
        return model ;
    }

 }
QSqlQueryModel * employe::chercher_employe_par_prenom(QString p)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM EMPLOYE WHERE PRENOM like '"+p+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));
        return model ;
    }

 }
QSqlQueryModel *employe::chercher_employe_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM EMPLOYE WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));
        return model ;
    }
}

QSqlQueryModel* employe:: trier()
{
 //order by extract (year from date_naissance)
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe order by (date_naissance)DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));

    return model;
}

QSqlQueryModel* employe:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe order by nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));

    return model;
}
QSqlQueryModel* employe:: trier2()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe order by prenom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));

    return model;
}

employe employe::recherche_Id(int id){
    QSqlQuery query;
    query.prepare("select *from employe where id=:id");
    query.bindValue(":id",id);
    query.exec();
    employe e;
    while(query.next()){
        e.setId(query.value(0).toInt());
        e.setNom(query.value(1).toString());
        e.setPrenom(query.value(2).toString());
        e.setDate_naissance(query.value(3).toDate());
        e.setSalaire(query.value(4).toDouble());
    }

    return e;
}
QSqlQueryModel* employe::Filter(int){
    QSqlQueryModel* model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from citoyen where sexe='"+res+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE N"));

    return model;
}
