#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow){
  ui->setupUi(this);
  createActions();
  image = new Image();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::openImage(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imagen"),QDir::currentPath());

  if(!fileName.isEmpty()){
    QImage *img = new QImage(fileName); 
    if(img->isNull()){
      QMessageBox::information(this,tr("Image"),tr("El archivo %1 no es una imagen").arg(fileName));
      return;
    } 
    image->setImage(img);
    ui->originalImage->setPixmap(QPixmap::fromImage(*img));
    ui->originalImage->adjustSize();
    image->imageToBinary();
    ui->editedImage->setPixmap(QPixmap::fromImage(image->getImage()));
    ui->editedImage->adjustSize();
  }
}

void MainWindow::dilateImage(){
  image->dilate();
  ui->editedImage->setPixmap(QPixmap::fromImage(image->getImage()));
  ui->editedImage->adjustSize();

}

void MainWindow::createActions(){
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
  connect(ui->dilate,SIGNAL(released()),this,SLOT(dilateImage()));
}
