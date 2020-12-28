#ifndef STAT2_H
#define STAT2_H
#include <QDialog>
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
#include"abonnement.h"
#include <QAbstractTableModel>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class Stat2;
}

class Stat2 : public QDialog
{
    Q_OBJECT

public:
    explicit Stat2(QWidget *parent = nullptr);
    ~Stat2();

private:
    Ui::Stat2 *ui;
    Abonnement tmpabonnement;
};

#endif // STAT2_H
