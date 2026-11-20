#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QtCharts>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCandlestickSeries* series = new QCandlestickSeries();
    series->setIncreasingColor(Qt::green);
    series->setDecreasingColor(Qt::red);

    qint64 baseTime = QDateTime(QDate(2026, 11, 20), QTime(9, 30)).toMSecsSinceEpoch();
    qint64 interval = 60 * 1000; // 1 minute in ms (use 86400 * 1000 for 1 day)

    series->append(new QCandlestickSet(100, 110, 95, 105, baseTime));
    series->append(new QCandlestickSet(105, 108, 98, 100, baseTime + interval));
    series->append(new QCandlestickSet(100, 115, 99, 112, baseTime + 2 * interval));

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();

    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}
