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



class planning
{
public:
    planning();
    planning(int,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_date_planning();
    QString get_heure();
    void setId(int);
    void setNom(QString);
    void setDateplanning(QString);
    void setHeure(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int);
    bool modifier(int);
    bool rech(int x);

    QSqlQueryModel * chercher_planning_avancee(QString nom,QString heure,QString date);
    QSqlQueryModel * trier(QString);
    void exporter(QTableView *table);
    QStringList listplanning();
     planning recherche_Id(int);
private:
    QString nom,date_planning,heure;
    int id;




};

#endif // PLANNING_H
