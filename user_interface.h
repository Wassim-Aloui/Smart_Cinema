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

    void on_msg_2_textChanged();

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

    void on_test_id_emp_linkActivated(const QString &link);

private:
    Ui::user_interface *ui;
    planning tmpplanning;
    film tmpfilm;
    employe tmpemploye;
    conge tmpconge;
};

#endif // USER_INTERFACE_H
