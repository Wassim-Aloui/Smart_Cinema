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


class planning
{
public:
    planning();
    planning(int,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_date_planning();
    QString get_heure();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int);
    bool modifier(int,QString,QString,QString);
    bool rech(int x);
    QSqlQueryModel * chercher_planning_date(QString  date);
    QSqlQueryModel * chercher_planning_heure(QString  heure);
    QSqlQueryModel * chercher_planning_nom(QString nom);
    QSqlQueryModel * trier(QString);
    void exporter(QTableView *table);
private:
    QString nom,date_planning,heure;
    int id;




};

#endif // PLANNING_H
