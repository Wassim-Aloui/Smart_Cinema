#ifndef ADMIN_H
#define ADMIN_H
#include <QString>
#include <QSqlQueryModel>

class Admin
{
        int id;
        QString nom;
        QString prenom;

        QString username;
        QString password;

    public:
        Admin();
        Admin(int ,QString ,QString ,QString ,QString );
        ~Admin();

        int getId();
        void setId(int);
        QString getNom();
        void setNom(QString);
        QString getprenom();
        void setPrenom(QString);
        QString getusername();
        void setusername(QString);
        QString getpassword();
        void setpassword(QString);
        void login();


        bool ajouter();
        bool supprimer(int);
        bool modifier(int);
        QSqlQueryModel* afficher();
        Admin recherche_Id(int);
        Admin recherche_mail(QString);
        QSqlQueryModel* trier();
        QSqlQueryModel* trier1();
        QSqlQueryModel* trier2();
        bool modifier(int idc ,QString nom,QString prenom,QString username,QString password);
        QSqlQueryModel * chercher_admin_par_nom(QString m);
        QSqlQueryModel * chercher_admin_par_prenom(QString p);
        QSqlQueryModel * chercher_admin_par_id(QString idd);
         QSqlQueryModel* Filter(int);
         bool verifierExnoms(QString);
          QSqlQueryModel* recherche_nom(QString);
        QStringList listemploye();
        QStringList listemploye1();
        int calcul_employe(int,int);
};

#endif // ADMIN_H
