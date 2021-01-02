#ifndef PLANNING_H
#define PLANNING_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include<QFile>
#include <QFileDialog>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <qtextbrowser.h>


class planning
{
public:
    planning();
    planning(int,QString,QString,QString);
    int get_id_planning();
    QString get_nom_planning();
    QString get_date_planning();
    QString get_heure();
    void setId_planning(int);
    void setNom_planning(QString);
    void setDateplanning(QString);
    void setHeure(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int);
    bool modifier(int);
    bool rech(int x);

    QSqlQueryModel * chercher_planning_avancee(QString nom_planning,QString heure,QString date_planning);
    QSqlQueryModel * trier(QString);

    QStringList listplanning();
     planning recherche_Id_planning(int);
private:
    QString nom_planning,date_planning,heure;
    int id_planning;




};

#endif // PLANNING_H
