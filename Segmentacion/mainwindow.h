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
    void openingImage();
    void closingImage();

private:
    Ui::MainWindow *ui;
    Image *image;
    void createActions();
    void init();
    void showButtons();
    void renderImageInLabel();

};

#endif // MAINWINDOW_H
