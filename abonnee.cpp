#include "abonnee.h"

Abonnee::Abonnee()
{
id=0;
nom=prenom=tarif=ville="";
}
Abonnee::Abonnee(int id ,QString nom ,QString prenom,QString tarif,QString ville){
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->tarif=tarif;
    this->ville=ville;
}
QString Abonnee ::get_nom(){return nom;}
void Abonnee::setnom(QString nom){
    this->nom=nom;}
QString Abonnee ::get_prenom(){return prenom;}
void Abonnee::setprenom(QString prenom){
    this->prenom=prenom;}
QString Abonnee ::get_tarif(){return tarif;}
void Abonnee::settarif(QString tarif){
    this->tarif=tarif;}
QString Abonnee ::get_ville(){return ville;}
void Abonnee::setville(QString ville){
    this->ville=ville;}
int Abonnee ::get_id(){return id;}
void Abonnee::setId(int id){
    this->id=id;}

bool Abonnee::ajouter()
{
    QSqlQuery query ;
    QString res=QString::number(id);
    query.prepare("INSERT INTO abonnee (ID,NOM,PRENOM,TARIF,VILLE) VALUES (:id,:nom,:prenom,:tarif,:ville)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tarif",tarif);
    query.bindValue(":ville",ville);

return query.exec();
}
QSqlQueryModel * Abonnee::afficher(){

    QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("SELECT * FROM abonnee");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal,  QObject::tr("PRENOM"));
     model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TARIF"));
     model->setHeaderData(4, Qt::Horizontal,  QObject::tr("VILLE"));
       return model;

}

bool Abonnee :: supprimer(int id)
{
    QSqlQuery q;
    QString res= QString::number(id);
    q.prepare("select * from abonnee where ID = :id");
    q.bindValue(":id",res);
    q.exec();
    int total=0; //s'il n'existe pas
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from abonnee where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }

}
bool Abonnee::modifier(int i,QString b,QString c,QString d,QString e){
    QSqlQuery query;
    QString res=QString::number(i);
    query.prepare("UPDATE Abonnee set nom=:nom ,prenom=:prenom ,tarif=:tarif,ville=:ville  where id ='"+res+"'");
    query.bindValue(":id",i);
    query.bindValue(":nom", b);
    query.bindValue(":prenom",c);
    query.bindValue(":tarif",d);
    query.bindValue(":ville",e);
    return query.exec();
}
bool Abonnee::rech(int x){
    QSqlQuery query;
    query.prepare("select * from Abonnee where ID = :id;");
    query.bindValue(":id", x);
    return query.exec();
}
QSqlQueryModel * Abonnee::searchid(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from ABONNEE where ID like '"+res+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TARIF"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("VILLE"));
     return model;
}
QSqlQueryModel * Abonnee::searchnom(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ABONNEE where NOM like '"+nom+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TARIF"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("VILLE"));
     return model;
}
QSqlQueryModel * Abonnee::searchprenom(QString prenom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ABONNEE where PRENOM like '"+prenom+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TARIF"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("VILLE"));
     return model;
}
 QSqlQueryModel * Abonnee::tri()
{
   QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("select * from abonnee ORDER BY NOM");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NOM"));
   model->setHeaderData(2, Qt::Horizontal,  QObject::tr("PRENOM"));
   model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TARIF"));
   model->setHeaderData(4, Qt::Horizontal,  QObject::tr("VILLE"));
     return  model;
}
QSqlQueryModel * Abonnee::triville()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from abonnee ORDER BY VILLE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TARIF"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("VILLE"));
      return  model;
}

QSqlQueryModel * Abonnee::tritarif()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from abonnee ORDER BY TARIF");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TARIF"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("VILLE"));
      return  model;
}
QSqlQueryModel * Abonnee::stat(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT count (*)as nombre, tarif FROM ABONNEE GROUP BY TARIF;");
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("TARIF"));
    return  model;
}
int Abonnee::calculer(int)
{
    QSqlQuery query ;
    QSqlQuery q("select * from ABONNEE where TARIF='Etudiant'") ;
    int total=0;
    while (q.next()){
        total++;
    }
    return total;
}
int Abonnee::calculerenfant(int )
{
    QSqlQuery query ;
    QSqlQuery q("select * from ABONNEE where TARIF='Enfant'") ;
    int total=0;
    while (q.next()){
        total++;
    }
    return total;
}
int Abonnee::calculertarif(int)
{
    QSqlQuery query ;
    QSqlQuery q("select * from ABONNEE where TARIF='Tarif plein'") ;
    int total=0;
    while (q.next()){
        total++;
    }
    return total;
}
