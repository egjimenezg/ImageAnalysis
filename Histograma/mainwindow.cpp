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
   QString channel = ui->comboBox->currentText();   
   int cmax = ui->max->text().toInt();
   int cmin = ui->min->text().toInt();
   histogramas[ui->comboBox->currentIndex()]->expandHistogram(cmax,cmin,image,channel);
   ui->imagew->setPixmap(QPixmap::fromImage(image->getImage()));
}

void MainWindow::reduceHistogram(){
  QString channel = ui->comboBox->currentText();
  int cmax= ui->max->text().toInt();
  int cmin= ui->max->text().toInt();
  histogramas[ui->comboBox->currentIndex()]->reduceHistogram(cmax,cmin,image,channel);
  ui->imagew->setPixmap(QPixmap::fromImage(image->getImage()));
}

void MainWindow::createActions(){
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
  connect(ui->expandirButton,SIGNAL(released()),this,SLOT(expandHistogram()));
  connect(ui->contraerButton,SIGNAL(released()),this,SLOT(reduceHistogram()));
}

