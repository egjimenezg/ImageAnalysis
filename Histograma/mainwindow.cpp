#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtWidgets>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  createActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imagen"),QDir::currentPath());
  if(!fileName.isEmpty()){
    image = new QImage(fileName);
    if(image->isNull()){
      QMessageBox::information(this,tr("Image"),tr("El archivo %1 no es una imagen").arg(fileName));
      return;
    }

    ui->imagew->setPixmap(QPixmap::fromImage(*image));
    ui->imagew->adjustSize();


  }

}

void MainWindow::createActions(){
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
}

