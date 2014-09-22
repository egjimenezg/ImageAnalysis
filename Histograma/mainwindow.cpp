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
  auxImage = new Image();
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
    auxImage->setImage(img);

    ui->imagew->setPixmap(QPixmap::fromImage(*img));
    ui->finalImage->setPixmap(QPixmap::fromImage(*img));

    ui->imagew->adjustSize();
    ui->finalImage->adjustSize();

    setRGBImages(image);
    initializeHistograms();
  }
}

void MainWindow::setRGBImages(Image* img){
  ui->imager->setPixmap(QPixmap::fromImage(img->getRGBImage('R')));
  ui->imager->adjustSize();
  ui->imageg->setPixmap(QPixmap::fromImage(img->getRGBImage('G')));
  ui->imageg->adjustSize();
  ui->imageb->setPixmap(QPixmap::fromImage(img->getRGBImage('B')));
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
   int currentIndex = ui->comboBox->currentIndex();
   int cmax = ui->max->text().toInt();
   int cmin = ui->min->text().toInt();
   histogramas[currentIndex]->expandHistogram(cmax,cmin,image,auxImage,currentIndex);
   ui->finalImage->setPixmap(QPixmap::fromImage(auxImage->getImage()));
   ui->finalImage->adjustSize();
   setRGBImages(auxImage);
}

void MainWindow::reduceHistogram(){
  int currentIndex = ui->comboBox->currentIndex();
  int cmax= ui->max->text().toInt();
  int cmin= ui->min->text().toInt();
  histogramas[currentIndex]->reduceHistogram(cmax,cmin,image,auxImage,currentIndex);
  ui->finalImage->setPixmap(QPixmap::fromImage(auxImage->getImage()));
  ui->finalImage->adjustSize();
  setRGBImages(auxImage);
}

void MainWindow::createActions(){
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
  connect(ui->expandirButton,SIGNAL(released()),this,SLOT(expandHistogram()));
  connect(ui->contraerButton,SIGNAL(released()),this,SLOT(reduceHistogram()));
}

