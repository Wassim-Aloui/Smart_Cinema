#include "produit.h"

produit::produit()
{
    id_produit=0;
    nombre_produit=0;
    nom_produit="";
    type_produit="";

}

produit::produit(int id_produit,QString nom_produit,QString type_produit,int nombre_produit )
{
    this->id_produit=id_produit;
    this->nom_produit=nom_produit;
    this->type_produit=type_produit;
    this->nombre_produit=nombre_produit;
}

//Fonction ajouter produit
bool produit::ajouter_Produit()
{
    QSqlQuery query;
    QString res=QString::number(id_produit);
    QString ress=QString::number(nombre_produit);
    query.prepare("INSERT INTO PRODUIT(ID,NOM,TYPE,NOMBRE) VALUES(:id_produit,:nom_produit,:type_produit,:nombre_produit);");
    query.bindValue(":id_produit",res);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":type_produit",type_produit);
    query.bindValue(":nombre_produit",ress);
    return query.exec();
}
 //Fonction supprimer produit
bool produit::supprimer_produit(int id_produit)
{
QSqlQuery query;
QString res=QString::number(id_produit);
query.prepare("Delete from PRODUIT where ID = :id_produit ");
query.bindValue(":id_produit", res);
return query.exec();

}

//Fonction afficher produit
QSqlQueryModel * produit::afficher_produit()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM PRODUIT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE"));
   return model;
}

//Fonction modifier produit
bool produit::modifier_produit(int new_id, QString new_nom, QString new_type, int new_nombre){
    QSqlQuery query;
    QString res=QString::number(new_id);
    query.prepare("UPDATE PRODUIT set NOM=:nom_produit ,TYPE=:type_produit ,NOMBRE=:nombre_produit where ID ='"+res+"'");
    query.bindValue(":id_produit",new_id);
    query.bindValue(":nom_produit", new_nom);
    query.bindValue(":type_produit",new_type);
    query.bindValue(":nombre_produit",new_nombre);
    return query.exec();
}
//chercher id produit
bool produit::recherche(int x)
{
    QSqlQuery query;
    query.prepare("select * from PRODUIT where ID= :id_produit;");
    query.bindValue(":reference", x);
    return query.exec();
}

/*QSqlQueryModel * produit::rechercher_produit(int new_id, QString new_nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(new_id);

    //model->setQuery("select * from PRODUIT where ID ='"+res+"' or NOM ='"+new_nom+"'");
    model->setQuery("select * from PRODUIT where ID ='"+res+"' or NOM like '"+new_nom+"%'   ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE"));

        return model;

}*/

//Fonction chercher produit par id
QSqlQueryModel * produit::chercher_produit_id(int new_id)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        QString res=QString::number(new_id);
        model->setQuery("SELECT * FROM PRODUIT WHERE ID like '"+res+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE"));
        return model ;
    }

 }

//Fonction chercher produit par nom
QSqlQueryModel * produit::chercher_produit_nom(QString new_nom)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM PRODUIT WHERE NOM like '"+new_nom+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE"));
        return model ;
    }

 }

//Fonction chercher produit par type
QSqlQueryModel *produit::chercher_produit_type(QString new_type)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM PRODUIT WHERE TYPE like '"+new_type+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE"));
        return model ;
    }
}
 //Fonction tri produit par id
QSqlQueryModel * produit :: tri_produit_id()
{    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PRODUIT ORDER BY ID ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE"));


        return model;
}

//Fonction tri produit par nom
QSqlQueryModel * produit :: tri_produit_nom()
{    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PRODUIT ORDER BY NOM ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE"));


        return model;
}

//Fonction tri produit par nombre
QSqlQueryModel * produit :: tri_produit_nombre()
{    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PRODUIT ORDER BY NOMBRE ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE"));


        return model;
}

//calcul stat produit
int produit::calcul_produit(int min, int max){
    QSqlQuery query;
    query.prepare("select *from PRODUIT where NOMBRE between :min and :max");
    query.bindValue(":min",min);
    query.bindValue(":max",max);
    query.exec();

    int total=0;
    while(query.next()){
        total++;
    }
    return total;
}



