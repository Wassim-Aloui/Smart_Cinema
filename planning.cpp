#include "planning.h"
#include <QTextDocument>
#include <QPrinter>
planning::planning()
{
id_planning=0;
nom_planning=date_planning=heure="";
}
planning::planning(int id_planning, QString nom_planning,QString date_planning , QString heure )
{
    this->id_planning=id_planning;
    this->nom_planning=nom_planning;
    this->date_planning=date_planning;
    this->heure=heure;
}
QStringList planning::listplanning(){
    QSqlQuery query;
    query.prepare("select * from planning");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
int planning::get_id_planning(){return id_planning;}
QString planning::get_nom_planning(){return nom_planning ;}
QString planning::get_date_planning(){return date_planning;}
QString planning::get_heure(){return heure;}



void planning::setId_planning(int id_planning){
    this->id_planning=id_planning;
}
void planning::setNom_planning(QString nom_planning){
    this->nom_planning=nom_planning;
}
void planning::setDateplanning(QString date_planning){
    this->date_planning=date_planning;
}
void planning::setHeure(QString heure){
    this->heure=heure;
}

bool planning::ajouter()
{
QSqlQuery query;
QString res=QString::number(id_planning);
query.prepare("INSERT INTO PLANNING (ID_planning,NOM_planning,DATE_PLANNING,HEURE) "
              "VALUES (:id_planning,:nom_planning,:date_planning,:heure)");

query.bindValue(":id_planning", res);
query.bindValue(":nom_planning", nom_planning);
query.bindValue(":date_planning", date_planning);
query.bindValue(":heure", heure);
return    query.exec();
}
bool planning::supprimer(int idd)
{
QSqlQuery query;
QString res=QString::number(idd);
query.prepare("Delete from planning where ID_planning = :id_planning ");
query.bindValue(":id_planning", res);
return    query.exec();

}
bool planning::rech(int x){
    QSqlQuery query;
    query.prepare("select * from PLANNINGL where ID_planning = :id_planning;");
    query.bindValue(":id_planning", x);
    return query.exec();
}

planning planning::recherche_Id_planning(int id_planning){
    QSqlQuery query;
    query.prepare("select *from planning where id_planning=:id_planning");
    query.bindValue(":id_planning",id_planning);
    query.exec();
    planning p;
    while(query.next()){
        p.setId_planning(query.value(0).toInt());
        p.setNom_planning(query.value(1).toString());
        p.setDateplanning(query.value(2).toString());
        p.setHeure(query.value(3).toString());

    }


    return p;
}



bool planning::modifier(int idc){
    QSqlQuery query;
    query.prepare("update planning set id_planning=:id_planning,nom_planning=:nom_planning,date_planning=:date_planning,heure=:heure where id=:idc");
    query.bindValue(":id_planning",id_planning);
    query.bindValue(":nom_planning",nom_planning);
    query.bindValue(":date_planning",date_planning);
    query.bindValue(":heure",heure);

    query.bindValue(":idc",idc);

    return query.exec();
}


QSqlQueryModel *planning::chercher_planning_avancee(QString nom_planning,QString heure,QString date)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM planning WHERE upper(NOMplanning) Like upper('%"+nom_planning+"%') and upper(Heure) Like upper('%"+heure+"%') and upper(date_planning) like upper('%"+date+"%') ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_planning"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_planning"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PLANNING"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE"));
        qDebug() << model;
        return model ;
    }
}
QSqlQueryModel *planning::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;
    if(x=="Nom")
        model->setQuery("select * from PLANNING order by nom_planning ");
    else if(x=="Id")
        model->setQuery("select * from PLANNING order by id_planning ");
    else if (x=="Heure")
        model->setQuery("select * from PLANNING order by heure ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_planning"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_planning"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_planning"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("heure"));

        return model;
}


