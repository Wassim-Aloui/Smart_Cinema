#include "planning.h"
#include <QTextDocument>
#include <QPrinter>
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
int planning::get_id(){return id;}
QString planning::get_nom(){return nom ;}
QString planning::get_date_planning(){return date_planning;}
QString planning::get_heure(){return heure;}



void planning::setId(int id){
    this->id=id;
}
void planning::setNom(QString nom){
    this->nom=nom;
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

planning planning::recherche_Id(int id){
    QSqlQuery query;
    query.prepare("select *from planning where id=:id");
    query.bindValue(":id",id);
    query.exec();
    planning p;
    while(query.next()){
        p.setId(query.value(0).toInt());
        p.setNom(query.value(1).toString());
        p.setDateplanning(query.value(2).toString());
        p.setHeure(query.value(3).toString());

    }


    return p;
}



bool planning::modifier(int idc){
    QSqlQuery query;
    query.prepare("update planning set id=:id,nom=:nom,date_planning=:date_planning,heure=:heure where id=:idc");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":date_planning",date_planning);
    query.bindValue(":heure",heure);

    query.bindValue(":idc",idc);

    return query.exec();
}


QSqlQueryModel *planning::chercher_planning_avancee(QString nom,QString heure,QString date)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM planning WHERE upper(NOM) Like upper('%"+nom+"%') and upper(Heure) Like upper('%"+heure+"%') and upper(date_planning) like upper('%"+date+"%') ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
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
        model->setQuery("select * from PLANNING order by nom ");
    else if(x=="Id")
        model->setQuery("select * from PLANNING order by id ");
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

