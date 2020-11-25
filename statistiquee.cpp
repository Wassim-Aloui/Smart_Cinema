#include "statistiquee.h"
#include "ui_statistiquee.h"
#include "abonnee.h"
#include <QtCharts/QBarCategoryAxis>
statistiquee::statistiquee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiquee)
{
    ui->setupUi(this);

    QBarSet *set1=new QBarSet("2");

           *set1 <<tmpabonnee.calculer(2)<<tmpabonnee.calculer(1)<<tmpabonnee.calculer(2);
           QBarSeries *series=new QBarSeries();
           series->append(set1);

           QChart *chart =new QChart();
           chart->addSeries(series);
           chart->setTitle("Les tarifs");
           chart->setAnimationOptions(QChart::GridAxisAnimations);
           QStringList tarif;
           tarif <<"Etudiant"<<"Enfant"<<"Tarif plein";
           QBarCategoryAxis *axis=new QBarCategoryAxis();
           axis->append(tarif);
           chart->createDefaultAxes();
           chart->setAxisX(axis,series);

           QChartView *chartview=new QChartView(chart);
           chartview->setRenderHint(QPainter::Antialiasing);

           QGridLayout *mainLayout = new QGridLayout;
           mainLayout->addWidget(chartview, 1, 1);
           setLayout(mainLayout);

           chartview->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    }

statistiquee::~statistiquee()
{
    delete ui;
}
