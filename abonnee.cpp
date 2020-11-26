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
QString Abonnee ::get_prenom(){return prenom;}
QString Abonnee ::get_tarif(){return tarif;}
QString Abonnee ::get_ville(){return ville;}
int Abonnee ::get_id(){return id;}

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

bool Abonnee :: supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from abonnee where ID = :id");
    query.bindValue(":id",res);
    return query.exec();

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
    /*odel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("TARIF"));*/
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("TARIF"));
    return  model;
}
int Abonnee::calculer(int tarif)
{
    QSqlQuery query ;
    query.prepare("SELECT TARIF FROM abonnee;");
    query.bindValue(":tarif",tarif);
    query.exec();
    int total=0;
    while (query.next()){
        total++;
    }
    return total;
}
