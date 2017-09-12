#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Tugas
    tugas1 = new Tugas1();
    tugas1->setInitVelocity(-10); //set kecepatan awal
    tugas1->setInitPosition(2); // set posisi awal
    tugas1->setTimeRange(0, 10, 1000); // set range waktu
    tugas1->setInitialGuess(1, 2); // set tebakan awal bisection
    tugas1->calculate(); // hitung

    //Plot
    QVector<double> accel = QVector<double>::fromStdVector(tugas1->getAcceleration());
    QVector<double> veloc =  QVector<double>::fromStdVector(tugas1->getVelocity());
    QVector<double> pos =  QVector<double>::fromStdVector(tugas1->getPosition());
    QVector<double> time =  QVector<double>::fromStdVector(tugas1->getTime());

    aPlot = new QCustomPlot();
    vPlot = new QCustomPlot();
    xPlot = new QCustomPlot();

    aPlot->plotLayout()->insertRow(0);
    vPlot->plotLayout()->insertRow(0);
    xPlot->plotLayout()->insertRow(0);

    aPlot->plotLayout()->addElement(0, 0, new QCPTextElement(aPlot, "Percepatan Terhadap Waktu"));
    vPlot->plotLayout()->addElement(0, 0, new QCPTextElement(vPlot, "Kecepatan Terhadap Waktu"));
    xPlot->plotLayout()->addElement(0, 0, new QCPTextElement(xPlot, "Posisi Terhadap Waktu"));

    aPlot->yAxis->setLabel("Percepatan a(m/s^2)");
    vPlot->yAxis->setLabel("Kecepatan v(m/s)");
    xPlot->yAxis->setLabel("Posisi x(m)");

    aPlot->xAxis->setLabel("Waktu t(s)");
    vPlot->xAxis->setLabel("Waktu t(s)");
    xPlot->xAxis->setLabel("Waktu t(s)");

    aPlot->addGraph();
    aPlot->graph(0)->setData(time, accel);
    aPlot->rescaleAxes();
    aPlot->axisRect()->setupFullAxesBox(true);

    vPlot->addGraph();
    vPlot->graph(0)->setData(time, veloc);
    vPlot->rescaleAxes();
    vPlot->axisRect()->setupFullAxesBox(true);

    xPlot->addGraph();
    xPlot->graph(0)->setData(time, pos);
    xPlot->rescaleAxes();
    xPlot->axisRect()->setupFullAxesBox(true);

    aPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    vPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    xPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    QLabel *akarLabel = new QLabel();
    akarLabel->setText(QString("Kecepatan benda sama dengan nol (v(t=0)) ketika t=" + QString::number(tugas1->getZeroVelocity())));
    akarLabel->setAlignment(Qt::AlignCenter);

    QGridLayout *plotLayout = new QGridLayout();
    plotLayout->addWidget(aPlot, 0, 0);
    plotLayout->addWidget(vPlot, 0, 1);
    plotLayout->addWidget(xPlot, 1, 0);
    plotLayout->addWidget(akarLabel, 1, 1);

    QWidget *plotWidget = new QWidget();
    plotWidget->setLayout(plotLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(plotWidget);
    mainLayout->setSpacing(0);

    QWidget *central = new QWidget();
    central->setLayout(mainLayout);

    this->setCentralWidget(central);
}

MainWindow::~MainWindow()
{
    delete ui;
}

