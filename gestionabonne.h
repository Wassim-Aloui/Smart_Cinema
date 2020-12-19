#ifndef GESTIONABONNE_H
#define GESTIONABONNE_H
#include <QDialog>
#include "abonnee.h"
#include"abonnement.h"
#include<QDialog>
#include<QSortFilterProxyModel>
#include<QSqlRelationalTableModel>
#include<QtCharts>
#include<QChartView>
#include<QBarSet>
#include<QBarSeries>
namespace Ui {
class gestionabonne;
}


class gestionabonne : public QDialog
{
    Q_OBJECT

public:
    explicit gestionabonne(QWidget *parent = nullptr);
    ~gestionabonne();



private slots:
    void on_g_abonnes_clicked();

    void on_g_abonnements_clicked();

    void on_ajouter_abonne_clicked();

    void on_supprimer_abonnee_clicked();

    void on_modifier_abonne_clicked();

    void on_ajouter_abonnement_1_clicked();

    void on_supprimer_abonnement_3_clicked();

    void on_modifier_abonnement_2_clicked();

    void on_chercher_abonnee_clicked();

    void on_radioButton_nom1_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_ville_clicked();

    void on_radioButton_tarif_clicked();



    void on_stat_abonnee_clicked();

    void on_typeButton_clicked();

    void on_prixButton_clicked();

    void on_afficher_abonne_clicked();

    void on_radioButton_afficher_clicked();



    void on_statistique_clicked();

    void on_afficher_abonnement_clicked();



    void on_chercher_abonnement_4_clicked();

    void on_afficher_abonnement_4_clicked();



    void on_statis_abonnement_clicked();

    void on_statis_chart_clicked();


    void on_radioButton_5_clicked();

    void on_afficher_abonnement_3_clicked();

    void on_afficher_abonnement_modif_clicked();

    void on_modifier_affiche_abonnement_clicked();

    void on_affiche_supp_abonnement_clicked();


         void showTime();

private:
    Ui::gestionabonne *ui;
    Abonnee tmpabonnee;
    Abonnement tmpabonnement;



};

#endif // GESTIONABONNE_H
