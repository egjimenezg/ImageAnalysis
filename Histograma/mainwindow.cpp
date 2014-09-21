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
   QImage qimage(image->getW(),image->getH(),QImage::Format_RGB32);
   if(channel=="Red")
     histogramas[0]->expandHistogram(ui->max->text().toInt(),
                                     ui->min->text().toInt(),
                                     image,ui->comboBox->currentText());
   else if(channel=="Green")
     histogramas[1]->expandHistogram(ui->max->text().toInt(),
                                    ui->min->text().toInt(),
                                    image,ui->comboBox->currentText());
   else
     histogramas[2]->expandHistogram(ui->max->text().toInt(),
                                      ui->min->text().toInt(),
                                      image,ui->comboBox->currentText());


   image->getImage(&qimage);
   ui->imagew->setPixmap(QPixmap::fromImage(qimage));
}

void MainWindow::reduceHistogram(){
  QString channel = ui->comboBox->currentText();
  QImage qimage(image->getW(),image->getH(),QImage::Format_RGB32);

  if(channel=="Red")
    histogramas[0]->reduceHistogram(ui->max->text().toInt(),
                                    ui->min->text().toInt(),
                                    image,ui->comboBox->currentText());
  else if(channel=="Green")
    histogramas[1]->reduceHistogram(ui->max->text().toInt(),
                                    ui->min->text().toInt(),
                                    image,ui->comboBox->currentText());
  else
    histogramas[2]->reduceHistogram(ui->max->text().toInt(),
                                    ui->min->text().toInt(),
                                    image,ui->comboBox->currentText());
  image->getImage(&qimage);
  ui->imagew->setPixmap(QPixmap::fromImage(qimage));
}

void MainWindow::createActions(){
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
  connect(ui->expandirButton,SIGNAL(released()),this,SLOT(expandHistogram()));
  connect(ui->contraerButton,SIGNAL(released()),this,SLOT(reduceHistogram()));
}

