#include "abonnement.h"
#include "abonnee.h"
Abonnement::Abonnement()
{
num=prix=id=0;
duree=type="";
}
Abonnement::Abonnement(int num,int prix,int id,QString duree,QString type)
{
this->num=num;
this->prix=prix;
this->duree=duree;
this->type=type;
this->id=id;
}
int Abonnement ::get_num(){return num;}
int Abonnement ::get_prix(){return prix;}
int Abonnement ::get_id(){return id;}
QString Abonnement ::get_duree(){return duree;}
QString Abonnement ::get_type(){return type;}

bool Abonnement::ajouter()
{
    QSqlQuery query ;
    QString res=QString::number(num);
    QString p=QString::number(prix);
     QString j=QString::number(id);
    query.prepare("INSERT INTO abonnement (NUM,PRIX,DUREE,TYPE,ID_ABONNEE) VALUES (:num,:prix,:duree,:type,:id)");
    query.bindValue(":num",res);
     query.bindValue(":prix",p);
      query.bindValue(":duree",duree);
      query.bindValue(":type",type);
       query.bindValue(":id",id);

return query.exec();
}
QSqlQueryModel * Abonnement::afficher(){

    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM abonnement");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PRIX"));
     model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DUREE"));
      model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TYPE"));
       model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ID_ABONNEE"));
       return model;

}
bool Abonnement :: supprimer(int n)
{
    QSqlQuery query;
    QString res= QString::number(n);
    query.prepare("Delete from abonnement where NUM = :num");
    query.bindValue(":num",res);


    return query.exec();

}
bool Abonnement::modifiera(int n,int p,QString d,QString t,int i){
    QSqlQuery query;
    QString res=QString::number(n);
    /*QString r=QString::number(p);
    QString id=QString::number(i);*/
    query.prepare("UPDATE Abonnement set num=:num ,prix=:prix ,duree=:duree ,type=:type ,id_abonnee=:id where num ='"+res+"'");
    query.bindValue(":num",n);
    query.bindValue(":prix",p);
    query.bindValue(":duree",d);
    query.bindValue(":type",t);
    query.bindValue(":id",i);
    return query.exec();
}
bool Abonnement::rech(int y){
    QSqlQuery query;
    query.prepare("select * from Abonnement where NUM = :num;");
    query.bindValue(":num", y);
    return query.exec();
}
QSqlQueryModel * Abonnement::triduree(){

    QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("select * from Abonnement ORDER BY DUREE");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
   model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PRIX"));
   model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DUREE"));
   model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TYPE"));
   model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ID_ABONNEE"));
     return  model;
}
QSqlQueryModel * Abonnement::tritype(){

    QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("select * from Abonnement ORDER BY TYPE");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
   model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PRIX"));
   model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DUREE"));
   model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TYPE"));
   model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ID_ABONNEE"));
     return  model;
}
QSqlQueryModel * Abonnement::triprix(){

    QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("select * from Abonnement ORDER BY PRIX");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
   model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PRIX"));
   model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DUREE"));
   model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TYPE"));
   model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ID_ABONNEE"));
     return  model;
}
QSqlQueryModel * Abonnement::searchnum(int num)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(num);
    model->setQuery("select * from ABONNEMENT where NUM like '"+res+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DUREE"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ID_ABONNEE"));
     return model;
}
QSqlQueryModel * Abonnement::searchduree(QString duree)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ABONNEMENT where DUREE like '"+duree+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DUREE"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ID_ABONNEE"));
     return model;
}
QSqlQueryModel * Abonnement::searchtype(QString type)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ABONNEMENT where TYPE like '"+type+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DUREE"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ID_ABONNEE"));
     return model;
}
QSqlQueryModel * Abonnement::statis(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT count (*)as nombre, type FROM ABONNEMENT GROUP BY TYPE;");
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("TYPE"));
    return  model;
}
int Abonnement::calculertype1(int)
    {
        QSqlQuery query ;
        QSqlQuery q("select * from ABONNEMENT where TYPE='Cinepass duo'") ;
        int total=0;
        while (q.next()){
            total++;
        }
        return total;
    }
int Abonnement::calculertype2(int){
    QSqlQuery query ;
    QSqlQuery q("select * from ABONNEMENT where TYPE='Cinepass'");
    int total=0;
    while (q.next()){
        total++;
    }
    return total;
}
int Abonnement::calculertype3(int){
    QSqlQuery query ;
    QSqlQuery q("select * from ABONNEMENT where TYPE='Cinepass -26'") ;
    int total=0;
    while (q.next()){
        total++;
    }
    return total;
}
QSqlQueryModel * Abonnement::ajout(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT id FROM abonnee WHERE NOT EXISTS (SELECT id_abonnee FROM ABONNEMENT WHERE ABONNEE.id = abonnement.id_abonnee)");
    model->setHeaderData(0, Qt::Horizontal,  QObject::tr("ID de l'ABONNE"));
    return  model;
}

