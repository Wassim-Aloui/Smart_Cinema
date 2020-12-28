#include "stat_employe.h"
#include "ui_stat_employe.h"

stat_employe::stat_employe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stat_employe)
{
    ui->setupUi(this);
    QPieSeries *series=new QPieSeries();
    series->append("< 500",tmpemploye.calcul_employe(0,500));
    series->append("[500..1000]",tmpemploye.calcul_employe(500,1000));
    series->append("[1000..1500]",tmpemploye.calcul_employe(1000,1500));
    series->append("[1500..2000]",tmpemploye.calcul_employe(1500,2000));

    QPieSlice *slice1=series->slices().at(1);
    slice1->setExploded(true);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("les salaires des employes");
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartview=new QChartView(chart);

    this->setCentralWidget(chartview);
}

stat_employe::~stat_employe()
{
    delete ui;
}
