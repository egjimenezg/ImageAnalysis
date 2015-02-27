#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  bindEvents();
  init();
  image->setImage();
  image->setImageFrequencies();
  image->initCompression();
}

MainWindow::~MainWindow(){
  delete ui;
}

void MainWindow::init(){
  image = new Image();
}

void MainWindow::openImage(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imágen"),QDir::currentPath());

  if(!fileName.isEmpty()){
    QImage *img = new QImage(fileName);
    if(img->isNull()){
      QMessageBox::information(this,tr("Image"),tr("El archivo %1 no es una imagen").arg(fileName));
      return;
    }
    /*image->setImage(img);
    ui->originalImage->setPixmap(QPixmap::fromImage(image->getImage()));
    ui->originalImage->adjustSize();*/
  }

}

void MainWindow::bindEvents(){
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
}

