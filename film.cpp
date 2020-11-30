#include "film.h"

film::film()
{
    id=note=0;
    nom=date_sortie=duree=genre="";
}
film::film(int id ,QString nom,QString date_sortie,QString duree,int note,QString genre)
{
    this->id=id;
    this->nom=nom;
    this->date_sortie=date_sortie;
    this->duree=duree;
    this->note=note;
    this->genre=genre;
}
void film::setId(int id){
    this->id=id;
}
void film::setNom(QString nom){
    this->nom=nom;
}
void film::setDate_sortie(QString date_sortie){
    this->date_sortie=date_sortie;
}
void film::setDuree(QString duree){
    this->duree=duree;
}
void film::setNote(int note ){
    this->note=note;
}
void film::setGenre(QString genre){
    this->genre=genre;
}
QStringList film::listfilm(){
    QSqlQuery query;
    query.prepare("select * from film");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
int film::get_id(){return id;}
QString film::get_nom(){return nom ;}
QString film::get_date_sortie(){return date_sortie;}
QString film::get_duree(){return duree;}
int film::get_note(){return note;}
QString film::get_genre(){return genre;}

bool film::ajouter()
{
QSqlQuery query;
QString res=QString::number(id);
QString ress=QString::number(note);
query.prepare("INSERT INTO FILM (ID,NOM,DATE_SORTIE,DUREE,NOTE,GENRE) "
              "VALUES (:id,:nom,:date_sortie,:duree,:note,:genre)");

query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":date_sortie", date_sortie);
query.bindValue(":duree", duree);
query.bindValue(":note", ress);
query.bindValue(":genre", genre);

return    query.exec();
}

bool film::supprimer(int idd)
{
QSqlQuery query;
QString res=QString::number(idd);
query.prepare("Delete from film where ID = :id ");
query.bindValue(":id", res);
return    query.exec();

}
bool film::modifier(int idc){
    QSqlQuery query;
    query.prepare("update film set id=:id,nom=:nom,date_sortie=:date_sortie,duree=:duree,note=:note,genre=:genre where id=:idc");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":date_sortie",date_sortie);
    query.bindValue(":duree",duree);
    query.bindValue(":note",note);
    query.bindValue(":genre",genre);
    query.bindValue(":idc",idc);

    return query.exec();
}
bool film::rech(int x){
    QSqlQuery query;
    query.prepare("select * from film where ID = :id;");
    query.bindValue(":id", x);
    return query.exec();
}

QSqlQueryModel *film::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;
    if(x=="Nom")
        model->setQuery("select * from FILM order by nom ");
    else if(x=="Note")
        model->setQuery("select * from FILM order by note ");
    else if (x=="Duree")
        model->setQuery("select * from FILM order by duree ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_sortie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("note"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));

        return model;
}
QSqlQueryModel *film::chercher_film_avancee(QString id,QString nom,QString genre)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM film WHERE upper(ID) Like upper('%"+id+"%') and upper(nom) Like upper('%"+nom+"%') and upper(genre) like upper('%"+genre+"%') ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_sortie"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("note"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
        qDebug() << model;
        return model ;
    }
}
void film::exporter(QTableView *table)
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
film film::recherche_Id(int id){
    QSqlQuery query;
    query.prepare("select *from film where id=:id");
    query.bindValue(":id",id);
    query.exec();
    film f;
    while(query.next()){
        f.setId(query.value(0).toInt());
        f.setNom(query.value(1).toString());
        f.setDate_sortie(query.value(2).toString());
        f.setDuree(query.value(3).toString());
        f.setNote(query.value(4).toInt());
        f.setGenre(query.value(5).toString());
    }


    return f;
}


