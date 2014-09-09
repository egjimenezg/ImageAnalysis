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

  initializePlot();
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
    ui->canalRButton->setVisible(true);
    ui->canalGButton->setVisible(true);
    ui->canalBButton->setVisible(true);
  }
}

void MainWindow::initializePlot(){
  qcustomplot = new QCustomPlot(this);
  qcustomplot->setGeometry(600,20,400,600);
  qcustomplot->xAxis->setLabel("x");
  qcustomplot->yAxis->setLabel("y");
  qcustomplot->xAxis->setRange(0, 300);
  qcustomplot->yAxis->setRange(0, 100000);

  bars2 = new QCPBars(qcustomplot->xAxis, qcustomplot->yAxis);
  bars2->setWidth(2);
  bars2->setPen(Qt::NoPen);
  bars2->setBrush(QColor(0, 0, 255, 255));

  qcustomplot->addPlottable(bars2);
}

void MainWindow::createHistograma(int option){
  QColor* color;  
  initializeVectorValues();

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


  bars2->setData(x, y);
  qcustomplot->replot();
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
  ui->canalRButton->setVisible(false);
  ui->canalGButton->setVisible(false);
  ui->canalBButton->setVisible(false);

  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));

  connect(ui->canalRButton,SIGNAL(released()),&mapper,SLOT(map()));
  connect(ui->canalGButton,SIGNAL(released()),&mapper,SLOT(map()));
  connect(ui->canalBButton,SIGNAL(released()),&mapper,SLOT(map()));
  mapper.setMapping(ui->canalRButton,0);
  mapper.setMapping(ui->canalGButton,1);
  mapper.setMapping(ui->canalBButton,2);
  connect(&mapper, SIGNAL(mapped(int)), this, SLOT(createHistograma(int)));
}



