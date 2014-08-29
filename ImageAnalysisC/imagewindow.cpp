#include <QtWidgets>

#include "imagewindow.h"

ImageWindow::ImageWindow(){
  imageLabel = new QLabel;
  imageLabel->setBackgroundRole(QPalette::Dark);
  imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  imageLabel->setGeometry(QRect(QPoint(0,0),QSize(400,400)));
  imageLabel->setMaximumWidth(400);
  imageLabel->setMaximumHeight(400);
  imageLabel->setScaledContents(true);
  imageLabel->setParent(this);

  imageResult = new QLabel;
  imageResult->setBackgroundRole(QPalette::Dark);
  imageResult->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  imageResult->setGeometry(QRect(QPoint(410,0),QSize(400,400)));
  imageResult->setMaximumWidth(400);
  imageResult->setMaximumHeight(400);
  imageResult->setScaledContents(true);
  imageResult->setParent(this);


  changeColor = new QPushButton("&Práctica 1",this);
  changeColor->setGeometry(QRect(QPoint(10,400),QSize(100,50)));

  createActions();
  createMenuBar();

  setWindowTitle(tr("Image Analysis Application"));
  resize(800,600);
}

ImageWindow::~ImageWindow(){}

void ImageWindow::createActions(){
  openAction = new QAction(tr("Abrir"),this);
  openAction->setShortcut(tr("Ctrl+A"));
  connect(openAction, SIGNAL(triggered()), this, SLOT(openImage()));
  connect(changeColor,SIGNAL(released()), this, SLOT(practice1()));

}

void ImageWindow::createMenuBar(){
  fileMenu = new QMenu(tr("&Archivo"),this);
  fileMenu->addAction(openAction);
  menuBar()->addMenu(fileMenu);
}

void ImageWindow::openImage(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir Archivo"),QDir::currentPath());

  if(!fileName.isEmpty()){
    image = new QImage(fileName);
    if(image->isNull()){
      QMessageBox::information(this,tr("Image"),tr("Cannot load %1.").arg(fileName));
      return;
    }
    imageLabel->setPixmap(QPixmap::fromImage(*image));
    imageLabel->adjustSize();
  }

}

void ImageWindow::practice1(){
  QRgb value;
  QImage* img = new QImage(image->width()*2,image->height()*2,QImage::Format_RGB32);

  for(int y=0;y<img->height();y++){
    for(int x=0;x<img->width();x++){
      if(x<image->width() && y <image->height()){
        QColor currentColor(image->pixel(x,y));
        value = qRgb(currentColor.red(),currentColor.green(),currentColor.blue());
        img->setPixel(x,y,value);
      }
      else if(x>=image->width() && y<image->height()){
        QColor currentColor(image->pixel(x-image->width(),y));
        value = qRgb(currentColor.red(),0,0);
        img->setPixel(x,y,value);
      }
      else if(x<image->width() && y>image->height()){
        QColor currentColor(image->pixel(x,y-image->height()));
        value = qRgb(0,currentColor.green(),0);
        img->setPixel(x,y,value);
      }
      else if(x>image->width() && y>image->height()){
        QColor currentColor(image->pixel(x-image->width(),y-image->height()));
        value = qRgb(0,0,currentColor.blue());
        img->setPixel(x,y,value);
      }
    }
  }

  imageResult->setPixmap(QPixmap::fromImage(*img));
  imageResult->adjustSize();
}

void ImageWindow::convertToRed(){

  QRgb value;

  for(int y=0;y<image->height();y++){
    for(int x=0;x<image->width();x++){
        QColor clrCurrent( image->pixel(x,y));
        value = qRgb(clrCurrent.red(),0,0);
        image->setPixel(x,y,value);
    }
  }

  imageResult->setPixmap(QPixmap::fromImage(*image));
  imageResult->adjustSize();
}
