#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <vector>
#include "qcustomplot.h"
#include "tugas1.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QCustomPlot *aPlot;
    QCustomPlot *vPlot;
    QCustomPlot *xPlot;
    Tugas1 *tugas1;
};

#endif // MAINWINDOW_H

