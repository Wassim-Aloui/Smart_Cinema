#include "user_interface.h"
#include "ui_user_interface.h"
#include"planning.h"
#include"film.h"
#include "smtp.h"
#include<QPixmap>
#include<QIntValidator>
#include<QMessageBox>
user_interface::user_interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user_interface)
{
    ui->setupUi(this);

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
     ui->email_emp->setValidator(new QRegularExpressionValidator(rx, this));


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

