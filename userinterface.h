#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <QMainWindow>
#include "produit.h"
#include <QMessageBox>
#include "commande.h"
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinterInfo>
#include "statistique.h"
#include <QDebug>
#include <qpixmap.h>
#include "arduino.h"
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>


namespace Ui {
class userInterface;
}

class userInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit userInterface(QWidget *parent = nullptr);
    ~userInterface();

private slots:
    void on_g_prd_clicked();
    void on_g_cmd_clicked();
    void on_ajouter_produit_clicked();
    void on_supprimer_produit_clicked();
    void on_ajouter_commande_clicked();
    void on_supprimer_commande_clicked();
    void on_radioButton_produit_clicked();
    void on_radioButton_commande_clicked();
    void on_modifier_commande_clicked();
    void on_modifier_produit_clicked();
    void on_radioButto_afficher_commande_clicked();
    void on_chercher_produit_clicked();
    void on_radioButto_afficher_commande_2_clicked();
    void on_reference_commande_2_clicked();
    void on_supprimer_2_clicked();
    void on_modifier_commande_3_clicked();
    void on_modifier_commande_4_clicked();
    void on_rechercher_commande_clicked();
    void on_afficher_id_produit_clicked();
    void on_radioButton_commande_2_clicked();
    void on_afficher_nom_produit_clicked();
    void on_afficher_nombre_produit_clicked();
    void on_radioButto_afficher_commande_3_clicked();
    void on_pdf_commande_clicked();
    void on_load_commande_ref_clicked();
    void on_load_produit_id_clicked();
    void on_statistique_prod_clicked();
    void on_open_clicked();
    void on_close_clicked();
    void showTime_p();



    void on_pushButton_write_clicked();

    void on_pushButton_read_clicked();

private:
    Ui::userInterface *ui;
    produit Etmp;
    commande Com;
    QByteArray data;
    arduino A;
};

#endif // USERINTERFACE_H
