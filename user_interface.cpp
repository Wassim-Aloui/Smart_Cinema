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
    ui->tableView_recherche->setModel(tmpfilm.chercher_film_avancee(id_film,nom_film,genre));
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
