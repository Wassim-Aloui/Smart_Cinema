#ifndef STAT_EMPLOYE_H
#define STAT_EMPLOYE_H

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
#include"employe.h"


QT_CHARTS_USE_NAMESPACE
namespace Ui {
class stat_employe;
}

class stat_employe : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat_employe(QWidget *parent = nullptr);
    ~stat_employe();

private:
    Ui::stat_employe *ui;
    employe tmpemploye;
};

#endif // STAT_EMPLOYE_H
