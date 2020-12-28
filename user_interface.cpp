#include "user_interface.h"
#include "ui_user_interface.h"
#include"planning.h"
#include"film.h"
#include "smtp.h"
#include<QPixmap>
#include<QIntValidator>
#include<QMessageBox>
#include "abonnee.h"
#include "abonnement.h"
user_interface::user_interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user_interface)
{
    ui->setupUi(this);

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
     ui->email_emp->setValidator(new QRegularExpressionValidator(rx, this));


     //Arduino led
     int ret = A.connect_arduino();
     switch(ret){
     case(0): qDebug() << "arduino is available and connected to :" << A.getarduino_port_name();
         break;
     case(1): qDebug() << "arduino is available and not connected to :" << A.getarduino_port_name();
         break;
     case(-1): qDebug() << "arduino is not available" ;
     }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
     data=A.read_from_arduino();


    QIntValidator *int_val=new QIntValidator(1,9999999);
    ui->id_emp->setValidator(int_val);
    ui->salaire_emp->setValidator(int_val);
   // ui->id_emp_2->setValidator(int_val);

    ui->salaire_emp_2->setValidator(int_val);
   // ui->date_conge_e_8->setValidator(int_val);
    ui->id_conge_e_1->setValidator(int_val);
    ui->duree_conge_e_1->setValidator(int_val);
  //  ui->date_conge_e_4->setValidator(int_val);
    ui->heure_conge_e_4->setValidator(int_val);
    ui->ref_conge_e2->setValidator(int_val);
    ui->duree_conge_e_2->setValidator(int_val);

    ui->tab_affichage_planning->setModel(tmpplanning.afficher());
    ui->id_planning_e_1->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_affichage_film->setModel(tmpfilm.afficher());
    ui->id_film_e->setValidator(new QIntValidator(0,99999999,this));
    ui->id_film_e_2->setValidator(new QIntValidator(0,99999999,this));
    ui->id_film_e_3->setValidator(new QIntValidator(0,99999999,this));

    //commande/produit controle saisie
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

      ui->table_abonne->setModel(tmpabonnee.afficher());
      ui->id_abonne_e_1->setValidator (new QIntValidator(0,99999999, this));
      ui->id_modifier_abonne->setValidator(new QIntValidator(0,99999999,this));
       ui->id_supp_abonne->setValidator(new QIntValidator(0,99999999,this));

      ui->tab_abonnement->setModel(tmpabonnement.afficher());
      ui->num_abonnement_1->setValidator (new QIntValidator(0,99999999, this));
      ui->id_abonnement_2->setValidator(new QIntValidator(0,99999999,this));
      ui->id_abonnement_3->setValidator(new QIntValidator(0,99999999,this));




    //Timer
      QTimer *timer_p=new QTimer(this);
      connect(timer_p,SIGNAL(timeout()),this,SLOT(showTime()));
      timer_p->start();
      //DAate systeme
      QDateTime Date_p=QDateTime::currentDateTime();
      QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
      ui->Date->setText(Date_txt);
}

user_interface::~user_interface()
{
    delete ui;
}

void user_interface::on_open_clicked()
{
    A.write_to_arduino("1");
    data=A.read_from_arduino();
}

void user_interface::on_close_clicked()
{
    A.write_to_arduino("0");
    data=A.read_from_arduino();
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
   int id_planning= ui->id_planning_e_1->text().toInt();
    QString nom_planning= ui->nom_planning_e_1->text();
    QString date_planning = ui->date_planning_e_1->text();
    QString heure = ui->heure_e_1->text();
    planning p(id_planning,nom_planning,date_planning,heure);
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
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_planning"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_planning"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PLANNING"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE"));
    return model;
}

