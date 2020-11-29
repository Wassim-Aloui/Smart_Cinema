#include "commande.h"

commande::commande()
{
    reference=0;
    nombre_commande=0;
    etat_commande="";
    description="";
}

commande::commande(int reference,QString description ,QString etat_commande,int nombre_commande)
{
    this->reference=reference;
    this->nombre_commande=nombre_commande;
    this->etat_commande=etat_commande;
    this->description=description;
}

//fonction ajouter commande
bool commande::ajouter_commande()
{
    QSqlQuery query;
    QString res=QString::number(reference);
    QString ress=QString::number(nombre_commande);
    query.prepare("INSERT INTO COMMANDE(REFERENCE,DESCRIPTION,ETAT,NOMBRE) VALUES (:reference,:description,:etat_commande,:nombre_commande);");
    query.bindValue(":reference",res);
    query.bindValue(":description",description);
    query.bindValue(":etat_commande",etat_commande);
    query.bindValue(":nombre_commande",ress);
    return query.exec();
}

//fonction supprimer commande
bool commande::supprimer_commande(int reference)
{
QSqlQuery query;
QString res=QString::number(reference);
query.prepare("Delete from COMMANDE where REFERENCE = :reference ");
query.bindValue(":reference", res);
return    query.exec();

}

//fonction afficher commande
QSqlQueryModel * commande::afficher_commande()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM COMMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
   return model;
}

//fonction modifier commande
bool commande::modifier_commande(int new_ref, QString new_desc, QString new_etat, int new_nombre){
    QSqlQuery query;
    QString res=QString::number(new_ref);
    query.prepare("UPDATE COMMANDE set DESCRIPTION=:description ,ETAT=:etat_commande ,NOMBRE=:nombre_commande where REFERENCE ='"+res+"'");
   // query.bindValue(":reference",new_ref);
    query.bindValue(":description", new_desc);
    query.bindValue(":etat_commande",new_etat);
    query.bindValue(":nombre_commande",new_nombre);
    return query.exec();
}

//recherche id commande
bool commande::recherche(int x)
{
    QSqlQuery query;
    query.prepare("select * from COMMANDE where REFERENCE = :reference;");
    query.bindValue(":reference", x);
    return query.exec();
}
/*
//rechercher commande
QSqlQueryModel * commande::rechercher_commande(int new_reference,int new_quantite)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(new_reference);
    QString ress=QString::number(new_quantite);
    model->setQuery("select * from COMMANDE where REFERENCE like '"+res+"%' or NOMBRE like '"+ress+"%'   ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model;

}*/
//rechercher commande par reference
QSqlQueryModel * commande::chercher_commande_reference(int new_reference)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        QString res=QString::number(new_reference);
        model->setQuery("SELECT * FROM COMMANDE WHERE REFERENCE like '"+res+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
        return model ;
    }

 }

//rechercher commande par nombre
QSqlQueryModel * commande::chercher_commande_nombre(int new_nombre)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        QString res=QString::number(new_nombre);
        model->setQuery("SELECT * FROM COMMANDE WHERE NOMBRE like '"+res+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
        return model ;
    }

 }

//rechercher commande par etat
QSqlQueryModel * commande::chercher_commande_etat(QString new_etat)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;

        model->setQuery("SELECT * FROM COMMANDE WHERE ETAT like '"+new_etat+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
        return model ;
    }

 }


//Tri commande par reference
QSqlQueryModel * commande :: tri_commande_reference()
{    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from COMMANDE ORDER BY REFERENCE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model;
}
//Tri commande par quantite
QSqlQueryModel * commande :: tri_commande_quantite()
{    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from COMMANDE ORDER BY NOMBRE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model;

}
//Tri commande par type
QSqlQueryModel * commande :: tri_commande_etat()
{    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from COMMANDE ORDER BY ETAT ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model;
}
