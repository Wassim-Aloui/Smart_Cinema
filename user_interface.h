#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include"planning.h"
#include"film.h"
#include"smtp.h"
#include<QDate>
#include <QMainWindow>
#include"employe.h"
#include<QMessageBox>
#include"conge.h"
#include"smtp_employe.h"
#include"stat_conge.h"
#include"stat_employe.h"
#include<QValidator>
#include<QPrintDialog>
#include<qtextbrowser.h>
#include "commande.h"
#include "produit.h"
#include "arduino_led.h"
#include "statistique.h"
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include "abonnee.h"
#include "abonnement.h"
#include "statistiquee.h"
#include "stat2.h"
#include "smtp_produit.h"

namespace Ui {
class user_interface;
}

class user_interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit user_interface(QWidget *parent = nullptr);
    ~user_interface();

private slots:
    void on_g_film_clicked();

    void on_g_plng_clicked();

    void on_ajouter_planning_clicked();

    void on_supprimer_planning_clicked();

    void on_modifier_planning_clicked();

    void on_ajouter_film_clicked();

    void on_modifier_film_clicked();

    void on_supprimer_film_clicked();

    void on_chercher_film_clicked();

    void on_chercher_planning_clicked();

    void on_Trier_planning_clicked();
    void on_Exporter_planning_clicked();

    void on_Trier_film_clicked();

    void on_comboBox_supprimer_planning_currentTextChanged(const QString &arg1);

    void on_tab_Widget_planning_currentChanged(int index);

    void on_comboBox_modifier_planning_currentTextChanged(const QString &arg1);

    void on_Exporter_film_clicked();

    void on_comboBox_supprimer_film_currentTextChanged(const QString &arg1);

    void on_tab_widget_film_currentChanged(int index);

    void on_comboBox_modifier_film_currentTextChanged(const QString &arg1);

    void on_Mail_clicked();

    void on_g_emp_clicked();

    void on_email_emp_textChanged(const QString &arg1);

    void on_rech_emp2_clicked();

    void on_rech_emp2_2_clicked();
    void sendMail();
    void mailSent(QString);

    void on_date_conge_e_9_textChanged(const QString &arg1);

    void on_date_conge_e_4_textChanged(const QString &arg1);

    void on_Tricongetype_clicked();

    void on_Touslesconges_2_clicked();

    void on_Touslesconges_clicked();

    void on_id_conge_e_1_textChanged(const QString &arg1);

    void on_mdf_clicked();

    void on_combomail_currentTextChanged(const QString &arg1);

    void on_modifier_conge_clicked();

    void on_comboc1_currentTextChanged(const QString &arg1);

    void on_rcpt_textChanged(const QString &arg1);

    //void on_msg_2_textChanged();

    void on_date_conge_e_8_textChanged(const QString &arg1);

    void on_id_emp_textChanged(const QString &arg1);

    void on_stats_clicked();

    void on_stats_2_clicked();

    void on_combo2_currentTextChanged(const QString &arg1);

    void on_tri_emp_2_clicked();

    void on_tri_emp_clicked();

    void on_supprimer_employe_clicked();

    void on_supprimer_conge_clicked();

    void on_ajouter_conge_clicked();

    void on_tab_widget_conge_currentChanged(int index);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_tri_emp_3_clicked();

    void on_ajouter_employe_2_clicked();

    void on_tab_widget_employe_currentChanged(int index);

    void on_g_cong_clicked();

    //void on_test_id_emp_linkActivated(const QString &link);

    void on_g_prd_clicked();

    void on_g_cmd_clicked();

    void on_ajouter_produit_clicked();

    void on_modifier_produit_clicked();

    void on_supprimer_produit_clicked();

    void on_chercher_produit_clicked();

    void on_radioButto_afficher_commande_3_clicked();

    void on_radioButton_produit_clicked();

    void on_radioButto_afficher_commande_2_clicked();

    void on_afficher_id_produit_clicked();

    void on_afficher_nom_produit_clicked();

    void on_afficher_nombre_produit_clicked();

    void on_statistique_prod_clicked();

    void on_load_produit_id_clicked();
    void showTime();
    void on_open_clicked();
    void on_close_clicked();
    void on_ajouter_commande_clicked();
    void on_modifier_commande_clicked();
    void on_supprimer_commande_clicked();
    void on_rechercher_commande_clicked();

    void on_radioButton_commande_2_clicked();

    void on_radioButton_commande_clicked();

    void on_reference_commande_2_clicked();

    void on_modifier_commande_3_clicked();

    void on_modifier_commande_4_clicked();

    void on_load_commande_ref_clicked();

    void on_pdf_commande_clicked();

    void on_pushButton_write_clicked();

    void on_pushButton_read_clicked();

    void on_radioButto_afficher_commande_clicked();

    void on_g_abonnes_clicked();

    void on_g_abonnements_clicked();

    void on_ajouter_abonne_clicked();

    void on_modifier_abonne_clicked();

    void on_modifier_affiche_abonne_clicked();

    void on_supprimer_abonnee_clicked();

    void on_affiche_supp_abonne_clicked();

    void on_radioButton_nom1_clicked();

    void on_radioButton_ville_clicked();

    void on_radioButton_tarif_clicked();

    void on_afficher_abonne_clicked();

    void on_notee_clicked();

    void on_chercher_abonnee_clicked();

    void on_radioButton_afficher_clicked();

    void on_stat_abonnee_clicked();

    void on_statistique_clicked();

    void on_ajouter_abonnement_1_clicked();

    void on_radioButton_5_clicked();

    void on_modifier_abonnement_2_clicked();

    void on_afficher_abonnement_modif_clicked();

    void on_supprimer_abonnement_3_clicked();

    void on_afficher_abonnement_3_clicked();

    void on_afficher_abonnement_4_clicked();

    void on_radioButton_4_clicked();

    void on_typeButton_clicked();

    void on_prixButton_clicked();

    void on_chercher_abonnement_4_clicked();

    void on_afficher_abonnement_clicked();

    void on_statis_abonnement_clicked();

    void on_statis_chart_clicked();

    void on_write1_clicked();

    void on_read1_clicked();

    void on_pushButton_envoyerMail_clicked();

    void on_g_emp_pressed();

    void on_g_cong_pressed();

    void on_g_film_pressed();

    void on_g_plng_pressed();

    void on_g_salle_pressed();

    void on_g_prd_pressed();

    void on_g_cmd_pressed();

    void on_g_abonnes_pressed();

    void on_g_abonnements_pressed();

    void on_sendBtn_clicked();

private:
    Ui::user_interface *ui;
    planning tmpplanning;
    film tmpfilm;
    employe tmpemploye;
    conge tmpconge;
    produit Etmp;
    commande Com;
    QByteArray data;
    arduino_led A;
    Abonnee tmpabonnee;
    Abonnement tmpabonnement;
};

#endif // USER_INTERFACE_H
