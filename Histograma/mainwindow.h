#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "image.h"

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
    void createHistogram(int i);
    void expandHistogram();
    void initializeVectorValues();


private:
    Ui::MainWindow *ui;    
    QCustomPlot *qcustomplot;
    QCPBars* bars2;
    QSignalMapper mapper;
    Image* image;
    void createActions();
};

#endif // MAINWINDOW_H
