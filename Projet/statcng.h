#ifndef STATCNG_H
#define STATCNG_H

#include <QMainWindow>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include"conge.h"


QT_CHARTS_USE_NAMESPACE
namespace Ui {
class statcng;
}

class statcng : public QMainWindow
{
    Q_OBJECT

public:
    explicit statcng(QWidget *parent = nullptr);
    ~statcng();

private:
    Ui::statcng *ui;
    Conge tmpconge;
};

#endif // STATCNG_H
