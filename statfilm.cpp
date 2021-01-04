#include "statfilm.h"
#include "ui_statfilm.h"
#include "film.h"
#include <QtCharts/QBarCategoryAxis>
statfilm::statfilm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statfilm)
{
    ui->setupUi(this);

    setWindowTitle("STATISTIQUE selon les genres des films");
       QBarSet *set1=new QBarSet("genre");


         *set1 <<tmpfilm.calculerromantiue(2)<<tmpfilm.calculeraction(1)<<tmpfilm.calculerhorreur(0);
              QBarSeries *series=new QBarSeries();
              series->append(set1);
              set1->append(20.0);

              QChart *chart =new QChart();
              chart->addSeries(series);
              chart->setTitle("Le nombre des films par genre");
              chart->setAnimationOptions(QChart::AllAnimations);

              QStringList categories;
              categories <<"romantique"<<"action"<<"horreur";
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

statfilm::~statfilm()
{
    delete ui;
}
