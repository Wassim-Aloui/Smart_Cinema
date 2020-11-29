#ifndef STATISTIQUESCONGE_H
#define STATISTIQUESCONGE_H


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
class statistiquesconge;
}
class statistiquesconge
{  Q_OBJECT
public:

    statistiquesconge();

    explicit statistiquesconge(QWidget *parent = nullptr);
    ~statistiquesconge();

private:
    Ui::statistiquesconge *ui;
    Conge tmpemploye;
};

#endif // STATISTIQUESCONGE_H