void user_interface::on_supprimer_planning_clicked()

    {
        //int id = ui->id_planning_e_3->text().toInt();
        bool test=tmpplanning.supprimer(ui->comboBox_supprimer_planning->currentText().toInt());

        if(test)
        {ui->tab_affichage_planning->setModel(tmpplanning.afficher());//refresh


            QMessageBox::information(nullptr, QObject::tr("Supprimer un planning"),
                        QObject::tr("planning supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->comboBox_supprimer_planning->clear();
            ui->comboBox_supprimer_planning->addItems(tmpplanning.listplanning());


        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un planning"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }

void user_interface::on_modifier_planning_clicked()

    {

    planning p(ui->id_planning_e_2->text().toInt(),ui->nom_planning_e_2->text(),ui->date_planning_e_2->text(),ui->heure_e_2->text());
    bool test=p.modifier(ui->comboBox_modifier_planning->currentText().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Planning"),
                    QObject::tr("planning modifié avec succés.\n"), QMessageBox::Cancel);
        ui->tab_affichage_planning->setModel(tmpplanning.afficher());
        ui->id_planning_e_2->setText("");
        ui->nom_planning_e_2->setText("");
        ui->date_planning_e_2->setText("");
        ui->heure_e_2->setText("");


        ui->comboBox_modifier_planning->clear();
        ui->comboBox_modifier_planning->addItems(tmpplanning.listplanning());

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("planning"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }






}


void user_interface::on_ajouter_film_clicked()
{
    int id_film= ui->id_film_e->text().toInt();
     QString nom_film= ui->nom_film_e->text();
     QString date_sortie = ui->date_sortie_e->text();
     QString duree = ui->duree_e->text();
     int note= ui->note_e->text().toInt();
      QString genre= ui->genre_e->text();
     film f(id_film,nom_film,date_sortie,duree,note,genre);
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
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_film"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_film"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_SORTIE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOTE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("GENRE"));
    return model;
}


void user_interface::on_supprimer_film_clicked()
{
    //int id = ui->id_planning_e_3->text().toInt();
    bool test=tmpfilm.supprimer(ui->comboBox_supprimer_film->currentText().toInt());

    if(test)
    {ui->tab_affichage_film->setModel(tmpfilm.afficher());//refresh


        QMessageBox::information(nullptr, QObject::tr("Supprimer un film"),
                    QObject::tr("planning supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->comboBox_supprimer_film->clear();
        ui->comboBox_supprimer_film->addItems(tmpfilm.listfilm());


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un film"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void user_interface::on_modifier_film_clicked()
{
    film f(ui->comboBox_modifier_film->currentText().toInt(),ui->nom_film_e_2->text(),ui->date_sortie_e_2->text(),ui->duree_e_2->text(),(ui->note_e_2->text().toInt()),ui->genre_e_2->text());
    bool test=f.modifier(ui->comboBox_modifier_film->currentText().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("film"),
                    QObject::tr("film modifié avec succés.\n"), QMessageBox::Cancel);
        ui->tab_affichage_film->setModel(tmpfilm.afficher());
        ui->id_film_e_2->setText("");
        ui->nom_film_e_2->setText("");
        ui->date_sortie_e_2->setText("");
        ui->duree_e_2->setText("");
        ui->note_e_2->setText("");
        ui->genre_e_2->setText("");
        ui->comboBox_modifier_film->clear();
        ui->comboBox_modifier_film->addItems(tmpfilm.listfilm());

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("film"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }


}

void user_interface::on_chercher_film_clicked()
{
    QString id_film = ui->id_film_e_4->text();
    QString nom_film = ui->nom_film_e_4->text();
    QString genre = ui->genre_film_e_4->text();
    ui->tab_affichage_film->setModel(tmpfilm.chercher_film_avancee(id_film,nom_film,genre));
}


void user_interface::on_Trier_planning_clicked()
{
    QString l=ui->comboBox_Planning->currentText();
    ui->tab_affichage_planning->setModel(tmpplanning.trier(l));
}



void user_interface::on_Exporter_planning_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("planning.pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM PLANNING ");
        q.exec();
        QString pdf="<br> <img src='C:/Users/admin/Desktop/Atelier_Connexion/Pathé_Logo.png' height='42' width='144'/> <h1  style='color:red'>       LISTE DU PLANNING  <br></h1>\n <br> <table>  <tr>  <th> ID </th> <th> NOM </th> <th> DATE </th> <th> HEURE  </th>   </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString() +"</td>  <td>" +q.value(2).toString() +"  "" " "</td>      <td>     "+q.value(3).toString()+"--------"+"</td>       <td>"+q.value(4).toString()+"       </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void user_interface::on_chercher_planning_clicked()
{
    QString m =ui->date_planning_e_4->text();
        QString k = ui->heure_planning_e_4->text();
        QString l = ui->nom_planning_e_4->text();
       ui->tableView_planning->setModel(tmpplanning.chercher_planning_avancee(l,k,m)) ;

}

void user_interface::on_Trier_film_clicked()
{
    QString l=ui->comboBox_film->currentText();
    ui->tab_affichage_film->setModel(tmpfilm.trier(l));
}

void user_interface::on_comboBox_supprimer_planning_currentTextChanged(const QString &arg1)
{

   planning p =tmpplanning.recherche_Id_planning(ui->comboBox_supprimer_planning->currentText().toInt());
    QString id= QString::number(p.get_id_planning());
    ui->nom_planning_e_2->setText(p.get_nom_planning());
    ui->date_planning_e_2->setText(p.get_date_planning());
    ui->heure_e_2->setText(p.get_heure());
}
void user_interface::on_comboBox_modifier_planning_currentTextChanged(const QString &arg1)
{
    planning p =tmpplanning.recherche_Id_planning(ui->comboBox_modifier_planning->currentText().toInt());
     QString id= QString::number(p.get_id_planning());
     ui->nom_planning_e_2->setText(p.get_nom_planning());
     ui->date_planning_e_2->setText(p.get_date_planning());
     ui->heure_e_2->setText(p.get_heure());
}


void user_interface::on_tab_Widget_planning_currentChanged(int index)
{
    ui->tab_affichage_planning->setModel(tmpplanning.afficher());
    ui->comboBox_supprimer_planning->clear();
    ui->comboBox_supprimer_planning->addItems(tmpplanning.listplanning());
    ui->comboBox_modifier_planning->clear();
    ui->comboBox_modifier_planning->addItems(tmpplanning.listplanning());

}


void user_interface::on_Exporter_film_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("liste des films.pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM FILM ");
        q.exec();
        QString pdf="<br> <img src='C:/Users/admin/Desktop/Atelier_Connexion/Pathé_Logo.png' height='42' width='144'/> <h1  style='color:red'>       LISTE DES FILMS  <br></h1>\n <br> <table>  <tr>  <th> ID </th> <th> NOM </th> <th> DATE </th> <th> DUREE</th>  <th> NOTE </th> <th> GENRE  </th>   </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString() +"</td>  <td>" +q.value(2).toString() +"  "" " "</td>      <td>     "+q.value(3).toString()+"--"+"</td>       <td>"+q.value(4).toString()+"         <td>"+q.value(5).toString()+"     </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void user_interface::on_comboBox_supprimer_film_currentTextChanged(const QString &arg1)
{
    film f =tmpfilm.recherche_Id_film(ui->comboBox_supprimer_film->currentText().toInt());
     QString id= QString::number(f.get_id_film());
      QString note= QString::number(f.get_note());

     ui->nom_film_e_2->setText(f.get_nom_film());
     ui->date_sortie_e_2->setText(f.get_date_sortie());
     ui->duree_e_2->setText(f.get_duree());
     ui->note_e_2->setText(note);
     ui->genre_e_2->setText(f.get_genre());
}

void user_interface::on_tab_widget_film_currentChanged(int index)
{
    ui->tab_affichage_film->setModel(tmpfilm.afficher());
    ui->comboBox_supprimer_film->clear();
    ui->comboBox_supprimer_film->addItems(tmpfilm.listfilm());
    ui->comboBox_supprimer_film->clear();
    ui->comboBox_supprimer_film->addItems(tmpfilm.listfilm());
    ui->comboBox_modifier_film->clear();
    ui->comboBox_modifier_film->addItems(tmpfilm.listfilm());

}

void user_interface::on_comboBox_modifier_film_currentTextChanged(const QString &arg1)
{
    film f =tmpfilm.recherche_Id_film(ui->comboBox_modifier_film->currentText().toInt());
     QString id= QString::number(f.get_id_film());
      QString note= QString::number(f.get_note());

     ui->nom_film_e_2->setText(f.get_nom_film());
     ui->date_sortie_e_2->setText(f.get_date_sortie());
     ui->duree_e_2->setText(f.get_duree());
     ui->note_e_2->setText(note);
     ui->genre_e_2->setText(f.get_genre());
}

void user_interface::on_Mail_clicked()
{
    Smtp* smtp = new Smtp("fatma.louhichi@esprit.tn", "191JFT1375", "smtp.gmail.com", 465);

        smtp->sendMail("fatma.louhichi@esprit.tn", ui->envoyera->text() , ui->objet->text() ,ui->msg->toPlainText());
}



/*void MainWindow::on_modifier_employe_2_clicked()
{
    employe e(ui->id_emp_2->text().toInt(),ui->nom_emp_2->text(),ui->prenom_emp_2->text(),ui->date_naissance_emp_2->date(),ui->salaire_emp_2->text().toDouble(),ui->email_emp_2->text());
    bool test=e.modifier(ui->id_employe_mod->text().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Employe"),
                    QObject::tr("employé modifié avec succés.\n"), QMessageBox::Cancel);
        ui->tab_employe->setModel(tmpemploye.afficher());
        ui->id_emp_2->setText("");
        ui->nom_emp_2->setText("");
        ui->prenom_emp_2->setText("");
        ui->date_naissance_emp_2->setDate(QDate(2000,01,01));
        ui->salaire_emp_2->setText("");
        ui->id_employe_mod->setText("");
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}*/



/*void MainWindow::on_trouver_conge_clicked()
{
    Conge c =tmpconge.recherche_ref(ui->ref_conge_mod->text().toInt());
    QString ref= QString::number(c.getref());
    QString duree= QString::number(c.getduree());
    ui->ref_conge_e2->setText(ref);
    ui->duree_conge_e_2->setText(duree);
    ui->date_conge_e_2->setDate(c.getdate());
    ui->type_conge_e_2->setText(c.gettype());
}/*





/*void MainWindow::on_date_conge_e_7_textChanged(const QString &arg1)
{
    //ui->tab_employe_2->setModel(tmpemploye.rechercher(ui->date_conge_e_7->text())); ///lcase mta3 rechercher( ui->date_conge_e_7->text()))
        bool nom=ui->checkBoxRechNom->isChecked();
        bool prenom=ui->checkBoxRechPrenom->isChecked();
        bool id=ui->checkBoxRechId->isChecked();
        const QString rech=ui->date_conge_e_7->text();

        if((nom && prenom && id) || (!nom && !prenom && !id)){
            ui->tab_employe_2->setModel(tmpemploye.recherche_emp(rech));
            qDebug() <<"3!!";
        }

        else{
            if(nom){
                if(prenom){
                    ui->tab_employe_2->setModel(tmpemploye.chercher_emp_nom_prenom(rech));
                    qDebug()<<"nom w prenom";
                }
                else if(id){
                    ui->tab_employe_2->setModel(tmpemploye.chercher_emp_nom_id(rech));
                    qDebug()<<"nom w id";
                }
                else{
                    ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(rech));
                }
            }
            else if(prenom){
                if(id){
                    ui->tab_employe_2->setModel(tmpemploye.chercher_emp_id_prenom(rech));
                    qDebug()<<"prenom w id";
                }
                else{
                    ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_prenom(rech));
                }
            }
            else{
                ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(rech));
            }
        }

    }*/




/*void MainWindow::on_rech_emp2_clicked()
{
  // ui->tab_employe_2->setModel(tmpemploye.rechercher(ui->date_conge_e_7->text(),ui->date_conge_e_9->text(),ui->date_conge_e_8->text().toInt())); ///lcase mta3 rechercher( ui->date_conge_e_7->text()))
   //ui->tab_employe_2->setModel(tmpemploye.rechercher(ui->date_conge_e_9->text()));
   QString m =ui->date_conge_e_7->text();
       QString l = ui->date_conge_e_8->text(); //id
         QString k = ui->date_conge_e_9->text();
        if (k != ""){
           ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_prenom(k)) ;}
            if (l != ""){
           ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(l)) ;}
            if (m!= ""){
           ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(m)) ;
         if((m!="")&&(k!="")&&(l!="")){
                 ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(m)) ;
                 ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_prenom(k)) ;
                 ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(l)) ;
           }
           else if (m != ""){
              if (l != ""){
      ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(m)) ;
      ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(l)) ;
              }
              else if(k!=""){
      ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(m)) ;
      ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_prenom(k)) ;
              }
              else{
                  ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(m)) ;
              }

              }
              else if (l != ""){
               if(k!=""){
                   ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(l)) ;
                   ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(k)) ;
               }
               else{
                   ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(l)) ;
               }

              }
              else if (m!= ""){
               ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(l)) ;
               ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(m)) ;

              }
              else{
                  ui->tab_employe->setModel(tmpemploye.afficher());
              }


} */



void user_interface::sendMail()
{
    Smtp* smtp = new Smtp("lina.khammeri@esprit.tn","191JFT1097", "smtp.gmail.com", 465,30000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//ui->rcpt->text()

    smtp->sendMail("lina.khammeri@esprit.tn", ui->combomail->currentText() , ui->subject->text(),ui->msg->toPlainText());
}

void user_interface::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


/*void MainWindow::on_Touslesconges_3_clicked()
{
    ui->tab_affichage_conge->setModel(tmpconge.trier2());

}*/




/*void MainWindow::on_rech_emp2_clicked()
{
    QString nom_e =ui->date_conge_e_7->text();
        int id_e = ui->date_conge_e_8->text().toInt(); //id
          QString prenom_e = ui->date_conge_e_9->text();
          if ( nom_e!= ""){
         ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(nom_e)) ;}
         if (id_e != 0){
            ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(id_e)) ;}

             if (prenom_e!= ""){
            ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_prenom(prenom_e)) ;


}}*/







/*void MainWindow::on_rech_emp2_2_clicked()
{
    QString ref_c =ui->date_conge_e_4->text();
    QString duree_c = ui->heure_conge_e_4->text();
    QString type_c = ui->heure_conge_e_5->text();

    ui->tab_affichage_conge_2->setModel(tmpconge.chercher_cng_avancee(ref_c,duree_c,type_c));
}*/







void user_interface::on_g_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void user_interface::on_email_emp_textChanged(const QString &arg1)
{
    if(!ui->email_emp->hasAcceptableInput())
    {   // ui->email_emp->setStyleSheet("QLineEdit { color: red;}");
        ui->email_emp->setStyleSheet("background: red");
 ui->label_38->setText("format invalide "); }
        else
           // ui->email_emp->setStyleSheet("QLineEdit { color: black;}");
         {ui->email_emp->setStyleSheet("background:#FFD700 ");
    ui->label_38->setText(""); }
}

void user_interface::on_rech_emp2_clicked()
{
    QString nom_e =ui->date_conge_e_7->text();
    QString prenom_e = ui->date_conge_e_8->text();
    QString email_e = ui->date_conge_e_9->text();

    ui->tab_employe_2->setModel(tmpemploye.chercher_emp_avancee(nom_e,prenom_e,email_e));

// ui->tab_affichage_conge->setModel(tmpconge.trier2());
}

void user_interface::on_rech_emp2_2_clicked()
{
    int refc =ui->date_conge_e_4->text().toUInt();
    int dureec = ui->heure_conge_e_4->text().toInt(); //id
          QString typec = ui->heure_conge_e_5->text();
          if ( refc != 0){
         ui->tab_affichage_conge_2->setModel(tmpconge.chercher_conge_par_ref(refc)) ;}
         if (dureec != 0){
            ui->tab_affichage_conge_2->setModel(tmpconge.chercher_conge_par_duree(dureec)) ;}

             if (typec!= ""){
            ui->tab_affichage_conge_2->setModel(tmpconge.chercher_conge_par_type(typec)) ;
}
}

void user_interface::on_date_conge_e_9_textChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_mail(ui->date_conge_e_9->text());
    if(e.getNom()!=""){
        ui->label_37->setText("l'employe existe");
    }
    else{
        ui->label_37->setText("");
    }
}

void user_interface::on_date_conge_e_4_textChanged(const QString &arg1)
{
    conge c=tmpconge.recherche_ref(ui->date_conge_e_4->text().toInt());
    if(c.gettype()!=""){
        ui->label_35->setText("conge existe");
    }
    else{
        ui->label_35->setText("");
    }
}

void user_interface::on_Tricongetype_clicked()
{
     ui->tab_affichage_conge->setModel(tmpconge.trier2());
}

void user_interface::on_Touslesconges_2_clicked()
{
    ui->tab_affichage_conge->setModel(tmpconge.trier1());

}

void user_interface::on_Touslesconges_clicked()
{
    ui->tab_affichage_conge->setModel(tmpconge.trier());

}

void user_interface::on_id_conge_e_1_textChanged(const QString &arg1)
{
    conge c=tmpconge.recherche_ref(ui->id_conge_e_1->text().toInt());
    if(c.gettype()!=""){
        ui->label_35->setText("conge existe");
    }
    else{
        ui->label_35->setText("");
    }
}

void user_interface::on_mdf_clicked()
{
    employe e(ui->id_emp_2->text().toInt(),ui->nom_emp_2->text(),ui->prenom_emp_2->text(),ui->date_naissance_emp_2->date(),ui->salaire_emp_2->text().toDouble(),ui->email_emp_2->text());
    bool test=e.modifier(ui->comboBox->currentText().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Employe"),
                    QObject::tr("employé modifié avec succés.\n"), QMessageBox::Cancel);
        ui->tab_employe->setModel(tmpemploye.afficher());
        ui->id_emp_2->setText("");
        ui->nom_emp_2->setText("");
        ui->prenom_emp_2->setText("");
        ui->date_naissance_emp_2->setDate(QDate(2000,01,01));
        ui->salaire_emp_2->setText("");
      //  ui->id_employe_mod->setText("");
        ui->comboBox->clear();
        ui->comboBox->addItems(tmpemploye.listemploye());

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}

void user_interface::on_combomail_currentTextChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_mail(ui->combomail->currentText());
    QString id= QString::number(e.getId());
    QString salaire= QString::number(e.getSalaire());
    ui->id_emp_2->setText(id);
    ui->nom_emp_2->setText(e.getNom());
    ui->prenom_emp_2->setText(e.getprenom());
    ui->date_naissance_emp_2->setDate(e.getDate_naissance());
    ui->salaire_emp_2->setText(salaire);
}

void user_interface::on_modifier_conge_clicked()
{
    conge c(ui->comboc1->currentText().toInt(),ui->duree_conge_e_2->text().toInt(),ui->date_conge_e_2->date(),ui->type_conge_e_2->text(),ui->comboc1->currentText().toInt());
    bool test=c.modifier(ui->comboc1->currentText().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Conge"),
                    QObject::tr("congé modifié avec succés.\n"), QMessageBox::Cancel);
        ui->tab_affichage_conge->setModel(tmpconge.afficher());

        ui->duree_conge_e_2->setText("");
        ui->date_conge_e_2->setDate(QDate(2000,01,01));
        ui->type_conge_e_2->setText("");
        //ui->ref_conge_mod->setText("");
        ui->comboc1->clear();
        ui->comboc1->addItems(tmpconge.listconge());
        ui->comboBox_id_emp_2->clear();
        ui->comboBox_id_emp_2->currentText().toInt();

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Conge"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}

void user_interface::on_comboc1_currentTextChanged(const QString &arg1)
{
    conge c =tmpconge.recherche_ref(ui->comboc1->currentText().toInt());
    QString ref= QString::number(c.getref());
    QString duree= QString::number(c.getduree());
   ui->ref_conge_e2->setText(ref);
    ui->duree_conge_e_2->setText(duree);
    ui->date_conge_e_2->setDate(c.getdate());
    ui->type_conge_e_2->setText(c.gettype());
}


void user_interface::on_rcpt_textChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_mail(ui->rcpt->text());
    if(e.getNom()!=""){
        ui->label_30->setText("l'email existe");
    }
    else{
        ui->label_30->setText("");
    }
}

void user_interface::on_date_conge_e_8_textChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_Id(ui->date_conge_e_8->text().toInt());
    if(e.getprenom()!=""){
        ui->tst->setText("employe existe");
    }
    else{
        ui->tst->setText("");
    }
}

void user_interface::on_id_emp_textChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_Id(ui->id_emp->text().toInt());
    if(e.getprenom()!=""){
        ui->test_id_emp->setText("employe existe");
    }
    else{
        ui->test_id_emp->setText("");
    }
}

void user_interface::on_stats_clicked()
{
    stat_employe *s=new stat_employe();
    s->show();
}

void user_interface::on_stats_2_clicked()
{

    stat_conge *s=new stat_conge();
    s->show();
}

void user_interface::on_combo2_currentTextChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_Id(ui->combo2->currentText().toInt());
    QString id= QString::number(e.getId());
    QString salaire= QString::number(e.getSalaire());
    ui->id_emp_2->setText(id);
    ui->nom_emp_2->setText(e.getNom());
    ui->prenom_emp_2->setText(e.getprenom());
    ui->date_naissance_emp_2->setDate(e.getDate_naissance());
    ui->salaire_emp_2->setText(salaire);
}

void user_interface::on_tri_emp_2_clicked()
{
     ui->tab_employe->setModel(tmpemploye.trier1());
}

void user_interface::on_tri_emp_clicked()
{
     ui->tab_employe->setModel(tmpemploye.trier());
}

void user_interface::on_supprimer_employe_clicked()
{
    bool test=tmpemploye.supprimer(ui->combo2->currentText().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Employe"),
                    QObject::tr("employé supprimé avec succés.\n"), QMessageBox::Cancel);
        ui->tab_employe->setModel(tmpemploye.afficher());
        ui->combo2->clear();
                ui->combo2->addItems(tmpemploye.listemploye());
        //ui->comboBox->clear();
        //ui->comboBox->addItems(tmpemploye.listemploye());

        //ui->comboBox_id_emp->clear();
        //ui->comboBox_id_emp->addItems(tmpemploye.listemploye());

        //ui->comboBox_id_emp_2->clear();
        //ui->comboBox_id_emp_2->addItems(tmpemploye.listemploye());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}

void user_interface::on_supprimer_conge_clicked()
{
    bool test=tmpconge.supprimer(ui->comboBox_4->currentText().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Conge"),
                    QObject::tr("congé supprimé avec succés.\n"), QMessageBox::Cancel);
        ui->tab_affichage_conge->setModel(tmpconge.afficher());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Conge"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
        //ui->comboc1->clear();
        //ui->comboc1->addItems(tmpconge.listconge());
        ui->comboBox_4->clear();
        ui->comboBox_4->addItems(tmpconge.listconge());
    }
}

void user_interface::on_ajouter_conge_clicked()
{
    conge c(ui->id_conge_e_1->text().toInt(),ui->duree_conge_e_1->text().toInt(),ui->date_conge_e_1->date(),ui->type_e_1->text(),ui->comboBox_id_emp->currentText().toInt());
    bool test=c.ajouter1();
    if(test) {
        QMessageBox::information(nullptr, QObject::tr("Conge"),
                    QObject::tr("congé ajouté avec succés.\n"), QMessageBox::Cancel);
        ui->tab_affichage_conge->setModel(tmpconge.afficher());
        ui->id_conge_e_1->setText("");
        ui->duree_conge_e_1->setText("");
        ui->date_conge_e_1->setDate(QDate(2000,01,01));
        ui->type_e_1->setText("");
        ui->comboBox_id_emp->clear();
       ui->comboBox_id_emp->addItems(tmpemploye.listemploye());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Conge"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}

void user_interface::on_tab_widget_conge_currentChanged(int index)
{
    ui->tab_affichage_conge->setModel(tmpconge.afficher());
    ui->comboc1->clear();
    ui->comboc1->addItems(tmpconge.listconge());
    ui->comboBox_4->clear();
    ui->comboBox_4->addItems(tmpconge.listconge());
    ui->comboBox_id_emp->clear();
    ui->comboBox_id_emp->addItems(tmpemploye.listemploye());
    ui->comboBox_id_emp_2->clear();
    ui->comboBox_id_emp_2->addItems(tmpemploye.listemploye());
}

void user_interface::on_comboBox_currentTextChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_Id(ui->comboBox->currentText().toInt());
    QString id= QString::number(e.getId());
    QString salaire= QString::number(e.getSalaire());
    ui->id_emp_2->setText(id);
    ui->nom_emp_2->setText(e.getNom());
    ui->prenom_emp_2->setText(e.getprenom());
    ui->date_naissance_emp_2->setDate(e.getDate_naissance());
    ui->salaire_emp_2->setText(salaire);
    ui->email_emp_2->setText(e.getEmail());
}

void user_interface::on_tri_emp_3_clicked()
{
    ui->tab_employe->setModel(tmpemploye.trier2());

}

void user_interface::on_ajouter_employe_2_clicked()
{
    employe e(ui->id_emp->text().toInt(),ui->nom_emp->text(),ui->prenom_emp->text(),ui->date_naissance_emp->date(),ui->salaire_emp->text().toDouble(),ui->email_emp->text());
    bool test=e.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Employe"),
                    QObject::tr("employé ajouté avec succés.\n"), QMessageBox::Cancel);
        ui->tab_employe->setModel(tmpemploye.afficher());
        ui->id_emp->setText("");
        ui->nom_emp->setText("");
        ui->prenom_emp->setText("");

        ui->date_naissance_emp->setDate(QDate(2000,01,01));
        ui->salaire_emp->setText("");

        ui->comboBox->clear();
        ui->comboBox->addItems(tmpemploye.listemploye());

        ui->comboBox_id_emp->clear();
        ui->comboBox_id_emp->addItems(tmpemploye.listemploye());

       //ui->comboBox_id_emp_2->clear();
        //ui->comboBox_id_emp_2->addItems(tmpemploye.listemploye());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}

void user_interface::on_tab_widget_employe_currentChanged(int index)
{
    ui->tab_employe->setModel(tmpemploye.afficher());

    ui->comboBox->clear();
    ui->comboBox->addItems(tmpemploye.listemploye());

    ui->comboBox_id_emp->clear();
    ui->comboBox_id_emp->addItems(tmpemploye.listemploye());

    ui->comboBox_id_emp_2->clear();
    ui->comboBox_id_emp_2->addItems(tmpemploye.listemploye());
    ui->combo2->clear();
    ui->combo2->addItems(tmpemploye.listemploye());

    ui->combomail->clear();
    ui->combomail->addItems(tmpemploye.listemploye1());

    ui->combomail->clear();
    ui->comboBox_id_emp->addItems(tmpemploye.listemploye1());

    ui->combomail->clear();
    ui->combomail->addItems(tmpemploye.listemploye1());
}

void user_interface::on_g_cong_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

//nav prod widget
void user_interface::on_g_prd_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
//nav comm widget
void user_interface::on_g_cmd_clicked()
{
   ui->stackedWidget->setCurrentIndex(7);
}

//ajouter un produit(button ajouter)
void user_interface::on_ajouter_produit_clicked()
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

//Modifier un produit(button modifier)
void user_interface::on_modifier_produit_clicked()
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

//Supprimer un produit(button supprimer)
void user_interface::on_supprimer_produit_clicked()
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

//chercher un produit(button chercher)
void user_interface::on_chercher_produit_clicked()
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

void user_interface::on_radioButto_afficher_commande_3_clicked()
{
    ui->tableView_supp_produit->setModel(Etmp.afficher_produit());
}

void user_interface::on_radioButton_produit_clicked()
{

    ui->tab_afficher_produit->setModel(Etmp.afficher_produit());
}

void user_interface::on_radioButto_afficher_commande_2_clicked()
{
    ui->recherche_tabView_2->setModel(Etmp.afficher_produit());

}
//tri produit par id
void user_interface::on_afficher_id_produit_clicked()
{
    ui->tab_afficher_produit->setModel(Etmp.tri_produit_id());
}
//tri produit par nom
void user_interface::on_afficher_nom_produit_clicked()
{
  ui->tab_afficher_produit->setModel(Etmp.tri_produit_nom());
}
//tri produit par nombre
void user_interface::on_afficher_nombre_produit_clicked()
{
    ui->tab_afficher_produit->setModel(Etmp.tri_produit_nombre());
}

void user_interface::on_statistique_prod_clicked()
{
    statistique *s=new statistique();
        s->show();
}

//Load id produit in the combobox
void user_interface::on_load_produit_id_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
       model->setQuery("SELECT ID FROM PRODUIT");
       ui->comboBox_Produit->setModel(model);
}

void user_interface::showTime()
{
    QTime time=QTime::currentTime();
    QString time_txt=time.toString("hh:mm:ss");
    ui->Timer->setText(time_txt);
}
//Ajouter commande
void user_interface::on_ajouter_commande_clicked()
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
//modfier commande
void user_interface::on_modifier_commande_clicked()
{int reference= ui->reference_commande_e2->text().toInt();
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
//suuprimer commande
void user_interface::on_supprimer_commande_clicked()
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
//recherche commande
void user_interface::on_rechercher_commande_clicked()
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

void user_interface::on_radioButto_afficher_commande_clicked()
{
    ui->recherche_tabViewx->setModel(Com.afficher_commande());
}


void user_interface::on_radioButton_commande_2_clicked()
{
   ui->tab_afficher_commande_2->setModel(Com.afficher_commande());
}

void user_interface::on_radioButton_commande_clicked()
{
   ui->tab_afficher_commande->setModel(Com.afficher_commande());
}
//tri commande par reference
void user_interface::on_reference_commande_2_clicked()
{
   ui->tab_afficher_commande->setModel(Com.tri_commande_reference());
}
//tri commande par quantité
void user_interface::on_modifier_commande_3_clicked()
{
    ui->tab_afficher_commande->setModel(Com.tri_commande_quantite());
}
//tri commande par etat
void user_interface::on_modifier_commande_4_clicked()
{
    ui->tab_afficher_commande->setModel(Com.tri_commande_etat());
}
//load commande reference combobox
void user_interface::on_load_commande_ref_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
       model->setQuery("SELECT REFERENCE FROM COMMANDE");
       ui->comboBox_Commande->setModel(model);
}
//commande pdf
void user_interface::on_pdf_commande_clicked()
{
    //The QPrinter class is a paint device that paints on a printer
        QPrinter *printer = new QPrinter(QPrinter::HighResolution);
           printer->setOutputFormat(QPrinter::NativeFormat);
           printer->setPageSize(QPrinter::A4);
           printer->setOrientation(QPrinter::Portrait);
           printer->setFullPage(true);

    //The QPrintDialog class provides a dialog for specifying the printer's configuration
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
//reclamation write
void user_interface::on_pushButton_write_clicked()
{
    QFile file_reclamation("C:/Users/Wassim/Desktop/Integration/Smart_Cinema_2A7/Reclamation.txt");
      if(!file_reclamation.open(QFile::WriteOnly | QFile::Text))
      {QMessageBox::warning(this,"title","file not open");}
      QTextStream out(&file_reclamation);
      QString txt=ui->plainTextEdit_reclamation->toPlainText();
      out << txt;
      file_reclamation.flush();
      file_reclamation.close();

}
//reclamation read
void user_interface::on_pushButton_read_clicked()
{
    QFile file_reclamation("C:/Users/Wassim/Desktop/Integration/Smart_Cinema_2A7/Reclamation.txt");
       if(!file_reclamation.open(QFile::ReadOnly | QFile::Text))
       {QMessageBox::warning(this,"title","file not open");}
       QTextStream in(&file_reclamation);
       QString txt=in.readAll();
       ui->plainTextEdit_reclamation->setPlainText(txt);
       file_reclamation.close();
}


void user_interface::on_g_abonnes_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void user_interface::on_g_abonnements_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void user_interface::on_ajouter_abonne_clicked()
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

void user_interface::on_modifier_abonne_clicked()
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


void user_interface::on_modifier_affiche_abonne_clicked()
{
    ui->table_abonne_3->setModel(tmpabonnee.afficher());
}

void user_interface::on_supprimer_abonnee_clicked()
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
                               QObject::tr("Echec !\nAbonné non trouvé.\n"),QMessageBox::Ok);
}
}


void user_interface::on_affiche_supp_abonne_clicked()
{
     ui->table_rech_abonne_3->setModel(tmpabonnee.afficher());
}

void user_interface::on_radioButton_nom1_clicked()
{
    bool test = tmpabonnee.tri();
    if(test){
       ui->table_abonne->setModel(tmpabonnee.tri());
       QMessageBox::information(nullptr, QObject::tr("Tri des noms"),
                   QObject::tr("Abonnes triés.\n"),QMessageBox::Ok);
   }
   else   {
       QMessageBox::critical(nullptr, QObject::tr("Tri des noms"),
                                  QObject::tr("Abonnes non triés.\n"),QMessageBox::Ok);
   }
}


void user_interface::on_radioButton_ville_clicked()
{

    bool test = tmpabonnee.triville();
    if(test){
       ui->table_abonne->setModel(tmpabonnee.triville());
       QMessageBox::information(nullptr, QObject::tr("Tri des villes"),
                   QObject::tr("Abonnes triés.\n"),QMessageBox::Ok);
   }
   else   {
       QMessageBox::critical(nullptr, QObject::tr("Tri des villes"),
                                  QObject::tr("Abonnes non triés.\n"),QMessageBox::Ok);
   }
}

void user_interface::on_radioButton_tarif_clicked()
{
    bool test = tmpabonnee.tritarif();
        if(test){
           ui->table_abonne->setModel(tmpabonnee.tritarif());
           QMessageBox::information(nullptr, QObject::tr("Tri des tarifs"),
                       QObject::tr("Abonnes triés.\n"),QMessageBox::Ok);
       }
       else   {
           QMessageBox::critical(nullptr, QObject::tr("Tri des tarifs"),
                                      QObject::tr("Abonnes non triés.\n"),QMessageBox::Ok);
       }
}

void user_interface::on_afficher_abonne_clicked()
{
     ui->table_abonne->setModel(tmpabonnee.afficher());
}

void user_interface::on_notee_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Open PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("Exporter tableau abonnés.pdf"); }

            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);

            QTextDocument doc;
            QSqlQuery q;
            q.prepare("SELECT * from ABONNEE");
            q.exec();
           // QString pdf="<br> <img src='C:/Users/mariem/Desktop/Atelier_Connexion/img01.png' height='100' width='144' /> <h1  style='color:blue'>   LES ABONNES de notre cinéma:  <br></h1>\n <br>  <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PRENOM </th> <th> TARIF </th>  <th> VILLE </th>  </tr>" ;
 QString pdf="<center></br> <img style='border: 3px solid #555 ;'src='C:/Users/mariem/Desktop/Atelier_Connexion/img01.png' height='327' width='282 />  <h1  style='color:blue'> <u>Les ABONNES de notre cinéma:  </u></h1></center><br></h1>\n <br>  <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PRENOM </th> <th> TARIF </th>  <th> VILLE </th>  </tr>";


            while ( q.next()) {

                //pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>  <td>  "+q.value(2).toString() +"   </td>  <td>    "+q.value(3).toString()+"</td>       <td>"+q.value(4).toString()+"    <td>  <td>"+q.value(5).toString()+"            </td>" ;
pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>  <td>  "+q.value(2).toString() +"   </td>  <td>    "+q.value(3).toString()+"</td>       <td>"+q.value(4).toString()+"    <td>  <td>"+q.value(5).toString()+"            </td>" ;

            }
            doc.setHtml(pdf);
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}


