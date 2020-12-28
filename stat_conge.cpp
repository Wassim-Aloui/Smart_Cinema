#include "stat_conge.h"
#include "ui_stat_conge.h"


stat_conge::stat_conge(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stat_conge)
{
    ui->setupUi(this);
    QPieSeries *series=new QPieSeries();
    series->append("< 15",tmpconge.calcul_conge(0,15));
    series->append("[15..20]",tmpconge.calcul_conge(15,20));
series->append("[20..30]",tmpconge.calcul_conge(20,30));

    QPieSlice *slice1=series->slices().at(1);
    slice1->setExploded(true);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("les durees des conges");
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartview=new QChartView(chart);

    this->setCentralWidget(chartview);
}

stat_conge::~stat_conge()
{
    delete ui;
}
