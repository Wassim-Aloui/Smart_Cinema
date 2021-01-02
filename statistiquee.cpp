#include "statistiquee.h"
#include "ui_statistiquee.h"
#include "abonnee.h"
#include <QtCharts/QBarCategoryAxis>
statistiquee::statistiquee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiquee)
{
    ui->setupUi(this);
 setWindowTitle("STATISTIQUE selon les tarifs des abonnés");
    QBarSet *set1=new QBarSet("Tarif");


      *set1 <<tmpabonnee.calculer(2)<<tmpabonnee.calculerenfant(1)<<tmpabonnee.calculertarif(0);
           QBarSeries *series=new QBarSeries();
           series->append(set1);
           set1->append(20.0);

           QChart *chart =new QChart();
           chart->addSeries(series);
           chart->setTitle("Le nombre d'abonnés par tarif");
           chart->setAnimationOptions(QChart::AllAnimations);

           QStringList categories;
           categories <<"Etudiant"<<"Enfant"<<"Tarif plein";
           QBarCategoryAxis *axis=new QBarCategoryAxis();
           axis->append(categories);

           chart->createDefaultAxes();
           chart->setAxisX(axis,series);


           QChartView *chartview=new QChartView(chart);
           chartview->setRenderHint(QPainter::HighQualityAntialiasing);

           QGridLayout *mainLayout = new QGridLayout;
           mainLayout->addWidget(chartview, 1, 1);
           setLayout(mainLayout);

           set1->setColor(Qt::red);



}

statistiquee::~statistiquee()
{
    delete ui;
}
