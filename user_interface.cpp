#include "user_interface.h"
#include "ui_user_interface.h"
#include"planning.h"
#include"film.h"
#include<QMessageBox>
user_interface::user_interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user_interface)
{
    ui->setupUi(this);
    ui->tab_affichage_planning->setModel(tmpplanning.afficher());
    ui->id_planning_e_1->setValidator(new QIntValidator(0,99999999,this));
    ui->id_planning_e_2->setValidator(new QIntValidator(0,99999999,this));
    ui->id_planning_e_3->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_affichage_film->setModel(tmpfilm.afficher());
    ui->id_film_e->setValidator(new QIntValidator(0,99999999,this));
    ui->id_film_e_2->setValidator(new QIntValidator(0,99999999,this));
    ui->id_film_e_3->setValidator(new QIntValidator(0,99999999,this));
}

user_interface::~user_interface()
{
    delete ui;
}

void user_interface::on_g_film_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void user_interface::on_g_plng_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void user_interface::on_ajouter_planning_clicked()
{
   int id= ui->id_planning_e_1->text().toInt();
    QString nom= ui->nom_planning_e_1->text();
    QString date_planning = ui->date_planning_e_1->text();
    QString heure = ui->heure_e_1->text();
    planning p(id,nom,date_planning,heure);
    bool test=p.ajouter();
    if (test)
    {
        ui->tab_affichage_planning->setModel(tmpplanning.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un planning"),
                    QObject::tr("planning ajouté.\n"
                                "Click ok to exit."), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un planning"),
                    QObject::tr("planning non ajouté.\n"
                                "Click ok to exit."), QMessageBox::Ok);
    }
}
QSqlQueryModel * planning::afficher()
{
   QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from planning");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PLANNING"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE"));
    return model;
}

void user_interface::on_supprimer_planning_clicked()

    {
        int id = ui->id_planning_e_3->text().toInt();
        bool test=tmpplanning.supprimer(id);
        if(test)
        {ui->tab_affichage_planning->setModel(tmpplanning.afficher());//refresh


            QMessageBox::information(nullptr, QObject::tr("Supprimer un planning"),
                        QObject::tr("planning supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un planning"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }

void user_interface::on_modifier_planning_clicked()

    {

             QString nom= ui->nom_planning_e_2->text();

             QString date_planning= ui->date_planning_e_2->text();
             int id= ui->id_planning_e_2->text().toInt();

             QString heure= ui->heure_e_2->text();

               planning p;
                if(p.rech(id)){
                    bool test = p.modifier(id,nom,date_planning,heure);
                    if(test){

                        ui->tab_affichage_planning->setModel(tmpplanning.afficher());

                        QMessageBox::information(nullptr,QObject::tr("planning modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);

                    }
                }


}

void user_interface::on_ajouter_film_clicked()
{
    int id= ui->id_film_e->text().toInt();
     QString nom= ui->nom_film_e->text();
     QString date_sortie = ui->date_sortie_e->text();
     QString duree = ui->duree_e->text();
     int note= ui->note_e->text().toInt();
      QString genre= ui->genre_e->text();
     film f(id,nom,date_sortie,duree,note,genre);
     bool test=f.ajouter();
     if (test)
     {
         ui->tab_affichage_film->setModel(tmpfilm.afficher());
         QMessageBox::information(nullptr, QObject::tr("Ajouter un film"),
                     QObject::tr("film ajouté.\n"
                                 "Click ok to exit."), QMessageBox::Ok);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un film"),
                     QObject::tr("film non ajouté.\n"
                                 "Click ok to exit."), QMessageBox::Ok);
     }
}
QSqlQueryModel * film::afficher()
{
   QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from film");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_SORTIE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOTE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GENRE"));
    return model;
}


void user_interface::on_supprimer_film_clicked()
{
    int id = ui->id_film_e_3->text().toInt();
    bool test=tmpfilm.supprimer(id);
    if(test)
    {ui->tab_affichage_film->setModel(tmpfilm.afficher());//refresh


        QMessageBox::information(nullptr, QObject::tr("Supprimer un film"),
                    QObject::tr("film supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un film"
                                                   ""),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void user_interface::on_modifier_film_clicked()
{

    QString nom= ui->nom_film_e_2->text();

    QString date_sortie= ui->date_sortie_e_2->text();
    int id= ui->id_film_e_2->text().toInt();
    QString duree= ui->duree_e_2->text();
    QString genre= ui->genre_e_2->text();
    int note= ui->note_e_2->text().toInt();
      film f;
       if(f.rech(id)){
           bool test = f.modifier(id,nom,date_sortie,duree,note,genre);
           if(test){

               ui->tab_affichage_film->setModel(tmpfilm.afficher());

               QMessageBox::information(nullptr,QObject::tr("film modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);

           }
       }


}

void user_interface::on_chercher_film_clicked()
{
    QString id = ui->id_film_e_4->text();
    QString nom = ui->nom_film_e_4->text();
    QString genre = ui->genre_film_e_4->text();
    ui->tableView_recherche->setModel(tmpfilm.rechercher(id,nom,genre));
}


void user_interface::on_Trier_planning_clicked()
{
    QString l=ui->comboBox_Planning->currentText();
    ui->tab_affichage_planning->setModel(tmpplanning.trier(l));
}



void user_interface::on_Exporter_planning_clicked()
{
    tmpplanning.exporter(ui->tab_affichage_planning);
        ui->statusbar->showMessage("EXPORT TABLE ",5000);
}

void user_interface::on_chercher_planning_clicked()
{
    QString m =ui->date_planning_e_4->text();
        QString k = ui->heure_planning_e_4->text();
        QString l = ui->nom_planning_e_4->text();
        if (k != ""){
       ui->tableView_planning->setModel(tmpplanning.chercher_planning_heure(k)) ;}
        if (l != ""){
       ui->tableView_planning->setModel(tmpplanning.chercher_planning_nom(l)) ;}
        if (m!= ""){
       ui->tableView_planning->setModel(tmpplanning.chercher_planning_date(m)) ;
        }
}
