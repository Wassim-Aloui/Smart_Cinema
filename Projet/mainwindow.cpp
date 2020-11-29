#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));

    QIntValidator *int_val=new QIntValidator(1,9999999);
    ui->id_emp->setValidator(int_val);
    ui->salaire_emp->setValidator(int_val);
   // ui->id_emp_2->setValidator(int_val);

    ui->salaire_emp_2->setValidator(int_val);
    ui->date_conge_e_8->setValidator(int_val);
    ui->id_conge_e_1->setValidator(int_val);
    ui->duree_conge_e_1->setValidator(int_val);
    ui->date_conge_e_4->setValidator(int_val);
    ui->heure_conge_e_4->setValidator(int_val);
    ui->ref_conge_e2->setValidator(int_val);
    ui->duree_conge_e_2->setValidator(int_val);





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_g_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_g_cong_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_ajouter_employe_2_clicked()
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


/*void MainWindow::on_trouver_employe_3_clicked()
{
    employe e=tmpemploye.recherche_Id(ui->id_employe_mod->text().toInt());
    QString id= QString::number(e.getId());
    QString salaire= QString::number(e.getSalaire());
   // ui->id_emp_2->setText(id);
    ui->nom_emp_2->setText(e.getNom());
    ui->prenom_emp_2->setText(e.getprenom());
    ui->date_naissance_emp_2->setDate(e.getDate_naissance());
    ui->salaire_emp_2->setText(salaire);
}/*

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

void MainWindow::on_tab_widget_planning_2_currentChanged(int index)
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
void MainWindow::on_tab_widget_planning_currentChanged(int index)
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


void MainWindow::on_ajouter_conge_clicked()
{
    Conge c(ui->id_conge_e_1->text().toInt(),ui->duree_conge_e_1->text().toInt(),ui->date_conge_e_1->date(),ui->type_e_1->text(),ui->comboBox_id_emp->currentText().toInt());
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



void MainWindow::on_supprimer_conge_clicked()
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
void MainWindow::on_supprimer_employe_clicked()
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

void MainWindow::on_trouver_conge_clicked()
{
    Conge c =tmpconge.recherche_ref(ui->ref_conge_mod->text().toInt());
    QString ref= QString::number(c.getref());
    QString duree= QString::number(c.getduree());
    ui->ref_conge_e2->setText(ref);
    ui->duree_conge_e_2->setText(duree);
    ui->date_conge_e_2->setDate(c.getdate());
    ui->type_conge_e_2->setText(c.gettype());
}


void MainWindow::on_tri_emp_clicked()
{
    ui->tab_employe->setModel(tmpemploye.trier());
}

void MainWindow::on_tri_emp_2_clicked()
{
    ui->tab_employe->setModel(tmpemploye.trier1());

}


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




void MainWindow::on_tri_emp_3_clicked()
{
    ui->tab_employe->setModel(tmpemploye.trier2());

}



void MainWindow::on_comboBox_activated(const QString &arg1)
{

//ui->comboBox->setModel(tmpemploye.afficher());
//ui->tab_employe_3->setModel(tmpemploye.Filter(id));


}



void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
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
void MainWindow::on_combo2_currentTextChanged(const QString &arg1)
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


void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("lina.khammeri@esprit.tn","191JFT1097", "smtp.gmail.com", 465,30000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//ui->rcpt->text()

    smtp->sendMail("lina.khammeri@esprit.tn", ui->combomail->currentText() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_stats_2_clicked()
{
    statcng *s=new statcng();
    s->show();
}

void MainWindow::on_stats_clicked()
{
    statistiques *s=new statistiques();
    s->show();
}



void MainWindow::on_id_emp_textChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_Id(ui->id_emp->text().toInt());
    if(e.getprenom()!=""){
        ui->test_id_emp->setText("employe existe");
    }
    else{
        ui->test_id_emp->setText("");
    }
}

void MainWindow::on_modif_clicked()
{ //

}


void MainWindow::on_date_conge_e_8_textChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_Id(ui->date_conge_e_8->text().toInt());
    if(e.getprenom()!=""){
        ui->tst->setText("employe existe");
    }
    else{
        ui->tst->setText("");
    }
}



void MainWindow::on_rcpt_textChanged(const QString &arg1)
{
    employe e=tmpemploye.recherche_mail(ui->rcpt->text());
    if(e.getNom()!=""){
        ui->label_30->setText("l'email existe");
    }
    else{
        ui->label_30->setText("");
    }
}

void MainWindow::on_combomail_currentTextChanged(const QString &arg1)
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



void MainWindow::on_mdf_clicked()
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

void MainWindow::on_modifier_conge_clicked()
{
    Conge c(ui->comboc1->currentText().toInt(),ui->duree_conge_e_2->text().toInt(),ui->date_conge_e_2->date(),ui->type_conge_e_2->text(),ui->comboc1->currentText().toInt());
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

void MainWindow::on_id_conge_e_1_textChanged(const QString &arg1)
{
    Conge c=tmpconge.recherche_ref(ui->id_conge_e_1->text().toInt());
    if(c.gettype()!=""){
        ui->label_31->setText("conge existe");
    }
    else{
        ui->label_31->setText("");
    }
}

void MainWindow::on_comboc1_currentTextChanged(const QString &arg1)
{
    Conge c =tmpconge.recherche_ref(ui->comboc1->currentText().toInt());
    QString ref= QString::number(c.getref());
    QString duree= QString::number(c.getduree());
    ui->ref_conge_e2->setText(ref);
    ui->duree_conge_e_2->setText(duree);
    ui->date_conge_e_2->setDate(c.getdate());
    ui->type_conge_e_2->setText(c.gettype());
}

void MainWindow::on_Touslesconges_clicked()
{
     ui->tab_affichage_conge->setModel(tmpconge.trier());
}

void MainWindow::on_Touslesconges_2_clicked()
{
     ui->tab_affichage_conge->setModel(tmpconge.trier1());
}

void MainWindow::on_Touslesconges_3_clicked()
{
     ui->tab_affichage_conge->setModel(tmpconge.trier2());
}





void MainWindow::on_rech_emp2_clicked()
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


}}


void MainWindow::on_date_conge_e_4_textChanged(const QString &arg1)
{
    Conge c=tmpconge.recherche_ref(ui->date_conge_e_4->text().toInt());
    if(c.gettype()!=""){
        ui->label_35->setText("conge existe");
    }
    else{
        ui->label_35->setText("");
    }
}

void MainWindow::on_rech_emp2_2_clicked()
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
