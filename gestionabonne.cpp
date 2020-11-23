#include "gestionabonne.h"
#include "ui_gestionabonne.h"
#include "abonnee.h"
#include "abonnement.h"
#include<QMessageBox>
#include"connection.h"


gestionabonne::gestionabonne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionabonne)
{
    ui->setupUi(this);
    setWindowTitle("Gestion des abonnees et abonnements");
    ui->table_abonne->setModel(tmpabonnee.afficher());
    ui->id_abonne_e_1->setValidator (new QIntValidator(0,99999999, this));
    ui->id_modifier_abonne->setValidator(new QIntValidator(0,99999999,this));
ui->tab_abonnement->setModel(tmpabonnement.afficher());
    ui->num_abonnement_1->setValidator (new QIntValidator(0,99999999, this));
    ui->id_abonnement_2->setValidator(new QIntValidator(0,99999999,this));

//model = new CustomTableModel;






}

gestionabonne::~gestionabonne()
{
    delete ui;
}

void gestionabonne::on_g_abonnes_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void gestionabonne::on_g_abonnements_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void gestionabonne::on_ajouter_abonne_clicked()
{
int id = ui->id_abonne_e_1->text().toInt();
QString nom = ui->nom_abonne_e_2->text();
QString prenom = ui->prenom_abonne_e_3->text();
QString tarif = ui->tarif_abonnee_4->text();
QString ville = ui->ville_abonne_5->text();
Abonnee a(id,nom,prenom,tarif,ville);
bool test= a.ajouter();
if(test){

    ui->table_abonne->setModel(tmpabonnee.afficher());


    QMessageBox::information(nullptr, QObject::tr("Ajouter un abonnee"),
                QObject::tr("Abonnee ajoute.\n"),QMessageBox::Ok);
}
else   {
    QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonnee"),
                               QObject::tr("Abonnee non ajoute.\n"),QMessageBox::Ok);
}
}


void gestionabonne::on_supprimer_abonnee_clicked()
{
    int id= ui->id_supp_abonne->text().toInt();
   bool test = tmpabonnee.supprimer(id);
if(test)
{
    ui->table_abonne->setModel(tmpabonnee.afficher());
    QMessageBox::information(nullptr, QObject::tr("Supprimer un abonnee"),
                QObject::tr("Abonnee supprimé.\n"),QMessageBox::Ok);
}
else   {
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonnee"),
                               QObject::tr("Abonnee non supprimé.\n"),QMessageBox::Ok);
}
}

void gestionabonne::on_modifier_abonne_clicked()
{
    QString nom= ui->nom_abonne_e_4->text();
    QString prenom= ui->modifier_prenom->text();
    int id= ui->id_modifier_abonne->text().toInt();
    QString tarif= ui->modifier_tarif->text();
    QString ville= ui->modifier_ville->text();
      Abonnee a;
       if(a.rech(id)){
           bool test = a.modifier(id,nom,prenom,tarif,ville);
           if(test){

               ui->table_abonne->setModel(tmpabonnee.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("Modifier un abonnee"),
                           QObject::tr("Abonnee modifié.\n"),QMessageBox::Ok);
           }
           else   {
               QMessageBox::critical(nullptr, QObject::tr("Modifier un abonnee"),
                                          QObject::tr("Abonnee non modifié.\n"),QMessageBox::Ok);
           }
           }

           }

void gestionabonne::on_ajouter_abonnement_1_clicked()
{
    int num = ui->num_abonnement_1->text().toInt();
    int prix = ui->prix_abonnement_1->text().toInt();
    QString duree = ui->duree_abonnement_1->text();
       QString type = ui->type_abonnement_1->text();
       int id = ui->ida_abonnement_1->text().toInt();
    Abonnement b(num,prix,id,duree,type);
    bool test= b.ajouter();
    if(test){

        ui->tab_abonnement->setModel(tmpabonnement.afficher());


        QMessageBox::information(nullptr, QObject::tr("Ajouter un abonnement"),
                    QObject::tr("Abonnement ajoute.\n"),QMessageBox::Ok);
    }
    else   {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonnement"),
                                   QObject::tr("Abonnement non ajoute.\n"),QMessageBox::Ok);
    }
    }


