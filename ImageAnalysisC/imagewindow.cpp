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


  practice1Button = new QPushButton("&Práctica 1",this);
  practice1Button->setGeometry(QRect(QPoint(10,400),QSize(100,50)));
  practice2Button = new QPushButton("&Práctica 2",this);
  practice2Button->setGeometry(QRect(QPoint(120,400),QSize(100,50)));
  practice3Button = new QPushButton("&Práctica 3",this);
  practice3Button->setGeometry(QRect(QPoint(230,400),QSize(100,50)));
  practice4Button = new QPushButton("&Práctica 4",this);
  practice4Button->setGeometry(QRect(QPoint(340,400),QSize(100,50)));
  practice5Button = new QPushButton("&Práctica 5",this);
  practice5Button->setGeometry(QRect(QPoint(450,400),QSize(100,50)));

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
  connect(practice1Button,SIGNAL(released()), this, SLOT(practice1()));
  connect(practice2Button,SIGNAL(released()), this, SLOT(practice2()));
  connect(practice3Button,SIGNAL(released()), this, SLOT(practice3()));
  connect(practice4Button,SIGNAL(released()), this, SLOT(practice4()));
  connect(practice5Button,SIGNAL(released()), this, SLOT(practice5()));

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
      else if(x<image->width() && y>=image->height()){
        QColor currentColor(image->pixel(x,y-image->height()));
        value = qRgb(0,currentColor.green(),0);
        img->setPixel(x,y,value);
      }
      else if(x>=image->width() && y>=image->height()){
        QColor currentColor(image->pixel(x-image->width(),y-image->height()));
        value = qRgb(0,0,currentColor.blue());
        img->setPixel(x,y,value);
      }
    }
  }

  imageResult->setPixmap(QPixmap::fromImage(*img));
  imageResult->adjustSize();
}

void ImageWindow::practice2(){
  QRgb value;
  QImage* img = new QImage(image->width(),image->height()*4,QImage::Format_RGB32);

  for(int y=0;y<img->height();y++){
    for(int x=0;x<img->width();x++){
      if(y<image->height()){
        QColor currentColor(image->pixel(x,y));
        value = qRgb(currentColor.red(),currentColor.green(),currentColor.blue());
        img->setPixel(x,y,value);
      }
      else if(y<image->height()*2){
        QColor currentColor(image->pixel(x,y-image->height()));
        value = qRgb(currentColor.red(),0,0);
        img->setPixel(x,y,value);
      }
      else if(y<image->height()*3){
        QColor currentColor(image->pixel(x,y-(image->height()*2)));
        value = qRgb(0,currentColor.green(),0);
        img->setPixel(x,y,value);
      }
      else{
        QColor currentColor(image->pixel(x,y-image->height()*3));
        value = qRgb(0,0,currentColor.blue());
        img->setPixel(x,y,value);
      }
    }
  }

  imageResult->setPixmap(QPixmap::fromImage(*img));
  imageResult->adjustSize();
}

void ImageWindow::practice3(){
  QRgb value;
  QImage* img = new QImage(image->width(),image->height(),QImage::Format_RGB32);

  for(int y=0;y<img->height();y++){
    for(int x=0;x<img->width();x++){
      QColor currentColor(image->pixel(x,y));
      if(x<img->width()/3)
        value = qRgb(currentColor.red(),0,0);
      else if(x<(img->width()/3)*2)
        value = qRgb(0,currentColor.green(),0);
      else
        value = qRgb(0,0,currentColor.blue());

      img->setPixel(x,y,value);
    }
  }

  imageResult->setPixmap(QPixmap::fromImage(*img));
  imageResult->adjustSize();
}

void ImageWindow::practice4(){
  QRgb value;
  QImage* img = new QImage(image->width(),image->height(),QImage::Format_RGB32);

  for(int y=0;y<img->height();y++){
    for(int x=0;x<img->width();x++){
      QColor currentColor(image->pixel(x,y));
      if(y<img->height()/3)
        value = qRgb(currentColor.red(),0,0);
      else if(y<(img->height()/3)*2)
        value = qRgb(0,currentColor.green(),0);
      else
        value = qRgb(0,0,currentColor.blue());

      img->setPixel(x,y,value);
    }
  }

  imageResult->setPixmap(QPixmap::fromImage(*img));
  imageResult->adjustSize();
}

void ImageWindow::practice5(){
  QRgb value;
  QImage* img = new QImage(image->width(),image->height(),QImage::Format_RGB32);
  QColor* currentColor;

  for(int y=0;y<img->height();y++){
    for(int x=0;x<img->width();x++){
      currentColor = new QColor(image->pixel(x,y));
      if((x<img->width()/3 || x>(img->width()/3)*2) && (y<image->height()/3 || y>(image->height()/3)*2))
        value = qRgb(currentColor->red(),0,0);
      else
        value = qRgb(0,0,currentColor->blue());

      img->setPixel(x,y,value);
    }
  }

  imageResult->setPixmap(QPixmap::fromImage(*img));
  imageResult->adjustSize();
}
