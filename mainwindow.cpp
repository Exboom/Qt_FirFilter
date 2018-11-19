#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <timex.h>
#include <fir_fil.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    double X[1024];
    double Xfilter[1024]={0};
    double timex[1024];
    timeX(X,timex);
    fir_filter(X,Xfilter);


    graph1 = new QChart;
    ui->widget->setChart(graph1); // связь графика с элементом отображения
    graph1->setTitle("Исходный сигнал");

    graph2 = new QChart;
    ui->widget_2->setChart(graph2); // связь графика с элементом отображения
    graph2->setTitle("Отфильтрованный сигнал");

    // ось Х 1
    QValueAxis *axisX1 = new QValueAxis;
    axisX1->setRange(0, timeD*1024); // диапазон значений на оси
    axisX1->setTickCount(15); // число линий сетки
    axisX1->setLabelFormat("%.3f"); // формат отображения чисел на оси
    // ось Х 2
    QValueAxis *axisX2 = new QValueAxis;
    axisX2->setRange(0, timeD*1024);
    axisX2->setTickCount(15);
    axisX2->setLabelFormat("%.3f");

    // ось Y 1
    QValueAxis *axisY1 = new QValueAxis;
    axisY1->setRange(-40, 40);
    axisY1->setTickCount(7);
    axisY1->setLabelFormat("%i");
    // ось Y 2
    QValueAxis *axisY2 = new QValueAxis;
    axisY2->setRange(-40, 40);
    axisY2->setTickCount(7);
    axisY2->setLabelFormat("%i");

    // кривые, отображаемые на графике
    QLineSeries* series1 = new QLineSeries();
    QLineSeries* series2 = new QLineSeries();

    // построение графиков функций
    for(int i = 0; i<1024; i++)
    {
        series1->append(timex[i],X[i]);
        series2->append(timex[i],Xfilter[i]);
    }

    // связываем график с построенными кривыми
    graph1->addSeries(series1); graph2->addSeries(series2);
    // устанавливаем оси для каждого графика
    graph1->setAxisX(axisX1, series1); graph1->setAxisY(axisY1, series1);
    graph2->setAxisX(axisX2, series2); graph2->setAxisY(axisY2, series2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
