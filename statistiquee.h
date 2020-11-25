#ifndef STATISTIQUEE_H
#define STATISTIQUEE_H
#include <QWidget>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QGridLayout>
#include"abonnee.h"
QT_CHARTS_USE_NAMESPACE

#include <QDialog>

namespace Ui {
class statistiquee;
}

class statistiquee : public QDialog
{
    Q_OBJECT

public:
    explicit statistiquee(QWidget *parent = nullptr);
    ~statistiquee();

private:
    Ui::statistiquee *ui;
  Abonnee tmpabonnee;
};

#endif // STATISTIQUEE_H
