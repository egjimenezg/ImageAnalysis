#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow{
  Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private slots:
    void openImage();
    void compressImage();

  private:
    Ui::MainWindow *ui;
    Image *image;
    void bindEvents();
    void init();
};

#endif // MAINWINDOW_H
