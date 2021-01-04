#ifndef STATFILM_H
#define STATFILM_H
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
#include"film.h"
#include <QAbstractTableModel>
QT_CHARTS_USE_NAMESPACE
#include <QDialog>

namespace Ui {
class statfilm;
}

class statfilm : public QDialog
{
    Q_OBJECT

public:
    explicit statfilm(QWidget *parent = nullptr);
    ~statfilm();

private:
    Ui::statfilm *ui;
    film tmpfilm;
};

#endif // STATFILM_H
