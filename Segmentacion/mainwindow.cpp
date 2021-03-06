#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow){
  ui->setupUi(this);
  init();
  createActions();
  image = new Image();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::init(){
  ui->dilate->setVisible(false);
  ui->erode->setVisible(false);
  ui->opening->setVisible(false);
  ui->closing->setVisible(false);
  ui->countButton->setVisible(false);
  ui->border->setVisible(false);
}

void MainWindow::showButtons(){
  ui->dilate->setVisible(true);
  ui->erode->setVisible(true);
  ui->opening->setVisible(true);
  ui->closing->setVisible(true);
  ui->countButton->setVisible(true);
  ui->border->setVisible(true);
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
    renderImageInLabel();
    showButtons();
  }
}

void MainWindow::dilateImage(){
  image->dilate();
  renderImageInLabel();
}

void MainWindow::erodeImage(){
  image->erode();
  renderImageInLabel();
}

void MainWindow::openingImage(){
  image->erode();
  image->dilate();
  renderImageInLabel();
}

void MainWindow::closingImage(){
  image->dilate();
  image->erode();
  renderImageInLabel();
}

void MainWindow::showBorders(){
  image->showBorders();
  renderImageInLabel();
}

void MainWindow::renderImageInLabel(){
  ui->editedImage->setPixmap(QPixmap::fromImage(image->getImage()));
  ui->editedImage->adjustSize();
}

void MainWindow::countObjects(){
  image->segmentation();
  ui->number->setText(QString::number(image->getObjectsNumber()));
}

void MainWindow::createActions(){
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
  connect(ui->dilate,SIGNAL(released()),this,SLOT(dilateImage()));
  connect(ui->erode,SIGNAL(released()),this,SLOT(erodeImage()));
  connect(ui->opening,SIGNAL(released()),this,SLOT(openingImage()));
  connect(ui->closing,SIGNAL(released()),this,SLOT(closingImage()));
  connect(ui->countButton,SIGNAL(released()),this,SLOT(countObjects()));
  connect(ui->border,SIGNAL(released()),this,SLOT(showBorders()));
}
