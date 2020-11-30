#include "employe.h"
#include<QtDebug>
employe::employe()
{
    id=0;
    date_naissance=QDate(2000,01,01);
    salaire=0;
}
//test2

employe::employe(int id,QString nom,QString prenom,QDate date_naissance,double salaire,QString email)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->date_naissance=date_naissance;
    this->salaire=salaire;
    this->email=email;
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
QString employe::getEmail(){
    return email;
}
void employe::setEmail(QString email){
    this->email=email;
}




bool employe::ajouter(){
    QSqlQuery query;
    query.prepare("insert into employe (id,nom,prenom,date_naissance,salaire,email) values (:id,:nom,:prenom,:date_naissance,:salaire,:email)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":salaire",salaire);
    query.bindValue(":email",email);

    return query.exec();
}

bool employe::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from employe where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery q;
        q.prepare("select * from conge where id_emp=:idemp");
        q.bindValue(":idemp",id);
        q.exec();
        while(q.next()){
            tmpconge.supprimer(q.value(0).toInt());
        }

        QSqlQuery query;
        query.prepare("delete from employe where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

QSqlQueryModel *employe::chercher_emp_avancee(QString nom,QString prenom,QString email)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM employe WHERE upper(NOM) Like upper('"+nom+"%') and upper(prenom) Like upper('"+prenom+"%') and upper(email) like upper('"+email+"%') ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
        qDebug() << model;
        return model ;
    }
}
bool employe::modifier(int idc){
    QSqlQuery query;
    query.prepare("update employe set id=:id,nom=:nom,prenom=:prenom,date_naissance=:date_naissance,salaire=:salaire,email=:email where id=:idc");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":salaire",salaire);
    query.bindValue(":email",email);
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
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

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
QSqlQueryModel * employe::chercher_employe_par_nom( QString n)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM EMPLOYE WHERE NOM like '"+n+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
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
QSqlQueryModel *employe::chercher_employe_par_id(int idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        QString res=QString::number(idd);
        model->setQuery("SELECT * FROM EMPLOYE WHERE ID like '"+res+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));
        return model ;
    }
}
QSqlQueryModel * employe::chercher_emp_nom_id(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where nom like '"+str+"%' or id like '"+str+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));


    return model;
}
QSqlQueryModel * employe::chercher_emp_nom_prenom(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where nom like '"+str+"%' or prenom like '"+str+"%'" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));


    return model;
}
QSqlQueryModel *employe::chercher_emp_id_prenom(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where id like '"+str+"%' or prenom like '"+str+"%'" );
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
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
        e.setEmail(query.value(5).toString());
    }

    return e;
}

employe employe::recherche_mail(QString mail){
    QSqlQuery query;
    query.prepare("select *from employe where email like '"+mail+"' ");
    query.bindValue(":email",email);
    query.exec();
    employe e;
    while(query.next()){
        e.setId(query.value(0).toInt());
        e.setNom(query.value(1).toString());
        e.setPrenom(query.value(2).toString());
        e.setDate_naissance(query.value(3).toDate());
        e.setSalaire(query.value(4).toDouble());
        e.setEmail(query.value(5).toString());
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

QStringList employe::listemploye(){
    QSqlQuery query;
    query.prepare("select * from employe");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
QStringList employe::listemploye1(){
    QSqlQuery query;
    query.prepare("select * from employe");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(5).toString());
    }

    return list;

}
QSqlQueryModel * employe::recherche_emp(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employet where nom like '"+str+"%' or id like '"+str+"%' or prenom like '"+str+"%'");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}

int employe::calcul_employe(int min, int max){
    QSqlQuery query;
    query.prepare("select *from employe where salaire between :min and :max");
    query.bindValue(":min",min);
    query.bindValue(":max",max);
    query.exec();

    int total=0;
    while(query.next()){
        total++;
    }

    return total;
}
