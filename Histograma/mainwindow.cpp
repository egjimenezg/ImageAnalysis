#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtWidgets>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
  ui->setupUi(this);
  /*initializePlot();*/
  createActions();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::openImage(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imagen"),QDir::currentPath());
  if(!fileName.isEmpty()){
    QImage* image = new QImage(fileName);
    if(image->isNull()){
      QMessageBox::information(this,tr("Image"),tr("El archivo %1 no es una imagen").arg(fileName));
      return;
    }

    ui->imagew->setPixmap(QPixmap::fromImage(*image));
    ui->imagew->adjustSize();

  }
}


void MainWindow::initializePlot(){
  qcustomplot = new QCustomPlot(this);
  qcustomplot->setGeometry(600,20,300,300);
  qcustomplot->xAxis->setLabel("x");
  qcustomplot->yAxis->setLabel("y");

  bars2 = new QCPBars(qcustomplot->xAxis, qcustomplot->yAxis);
  bars2->setWidth(2);
  bars2->setPen(Qt::NoPen);
  bars2->setBrush(QColor(0, 0, 255, 255));
  qcustomplot->addPlottable(bars2);
}

void MainWindow::createHistogram(int option){

  initializeVectorValues();
  /*
  for(int i=0;i<image->height();i++){
    for(int j=0;j<image->width();j++){
      color = new QColor(image->pixel(j,i));
      switch(option){
        case 0:
          y[color->red()]++;
        break;
        case 1:
          y[color->green()]++;
        break;
        case 2:
            y[color->blue()]++;
        break;
      }
    }
  }
*/
  bars2->setData(x, y);  
  qcustomplot->rescaleAxes();
  qcustomplot->replot();
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

void MainWindow::initializeVectorValues(){
  x = QVector<double>(256);
  y = QVector<double>(256);

  for(int i=0;i<256;i++){
    x[i] = i;
    y[i] = 0;
  }
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
