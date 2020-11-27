#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("ID");

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
    employe e(ui->id_emp->text().toInt(),ui->nom_emp->text(),ui->prenom_emp->text(),ui->date_naissance_emp->date(),ui->salaire_emp->text().toDouble());
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
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimer_employe_clicked()
{
    bool test=tmpemploye.supprimer(ui->id_employe_sup->text().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Employe"),
                    QObject::tr("employé supprimé avec succés.\n"), QMessageBox::Cancel);
        ui->tab_employe->setModel(tmpemploye.afficher());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_trouver_employe_3_clicked()
{
    employe e=tmpemploye.recherche_Id(ui->id_employe_mod->text().toInt());
    QString id= QString::number(e.getId());
    QString salaire= QString::number(e.getSalaire());
    ui->id_emp_2->setText(id);
    ui->nom_emp_2->setText(e.getNom());
    ui->prenom_emp_2->setText(e.getprenom());
    ui->date_naissance_emp_2->setDate(e.getDate_naissance());
    ui->salaire_emp_2->setText(salaire);
}

void MainWindow::on_modifier_employe_2_clicked()
{
    employe e(ui->id_emp_2->text().toInt(),ui->nom_emp_2->text(),ui->prenom_emp_2->text(),ui->date_naissance_emp_2->date(),ui->salaire_emp_2->text().toDouble());
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
}

void MainWindow::on_tab_widget_planning_2_currentChanged(int index)
{
    ui->tab_employe->setModel(tmpemploye.afficher());
}
void MainWindow::on_tab_widget_planning_currentChanged(int index)
{
    ui->tab_affichage_conge->setModel(tmpconge.afficher());

}


void MainWindow::on_ajouter_conge_clicked()
{
    Conge c(ui->id_conge_e_1->text().toInt(),ui->duree_conge_e_1->text().toInt(),ui->date_conge_e_1->date(),ui->type_e_1->text());
    bool test=c.ajouter1();
    if(test) {
        QMessageBox::information(nullptr, QObject::tr("Conge"),
                    QObject::tr("congé ajouté avec succés.\n"), QMessageBox::Cancel);
        ui->tab_affichage_conge->setModel(tmpconge.afficher());
        ui->id_conge_e_1->setText("");
        ui->duree_conge_e_1->setText("");
        ui->date_conge_e_1->setDate(QDate(2000,01,01));
        ui->type_e_1->setText("");
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Conge"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}


void MainWindow::on_modifier_conge_clicked()
{
    Conge c(ui->ref_conge_e2->text().toInt(),ui->duree_conge_e_2->text().toInt(),ui->date_conge_e_2->date(),ui->type_conge_e_2->text());
    bool test=c.modifier(ui->ref_conge_mod->text().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Conge"),
                    QObject::tr("congé modifié avec succés.\n"), QMessageBox::Cancel);
        ui->tab_employe->setModel(tmpconge.afficher());
        ui->ref_conge_e2->setText("");
        ui->duree_conge_e_2->setText("");
        ui->date_conge_e_2->setDate(QDate(2000,01,01));
        ui->type_conge_e_2->setText("");
        ui->ref_conge_mod->setText("");
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Conge"),
                    QObject::tr("Echec!\n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimer_conge_clicked()
{
    bool test=tmpconge.supprimer(ui->ref_conge_sup->text().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Conge"),
                    QObject::tr("congé supprimé avec succés.\n"), QMessageBox::Cancel);
        ui->tab_affichage_conge->setModel(tmpconge.afficher());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Conge"),
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


void MainWindow::on_date_conge_e_7_textChanged(const QString &arg1)
{
    //ui->tab_employe_2->setModel(tmpemploye.rechercher(ui->date_conge_e_7->text())); ///lcase mta3 rechercher( ui->date_conge_e_7->text()))

}



void MainWindow::on_rech_emp2_clicked()            ///
{
  // ui->tab_employe_2->setModel(tmpemploye.rechercher(ui->date_conge_e_7->text(),ui->date_conge_e_9->text(),ui->date_conge_e_8->text().toInt())); ///lcase mta3 rechercher( ui->date_conge_e_7->text()))
   //ui->tab_employe_2->setModel(tmpemploye.rechercher(ui->date_conge_e_9->text()));
   QString m =ui->date_conge_e_7->text();
       QString l = ui->date_conge_e_8->text(); //id
         QString k = ui->date_conge_e_9->text();

       if (m != ""){
      ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_nom(m)) ;}
       if (l != ""){
      ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_id(l)) ;}
       else if (k!= ""){
      ui->tab_employe_2->setModel(tmpemploye.chercher_employe_par_prenom(k)) ;
}

       }




void MainWindow::on_tri_emp_3_clicked()
{
    ui->tab_employe->setModel(tmpemploye.trier2());

}



void MainWindow::on_comboBox_activated(const QString &arg1)
{

ui->comboBox->setModel(tmpemploye.afficher());
//ui->tab_employe_3->setModel(tmpemploye.Filter(id));


}

/*void MainWindow::on_comboBox_currentIndexChanged(int index)
{// ui->comboBox->setModel(tmpemploye.afficher());
   // ui->comboBox->currentIndex();
       // ui->tab_employe_3->setModel(tmpemploye.Filter(index));
}*/

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
      //QString value= ui->comboBox->currentText();
      //int id;
      QSqlQuery qry;
      qry.prepare("select id from employe where id='"+arg1+"' ");
      qry.bindValue(":id",ui->comboBox->currentText());
          if ( qry.exec() && qry.next())
          {
      ui->id_emp_2->setText(qry.value(0).toString());
       ui->nom_emp_2->setText(qry.value(1).toString());
        ui->prenom_emp_2->setText(qry.value(2).toString());
         ui->date_naissance_emp_2->setDate(qry.value(3).toDate());
         ui->salaire_emp_2->setText(qry.value(4).toString()); }
    /*QString nom=ui->comboBox->currentText();
    employe e=tmpemploye.recherche_Id(ui->id_employe_mod->text().toInt());
    QString id= QString::number(e.getId());
    QString salaire= QString::number(e.getSalaire());
    ui->id_emp_2->setText(id);
    ui->nom_emp_2->setText(e.getNom());
    ui->prenom_emp_2->setText(e.getprenom());
    ui->date_naissance_emp_2->setDate(e.getDate_naissance());
    ui->salaire_emp_2->setText(salaire);*/
}


