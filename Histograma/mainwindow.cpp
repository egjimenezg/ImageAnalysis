#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtWidgets>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
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
    QImage* img = new QImage(fileName);
    if(img->isNull()){
      QMessageBox::information(this,tr("Image"),tr("El archivo %1 no es una imagen").arg(fileName));
      return;
    }
    image->setImage(img);
    ui->imagew->setPixmap(QPixmap::fromImage(*img));
    ui->imagew->adjustSize();
    setRGBImages();
    initializeHistograms();
  }
}

void MainWindow::setRGBImages(){
  ui->imager->setPixmap(QPixmap::fromImage(image->getRGBImage('R')));
  ui->imager->adjustSize();
  ui->imageg->setPixmap(QPixmap::fromImage(image->getRGBImage('G')));
  ui->imageg->adjustSize();
  ui->imageb->setPixmap(QPixmap::fromImage(image->getRGBImage('B')));
  ui->imageb->adjustSize();
}

void MainWindow::initializeHistograms(){
  histogramas = new Histogram*[3];
  histogramas[0] = new Histogram(this,280,280);
  histogramas[1] = new Histogram(this,600,280);
  histogramas[2] = new Histogram(this,910,280);

  histogramas[0]->createHistogramForChanelOfTheImage(image,'G');
  histogramas[1]->createHistogramForChanelOfTheImage(image,'R');
  histogramas[2]->createHistogramForChanelOfTheImage(image,'B');
}

void MainWindow::expandHistogram(){
  /*int** matrix = new int*[image->height()];

  QColor* color;

  for(int i=0;i<image->height();i++)
    matrix[i] = new int[image->width()];

  for(int y=0;y<image->height();y++){
    for(int x=0;x<image->width();x++){
      color = new QColor(image->pixel(x,y));
    }
  }*/
}


void MainWindow::createActions(){

  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
  connect(ui->expandirButton,SIGNAL(released()),this,SLOT(expandHistogram()));
  /*
  connect(ui->canalRButton,SIGNAL(released()),&mapper,SLOT(map()));
  connect(ui->canalGButton,SIGNAL(released()),&mapper,SLOT(map()));
  connect(ui->canalBButton,SIGNAL(released()),&mapper,SLOT(map()));

  //connect(ui->contraerButton,SIGNAL(released()),this,SLOT(map()));
  mapper.setMapping(ui->canalRButton,0);
  mapper.setMapping(ui->canalGButton,1);
  mapper.setMapping(ui->canalBButton,2);

  connect(&mapper, SIGNAL(mapped(int)), this, SLOT(createHistogram(int)));
  */
}

void MainWindow::createHistogramsForEachChannel(){

}
