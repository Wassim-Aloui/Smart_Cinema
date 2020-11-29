#include "statcng.h"
#include "ui_statcng.h"

statcng::statcng(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statcng)
{
    ui->setupUi(this);
    QPieSeries *series=new QPieSeries();
    series->append("< 15",tmpconge.calcul_conge(0,15));
    series->append("[15..30]",tmpconge.calcul_conge(15,30));
series->append("[30..60]",tmpconge.calcul_conge(30,60));

    QPieSlice *slice1=series->slices().at(1);
    slice1->setExploded(true);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("les durees des conges");
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartview=new QChartView(chart);

    this->setCentralWidget(chartview);
}

statcng::~statcng()
{
    delete ui;
}