void user_interface::on_chercher_abonnee_clicked()
{
    int id = ui->id_rech_abonne_5->text().toInt();
    QString nom = ui->nom_rech_abonne_5->text();
    QString prenom = ui->prenom_rech_abonne_5->text();

    if(id != 0)
   { ui->table_rech_abonne->setModel(tmpabonnee.searchid(id));}

      if(nom != "")
        {ui->table_rech_abonne->setModel(tmpabonnee.searchnom(nom));}

     if (prenom != "")
        {ui->table_rech_abonne->setModel(tmpabonnee.searchprenom(prenom));}
}

void user_interface::on_radioButton_afficher_clicked()
{
    ui->table_rech_abonne->setModel(tmpabonnee.afficher());
}

void user_interface::on_stat_abonnee_clicked()
{
     ui->tableViewstat->setModel(tmpabonnee.stat());
}

void user_interface::on_statistique_clicked()
{
    statistiquee *s=new statistiquee();
        s->show();
}


void user_interface::on_ajouter_abonnement_1_clicked()
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


void user_interface::on_radioButton_5_clicked()
{
    ui->tableView9->setModel(tmpabonnement.ajout());
}

void user_interface::on_modifier_abonnement_2_clicked()
{
    int num= ui->id_abonnement_2->text().toInt();
   int prix= ui->prix_abonnement_3->text().toInt();
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

void user_interface::on_afficher_abonnement_modif_clicked()
{
    ui->tableViewmodif->setModel(tmpabonnement.afficher());
}

void user_interface::on_supprimer_abonnement_3_clicked()
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

void user_interface::on_afficher_abonnement_3_clicked()
{
    ui->tableViewsupp->setModel(tmpabonnement.afficher());
}


void user_interface::on_afficher_abonnement_4_clicked()
{
    ui->tab_abonnement->setModel(tmpabonnement.afficher());
}


void user_interface::on_radioButton_4_clicked()
{
     ui->tab_abonnement->setModel(tmpabonnement.triduree());
}


void user_interface::on_typeButton_clicked()
{
     ui->tab_abonnement->setModel(tmpabonnement.tritype());
}


void user_interface::on_prixButton_clicked()
{
     ui->tab_abonnement->setModel(tmpabonnement.triprix());
}

void user_interface::on_chercher_abonnement_4_clicked()
{
    int num = ui->num_5->text().toInt();
    QString type = ui->type_5->text();
    QString duree = ui->duree_8->text();

    if(num != 0)
   { ui->tab_chercher_abonnement->setModel(tmpabonnement.searchnum(num));}

      if(type != "")
      {ui->tab_chercher_abonnement->setModel(tmpabonnement.searchtype(type));}

     if (duree != "")
        {ui->tab_chercher_abonnement->setModel(tmpabonnement.searchduree(duree));}
}

void user_interface::on_afficher_abonnement_clicked()
{
     ui->tab_chercher_abonnement->setModel(tmpabonnement.afficher());
}

void user_interface::on_statis_abonnement_clicked()
{
     ui->tableViewstatis->setModel(tmpabonnement.statis());
}


void user_interface::on_statis_chart_clicked()
{
    Stat2 *s=new Stat2();
        s->show();
}

void user_interface::on_write1_clicked()
{
    //read and write in myfile
       QFile file("C:/Users/mariem/Desktop/upload integration/Smart_Cinema_2A7/myfile.txt");
       if(!file.open(QFile::WriteOnly| QFile::Text)){
           QMessageBox::warning(this,"title","file not open");

       }
       //write in the file with out
       QTextStream out(&file);
       QString text = ui->plainTextEdit1->toPlainText();

       out <<text ;
       //fluch operation
       file.flush();
       //close file
       file.close();
    }


void user_interface::on_read1_clicked()
{
    QFile file("C:/Users/mariem/Desktop/upload integration/Smart_Cinema_2A7/myfile.txt");
   if(!file.open(QFile::ReadOnly| QFile::Text)){
       QMessageBox::warning(this,"title","file not open");
   }
   //stream pour lire le contenu of the file
   QTextStream in(&file);
   QString text = in.readAll();
   ui->plainTextEdit1->setPlainText(text);

   //close file
   file.close();
}
