#include "statistiquee.h"
#include "ui_statistiquee.h"
#include "abonnee.h"
#include <QtCharts/QBarCategoryAxis>
statistiquee::statistiquee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiquee)
{
    ui->setupUi(this);
 setWindowTitle("STATISTIQUE");
    QBarSet *set1=new QBarSet("Tarif");

           *set1 <<tmpabonnee.calculer(1)<<tmpabonnee.calculer(2)<<tmpabonnee.calculer(3);
           QBarSeries *series=new QBarSeries();
           series->append(set1);
           set1->append(20.0);

           QChart *chart =new QChart();
           chart->addSeries(series);
           chart->setTitle("Le nombre d'abonnés par tarif");
           chart->setAnimationOptions(QChart::GridAxisAnimations);

           QStringList categories;
           categories <<"Etudiant"<<"Enfant"<<"Tarif plein";
           QBarCategoryAxis *axis=new QBarCategoryAxis();
           axis->append(categories);

           //chart->createDefaultAxes();
           chart->setAxisX(axis,series);

                   QValueAxis *axisY = new QValueAxis();
                   axisY->setTitleText("NOMBRE D'ABONNES");
                   axisY->setLabelFormat("%g");
                   chart->addAxis(axisY, Qt::AlignLeft);
                   series->attachAxis(axisY);
                   series->attachAxis(axisY);


           QChartView *chartview=new QChartView(chart);
           chartview->setRenderHint(QPainter::HighQualityAntialiasing);

           QGridLayout *mainLayout = new QGridLayout;
           mainLayout->addWidget(chartview, 1, 1);
           setLayout(mainLayout);

           chartview->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);




}

statistiquee::~statistiquee()
{
    delete ui;
}
