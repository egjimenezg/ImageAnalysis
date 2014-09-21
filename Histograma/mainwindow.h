#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image.h"
#include "histogram.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setRGBImages();    

private slots:
    void openImage();    
    void expandHistogram();
    void reduceHistogram();

private:
    Ui::MainWindow *ui;
    QSignalMapper mapper;
    Image* image;
    Histogram** histogramas;
    void createActions();
    void initializeHistograms();

};

#endif // MAINWINDOW_H
