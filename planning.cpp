#include "planning.h"
#include <QDebug>
planning::planning()
{
id=0;
nom=date_planning=heure="";
}
planning::planning(int id, QString nom,QString date_planning , QString heure )
{
    this->id=id;
    this->nom=nom;
    this->date_planning=date_planning;
    this->heure=heure;
}
int planning::get_id(){return id;}
QString planning::get_nom(){return nom ;}
QString planning::get_date_planning(){return date_planning;}
QString planning::get_heure(){return heure;}

bool planning::ajouter()
{
QSqlQuery query;
QString res=QString::number(id);
query.prepare("INSERT INTO PLANNING (ID,NOM,DATE_PLANNING,HEURE) "
              "VALUES (:id,:nom,:date_planning,:heure)");

query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":date_planning", date_planning);
query.bindValue(":heure", heure);
return    query.exec();
}
bool planning::supprimer(int idd)
{
QSqlQuery query;
QString res=QString::number(idd);
query.prepare("Delete from planning where ID = :id ");
query.bindValue(":id", res);
return    query.exec();

}
bool planning::rech(int x){
    QSqlQuery query;
    query.prepare("select * from PLANNINGL where ID = :id;");
    query.bindValue(":id", x);
    return query.exec();
}
bool planning::modifier(int a,QString b,QString c,QString d){
    QSqlQuery query;
    QString res=QString::number(a);
    query.prepare("UPDATE planning set nom=:nom ,date_planning=:date_planning,heure=:heure  where id ='"+res+"'");
    query.bindValue(":id",a);
    query.bindValue(":nom", b);
    query.bindValue(":date_planning", c);
    query.bindValue(":heure", d);
    return query.exec();
}
QSqlQueryModel * planning::chercher_planning_date(QString date)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM PLANNING WHERE DATE_PLANNING='"+date+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PLANNING"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE"));
        return model ;
    }

 }
QSqlQueryModel * planning::chercher_planning_heure(QString heure)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM PLANNING WHERE HEURE='"+heure+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PLANNING"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE"));
        return model ;
    }

 }
QSqlQueryModel *planning::chercher_planning_nom(QString nom)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM planning WHERE NOM = '"+nom+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PLANNING"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE"));
        return model ;
    }
}
QSqlQueryModel *planning::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;
    if(x=="Nom")
        model->setQuery("select * from PLANNING order by nom ");
    else if(x=="Date")
        model->setQuery("select * from PLANNING order by date_planning ");
    else if (x=="Heure")
        model->setQuery("select * from PLANNING order by heure ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_planning"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("heure"));

        return model;
}

void planning::exporter(QTableView *table)
{
    QString filters("CSV files (.csv);;All files (.*)");
    QString defaultFilter("csv files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                    filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }
}

