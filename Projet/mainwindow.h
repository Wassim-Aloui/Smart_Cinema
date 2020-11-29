#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDate>
#include <QMainWindow>
#include"employe.h"
#include<QMessageBox>
#include"conge.h"
#include"smtp.h"
#include"statistiques.h"
#include"statcng.h"
#include<QValidator>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_g_emp_clicked();

    void on_g_cong_clicked();

    void on_ajouter_employe_2_clicked();

    void on_supprimer_employe_clicked();

    void on_trouver_employe_3_clicked();

    void on_modifier_employe_2_clicked();

    void on_tab_widget_planning_2_currentChanged(int index);

    void on_ajouter_conge_clicked();
    void on_supprimer_conge_clicked();
    void on_trouver_conge_clicked();

    void on_modifier_conge_clicked();

    void on_tab_widget_planning_currentChanged(int index);

    void on_tri_emp_clicked();

    void on_date_conge_e_7_textChanged(const QString &arg1);

    void on_rech_emp2_clicked();

    void on_tri_emp_2_clicked();

    void on_tri_emp_3_clicked();

    void on_date_conge_e_9_textChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void sendMail();
    void mailSent(QString);

    void on_stats_clicked();

    void on_id_emp_textChanged(const QString &arg1);

    void on_modif_clicked();

    void on_combo2_currentTextChanged(const QString &arg1);

    void on_date_conge_e_8_textChanged(const QString &arg1);

    void on_sendBtn_clicked();

    void on_rcpt_textChanged(const QString &arg1);

    void on_combomail_currentTextChanged(const QString &arg1);

    void on_modif_2_clicked();

    void on_mdf_clicked();

    void on_id_conge_e_1_textChanged(const QString &arg1);

    void on_comboc1_currentTextChanged(const QString &arg1);

    void on_Touslesconges_clicked();

    void on_Touslesconges_2_clicked();

    void on_Touslesconges_3_clicked();

    void on_pushButton_clicked();

    void on_stats_2_clicked();

private:
    Ui::MainWindow *ui;
    employe tmpemploye;
    Conge tmpconge;
};
#endif // MAINWINDOW_H
