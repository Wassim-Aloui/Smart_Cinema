#include "stat2.h"
#include "ui_stat2.h"
#include <QtCharts/QBarCategoryAxis>
Stat2::Stat2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stat2)
{
    ui->setupUi(this);
    setWindowTitle("STATISTIQUE selon les types des abonnements");
       QBarSet *set1=new QBarSet("Type d'abonnement");


         *set1 <<tmpabonnement.calculertype1(2)<<tmpabonnement.calculertype2(1)<<tmpabonnement.calculertype3(0);
              QBarSeries *series=new QBarSeries();
              series->append(set1);
              set1->append(20.0);

              QChart *chart =new QChart();
              chart->addSeries(series);
              chart->setTitle("Le nombre d'abonnement par type d'abonnement");
              chart->setAnimationOptions(QChart::AllAnimations);

              QStringList categories;
              categories <<"Cinepass duo"<<"Cinepass "<<"Cinepass -26";
              QBarCategoryAxis *axis=new QBarCategoryAxis();
              axis->append(categories);

              chart->createDefaultAxes();
              chart->setAxisX(axis,series);

              QChartView *chartview=new QChartView(chart);
              chartview->setRenderHint(QPainter::HighQualityAntialiasing);

              QGridLayout *mainLayout = new QGridLayout;
              mainLayout->addWidget(chartview, 1, 1);
              setLayout(mainLayout);

              set1->setColor(Qt::black);

}

Stat2::~Stat2()
{
    delete ui;
}

