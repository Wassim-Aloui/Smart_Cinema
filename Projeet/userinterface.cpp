#include "userinterface.h"
#include "ui_userInterface.h"
#include <QMessageBox>
#include <qpixmap.h>



userInterface::userInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userInterface)
{
    ui->setupUi(this);

    //image admin
    QPixmap icon_admin(":icons/admin.png");
    ui->icon_admin->setPixmap(icon_admin.scaled(200,200,Qt::KeepAspectRatio));
    ui->tab_afficher_produit->setModel(Etmp.afficher_produit()); 
    ui->tab_afficher_commande->setModel(Com.afficher_commande());
    //allow user to use only numbers(commande inputs)
    ui->reference_commande_e->setValidator( new QIntValidator(0, 1000,this));
    ui->nombre_commande_e->setValidator( new QIntValidator(0, 1000,this) );
    ui->reference_commande_e2->setValidator( new QIntValidator(0, 1000,this));
    ui->nombre_commande_e2->setValidator( new QIntValidator(0, 1000, this) );
    ui->reference_commande_e3->setValidator( new QIntValidator(0, 1000, this) );
    ui->reference_commande_e3_2->setValidator( new QIntValidator(0, 1000, this) );
    //allow user to use only numbers(produit inputs)
    ui->id_produit_e->setValidator( new QIntValidator(0, 1000,this) );
    ui->nombre_produit_e->setValidator( new QIntValidator(0, 1000,this) );
    ui->id_produit_e_2->setValidator( new QIntValidator(0, 1000,this) );
    ui->nombre_produit_e2->setValidator( new QIntValidator(0, 1000,this) );
    ui->id_produit_e3->setValidator( new QIntValidator(0, 1000,this) );
    ui->id_produit_e4->setValidator( new QIntValidator(0, 1000,this) );

}

userInterface::~userInterface()
{
    delete ui;
}

void userInterface::on_g_prd_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void userInterface::on_g_cmd_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


