#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include"planning.h"
#include"film.h"
#include <QMainWindow>

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

private:
    Ui::user_interface *ui;
    planning tmpplanning;
    film tmpfilm;
};

#endif // USER_INTERFACE_H
