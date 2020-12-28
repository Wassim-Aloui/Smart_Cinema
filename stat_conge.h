#ifndef STAT_CONGE_H
#define STAT_CONGE_H


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
class stat_conge;
}

class stat_conge : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat_conge(QWidget *parent = nullptr);
    ~stat_conge();

private:
    Ui::stat_conge *ui;
    conge tmpconge;
};
#endif // STAT_CONGE_H