//ajouter un produit(button ajouter)
void userInterface::on_ajouter_produit_clicked()
{
    int id_produit=ui->id_produit_e->text().toInt();
    QString nom_produit=ui->nom_produit_e->text();
    QString type_produit=ui->type_produit_e->text();
    int nombre_produit=ui->nombre_produit_e->text().toInt();
    produit p(id_produit,nom_produit,type_produit,nombre_produit);

    bool test =p.ajouter_Produit();
    if(test)
       {
         ui->tab_afficher_produit->setModel(Etmp.afficher_produit());
        QMessageBox::information(nullptr, QObject::tr("Produit ajouter"),
                     QObject::tr("Produit ajouter.\n"
                                 "Click Cancel to exit."), QMessageBox::Ok);}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Produit non ajouter"),
                     QObject::tr("Produit non ajouter.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }

}


//supprimer un produit(button supprimer)
void userInterface::on_supprimer_produit_clicked()
{
    int id_produit=ui->id_produit_e3->text().toInt();
    bool test=Etmp.supprimer_produit(id_produit);
    if(test)
    {   ui->tableView_supp_produit->setModel(Etmp.afficher_produit());
        QMessageBox::information(nullptr, QObject::tr("Produit a supprimer"),
                     QObject::tr("Produit supprimer.\n"
                                 "Click Cancel to exit."), QMessageBox::Ok);
    }
    else {
                    QMessageBox::critical(nullptr, QObject::tr("Produit a supprimer"),
             QObject::tr("Produit non supprimer.\n"
                         "Click Cancel to exit."), QMessageBox::Ok);
           }


}

//ajouter commande(button ajouter)
void userInterface::on_ajouter_commande_clicked()
{
    int reference=ui->reference_commande_e->text().toInt();
    QString etat_commande=ui->etat_commande_e->text();
    QString description=ui->Desc_commande_e->text();
    int nombre_commande=ui->nombre_commande_e->text().toInt();
    commande co(reference,description,etat_commande,nombre_commande);

    bool test =co.ajouter_commande();
    if(test)
       { ui->tab_afficher_commande->setModel(Com.afficher_commande());
        QMessageBox::information(nullptr, QObject::tr("Commande a ajouter"),
                     QObject::tr("Commande a  ajouter.\n"
                                 "Click Cancel to exit."), QMessageBox::Ok);}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Commande non ajouter"),
                     QObject::tr("Commande non ajouter.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

//suuprimer commande(button supprimer)
void userInterface::on_supprimer_commande_clicked()
{
    int reference=ui->reference_commande_e3->text().toInt();
    bool test=Com.supprimer_commande(reference);
    if(test)
    {     ui->tab_afficher_commande_2->setModel(Com.afficher_commande());
        QMessageBox::information(nullptr, QObject::tr("Commande a supprimer"),
                     QObject::tr("Produit supprimer.\n"
                                 "Click Cancel to exit."), QMessageBox::Ok);
    }
    else {
                    QMessageBox::critical(nullptr, QObject::tr("Commande a supprimer"),
             QObject::tr("Produit non supprimer.\n"
                         "Click Cancel to exit."), QMessageBox::Ok);
           }
}


void userInterface::on_radioButton_produit_clicked()
{
    ui->tab_afficher_produit->setModel(Etmp.afficher_produit());
}

void userInterface::on_radioButton_commande_clicked()
{
    ui->tab_afficher_commande->setModel(Com.afficher_commande());
}

//modifier commande(button modifier)
void userInterface::on_modifier_commande_clicked()
{
    int reference= ui->reference_commande_e2->text().toInt();
    QString description=ui->desc_commande_e->text();
    QString etat_commande= ui->etat_commande_e2->text();
    int nombre_commande= ui->nombre_commande_e2->text().toInt();
    commande c;
      if(c.recherche(reference))
     {
        bool test = c.modifier_commande(reference,description,etat_commande,nombre_commande);
        if(test)
          {
          ui->tab_afficher_commande->setModel(Com.afficher_commande());
          QMessageBox::information(nullptr,QObject::tr("commande modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
      }
       else
        QMessageBox::warning(nullptr,QObject::tr("reference non valide"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
}


//modifier produit(button modifier)
void userInterface::on_modifier_produit_clicked()
{
    int id_produit= ui->id_produit_e_2->text().toInt();
    QString nom_produit=ui->nom_produit_e2->text();
    QString type_produit= ui->type_produit2_e->text();
    int nombre_produit= ui->nombre_produit_e2->text().toInt();
    produit p;

         bool test = p.modifier_produit(id_produit,nom_produit,type_produit,nombre_produit);

          if(test)
            {  ui->tab_afficher_produit->setModel(Etmp.afficher_produit());

              QMessageBox::information(nullptr,QObject::tr("Produit modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
            }
 }


void userInterface::on_radioButto_afficher_commande_clicked()
{
  ui->recherche_tabViewx->setModel(Com.afficher_commande());
}

//chercher produit
void userInterface::on_chercher_produit_clicked()
{

    int id_produit =ui->id_produit_e4->text().toInt();
    QString nom_produit = ui->nom_produit_e4->text();
    QString type_produit = ui->type_produit_e4->text();
        if (id_produit!= 0){
       ui->recherche_tabView_2->setModel(Etmp.chercher_produit_id(id_produit)) ;}
        if (nom_produit != ""){
       ui->recherche_tabView_2->setModel(Etmp.chercher_produit_nom(nom_produit));}
        if (type_produit!= ""){
       ui->recherche_tabView_2->setModel(Etmp.chercher_produit_type(type_produit));}

}


void userInterface::on_radioButto_afficher_commande_2_clicked()
{
   ui->recherche_tabView_2->setModel(Etmp.afficher_produit());
}

//tri commande par refrence(reference button)
void userInterface::on_reference_commande_2_clicked()
{
    ui->tab_afficher_commande->setModel(Com.tri_commande_reference());
}
//tri commande par quantite(quantite button)
void userInterface::on_modifier_commande_3_clicked()
{
    ui->tab_afficher_commande->setModel(Com.tri_commande_quantite());
}
//Tri commande par type(type button)
void userInterface::on_modifier_commande_4_clicked()
{
    ui->tab_afficher_commande->setModel(Com.tri_commande_etat());
}

void userInterface::on_supprimer_2_clicked()
{
    ui->tab_afficher_produit->setModel(Etmp.tri_produit_id());
}


//Chercher commande
void userInterface::on_rechercher_commande_clicked()
{
    int reference =ui->reference_commande_e3_2->text().toUInt();
    int nombre_commande = ui->quantite_commande_e3->text().toUInt();
    QString etat_commande = ui->etat_commande_e3->text();
        if (reference!= 0){
       ui->recherche_tabViewx->setModel(Com.chercher_commande_reference(reference));}
        if (nombre_commande!= 0){
       ui->recherche_tabViewx->setModel(Com.chercher_commande_nombre(nombre_commande));}
        if (etat_commande!= ""){
       ui->recherche_tabViewx->setModel(Com.chercher_commande_etat(etat_commande));}
}


//tri des produit par id
void userInterface::on_afficher_id_produit_clicked()
{
ui->tab_afficher_produit->setModel(Etmp.tri_produit_id());
}
//tri des produit par nom
void userInterface::on_afficher_nom_produit_clicked()
{
    ui->tab_afficher_produit->setModel(Etmp.tri_produit_nom());
}

//tri des produit par nombre
void userInterface::on_afficher_nombre_produit_clicked()
{
    ui->tab_afficher_produit->setModel(Etmp.tri_produit_nombre());
}

void userInterface::on_radioButton_commande_2_clicked()
{
    ui->tab_afficher_commande_2->setModel(Com.afficher_commande());
}

void userInterface::on_radioButto_afficher_commande_3_clicked()
{
    ui->tableView_supp_produit->setModel(Etmp.afficher_produit());
}

void userInterface::on_pdf_commande_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
       printer->setOutputFormat(QPrinter::NativeFormat);
       printer->setPageSize(QPrinter::A4);
       printer->setOrientation(QPrinter::Portrait);
       printer->setFullPage(true);


   QPrintDialog *printDialog = new QPrintDialog(printer,this);
   printDialog->setWindowTitle("Impression PDF");
   if(printDialog->exec())
   {
      QPainter painter;
      if(painter.begin(printer))
      {
          double xscale = double(ui->recherche_tabViewx->width() / 65);
          double yscale = double(ui->recherche_tabViewx->height() / 65);
          painter.scale(xscale, yscale);
          ui->recherche_tabViewx->render(&painter);
          painter.end();
      }
      else
      {
          qWarning("failed to open file");
         QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
      }
   }
}

//Load reference commandein the comobbox
void userInterface::on_load_commande_ref_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT REFERENCE FROM COMMANDE");
    ui->comboBox_Commande->setModel(model);
}

//Load id produit in the combobox
void userInterface::on_load_produit_id_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT ID FROM PRODUIT");
    ui->comboBox_Produit->setModel(model);

}


void userInterface::on_statistique_prod_clicked()
{
    statistique *s=new statistique();
    s->show();
}
