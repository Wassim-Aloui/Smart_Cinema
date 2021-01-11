#include "userinterface.h"
#include "ui_userInterface.h"


userInterface::userInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userInterface)
{
    ui->setupUi(this);


    //Arduino
    int ret = A.connect_arduino();
    switch(ret){
    case(0): qDebug() << "arduino is available and connected to :" << A.getarduino_port_name();
        break;
    case(1): qDebug() << "arduino is available and not connected to :" << A.getarduino_port_name();
        break;
    case(-1): qDebug() << "arduino is not available" ;
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_msg()));
    data=A.read_from_arduino();
    qDebug() << "DATA :" <<data;


    //Timer
    QTimer *timer_p=new QTimer(this);
    connect(timer_p,SIGNAL(timeout()),this,SLOT(showTime_p()));
    timer_p->start();
    //DAate systeme
    QDateTime Date_p=QDateTime::currentDateTime();
    QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
    ui->Date->setText(Date_txt);

    ui->tab_afficher_produit->setModel(Etmp.afficher_produit()); 
    ui->tab_afficher_commande->setModel(Com.afficher_commande());
     // ui->tab_afficher_commande->setModel(Com.afficher_commande());
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
          A.write_to_arduino("2");
       }
    else
        A.write_to_arduino("1");
}

//OFF led
void userInterface::on_OFF_Led_clicked()
{
    A.write_to_arduino("0");
    A.write_to_arduino("3");
    ui->update_msg->setText("");
}

//update msg
void userInterface::update_msg()
{
 data=A.read_from_arduino();
 if(data=="2")
     ui->update_msg->setText("Commande ajouter");
 else if (data=="1")
     ui->update_msg->setText("Commande non ajouter");
}


//suuprimer commande(button supprimer)
void userInterface::on_supprimer_commande_clicked()
{
    int reference=ui->reference_commande_e3->text().toInt();
    bool test=Com.supprimer_commande(reference);
    if(test)
        ui->tab_afficher_commande_2->setModel(Com.afficher_commande());
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
        bool test =c.modif_commande(reference,description,etat_commande,nombre_commande);
        if(test)
          {
          ui->tab_afficher_commande->setModel(Com.afficher_commande());
          QMessageBox::information(nullptr,QObject::tr("commande modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
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
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Open PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("Commande.pdf"); }

                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                QTextDocument doc;
                QSqlQuery q;
                q.prepare("SELECT * from COMMANDE");
                q.exec();
        QString pdf="<br> <img src='C:/Users/Wassim/Desktop/v2/QTv2/Logo.png' height='42' width='144'/> <body style='background-color:LightYellow'> <h1  style='color:DarkKhaki'>  Liste des commandes :  <br></h1>\n <br>  <table>  <tr><th>REFERENCE</th>   <th> DESCRIPTION </th>     <th> ETAT</th>   <th> QUANTITE</th>  </tr>" ;


                while ( q.next()) {

               pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>     <td>    "  +q.value(2).toString() +"   </td>  <td>     "   +q.value(3).toString()+"</td>      </td>" ;

                }
                doc.setHtml(pdf);
                doc.setPageSize(printer.pageRect().size());
                doc.print(&printer);
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

void userInterface::showTime_p()
{
    QTime time=QTime::currentTime();
    QString time_txt=time.toString("hh:mm:ss");
    ui->Timer->setText(time_txt);
}

void userInterface::on_pushButton_write_clicked()
{
    QFile file_reclamation("C:/Users/Wassim/Desktop/v2/QTv2/Reclamation.txt");
    if(!file_reclamation.open(QFile::WriteOnly | QFile::Text))
    {QMessageBox::warning(this,"title","file not open");}
    QTextStream out(&file_reclamation);
    QString txt=ui->plainTextEdit_reclamation->toPlainText();
    out << txt;
    file_reclamation.flush();
    file_reclamation.close();

}

void userInterface::on_pushButton_read_clicked()
{
    QFile file_reclamation("C:/Users/Wassim/Desktop/v2/QTv2/Reclamation.txt");
    if(!file_reclamation.open(QFile::ReadOnly | QFile::Text))
    {QMessageBox::warning(this,"title","file not open");}
    QTextStream in(&file_reclamation);
    QString txt=in.readAll();
    ui->plainTextEdit_reclamation->setPlainText(txt);
    file_reclamation.close();
}


void userInterface::on_pushButton_envoyerMail_clicked()
{

    Smtp_produit* smtp = new Smtp_produit("projet.esprit11@gmail.com", "esprit2020", "smtp.gmail.com", 465);

        smtp->sendMail("projet.esprit11@gmail.com", ui->ecrire_mail->text() , ui->ecrire_objet->text() ,ui->ecrire_txt->toPlainText());
}



