#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<double> x;
    QVector<double> y;

private slots:
    void openImage();
    void initializePlot();
    void createHistograma(int i);
    void initializeVectorValues();

private:
    Ui::MainWindow *ui;
    QImage* image;
    QCustomPlot *qcustomplot;
    QCPBars* bars2;
    QSignalMapper mapper;
    void createActions();

};

#endif // MAINWINDOW_H
