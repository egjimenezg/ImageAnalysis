#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:
    void openImage();
    void dilateImage();
    void erodeImage();

private:
    Ui::MainWindow *ui;
    Image *image;
    void createActions();

};

#endif // MAINWINDOW_H