void gestionabonne::on_supprimer_abonnement_3_clicked()
{

    int num= ui->id_abonnement_3->text().toInt();
   bool test = tmpabonnement.supprimer(num);
if(test)
{
    ui->tab_abonnement->setModel(tmpabonnement.afficher());
    QMessageBox::information(nullptr, QObject::tr("Supprimer un abonnement"),
                QObject::tr("Abonnement supprimé.\n"),QMessageBox::Ok);
}
else   {
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonnement"),
                               QObject::tr("Abonnement non supprimé.\n"),QMessageBox::Ok);
}
}
void gestionabonne::on_modifier_abonnement_2_clicked()
{

    int num= ui->id_abonnement_2->text().toInt();
   int prix= ui->prix_abonnement_2->text().toInt();
    QString duree= ui->duree_abonnement_2->text();
    QString type= ui->type_abonnement_2->text();
    int id= ui->ida_abonnement_2->text().toInt();
      Abonnement b;
       if(b.rech(num)){
           bool test = b.modifiera(num,prix,duree,type,id);
           if(test){

               ui->tab_abonnement->setModel(tmpabonnement.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("Modifier un abonnement"),
                           QObject::tr("Abonnement modifié.\n"),QMessageBox::Ok);
           }
           else   {
               QMessageBox::critical(nullptr, QObject::tr("Modifier un abonnement"),
                                          QObject::tr("Abonnement non modifié.\n"),QMessageBox::Ok);
           }
           }

}
void gestionabonne::on_chercher_abonnee_clicked()
{
        int id = ui->id_rech_abonne_5->text().toInt();
        QString nom = ui->nom_rech_abonne_5->text();
        QString prenom = ui->prenom_rech_abonne_5->text();
        ui->table_rech_abonne->setModel(tmpabonnee.search(id,nom,prenom));
}
void gestionabonne::on_radioButton_nom1_clicked()
{

    bool test = tmpabonnee.tri();
    if(test){
       ui->table_tri_abonne->setModel(tmpabonnee.tri());
       QMessageBox::information(nullptr, QObject::tr("Tri des noms"),
                   QObject::tr("Abonnes triés.\n"),QMessageBox::Ok);
   }
   else   {
       QMessageBox::critical(nullptr, QObject::tr("Tri des noms"),
                                  QObject::tr("Abonnes non triés.\n"),QMessageBox::Ok);
   }

}
void gestionabonne::on_radioButton_4_clicked()
{Abonnement b;
bool test=tmpabonnement.triduree();
if(test)
{
    ui->tab_tri_abonnement->setModel(tmpabonnement.triduree());
        QMessageBox::information(nullptr, QObject::tr("Tri des durées"),
                                   QObject::tr("Abonnements triés.\n"),QMessageBox::Ok);
                     }
                     else   {
                        QMessageBox::critical(nullptr, QObject::tr("Tri des durées"),
                                                QObject::tr("Abonnements non triés.\n"),QMessageBox::Ok);
                     }

}

void gestionabonne::on_radioButton_ville_clicked()
{
    bool test = tmpabonnee.triville();
    if(test){
       ui->table_tri_abonne->setModel(tmpabonnee.triville());
       QMessageBox::information(nullptr, QObject::tr("Tri des villes"),
                   QObject::tr("Abonnes triés.\n"),QMessageBox::Ok);
   }
   else   {
       QMessageBox::critical(nullptr, QObject::tr("Tri des villes"),
                                  QObject::tr("Abonnes non triés.\n"),QMessageBox::Ok);
   }
}

void gestionabonne::on_radioButton_tarif_clicked()
{ bool test = tmpabonnee.tritarif();
    if(test){
       ui->table_tri_abonne->setModel(tmpabonnee.tritarif());
       QMessageBox::information(nullptr, QObject::tr("Tri des tarifs"),
                   QObject::tr("Abonnes triés.\n"),QMessageBox::Ok);
   }
   else   {
       QMessageBox::critical(nullptr, QObject::tr("Tri des tarifs"),
                                  QObject::tr("Abonnes non triés.\n"),QMessageBox::Ok);
   }

}

void gestionabonne::on_stat_abonnee_clicked()
{
       ui->tableViewstat->setModel(tmpabonnee.stat());


}

void gestionabonne::on_typeButton_clicked()
{
    ui->tab_tri_abonnement->setModel(tmpabonnement.tritype());
}

void gestionabonne::on_prixButton_clicked()
{
    ui->tab_tri_abonnement->setModel(tmpabonnement.triprix());
}

void gestionabonne::on_afficher_abonne_clicked()
{
    ui->table_abonne->setModel(tmpabonnee.afficher());
}
