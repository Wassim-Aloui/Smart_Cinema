#include "statistique.h"
#include "ui_statistique.h"

statistique::statistique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    //The QPieSeries class presents data in pie charts
    QPieSeries *series=new QPieSeries();
    //The QLineSeries class presents data in line charts.
      series->append("[0..100]",Etmp.calcul_produit(0,50));
      series->append("[50..100]",Etmp.calcul_produit(50,100));
      series->append("[100..150]",Etmp.calcul_produit(100,150));

      //The QPieSlice class represents a single slice in a pie series
      QPieSlice *slice1=series->slices().at(1);
      slice1->setExploded(true);

      QChart *chart =new QChart();
      chart->addSeries(series);
      chart->setTitle("statistique des produit selon nombre");
      chart->setAnimationOptions(QChart::AllAnimations);
      QChartView *chartview=new QChartView(chart);
      this->setCentralWidget(chartview);
}

statistique::~statistique()
{
    delete ui;
}
