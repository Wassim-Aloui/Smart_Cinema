#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include"planning.h"
#include"film.h"
#include"smtp.h"
#include <QMainWindow>

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

private:
    Ui::user_interface *ui;
    planning tmpplanning;
    film tmpfilm;
};

#endif // USER_INTERFACE_H
