#include <QtWidgets>

#include "imagewindow.h"

ImageWindow::ImageWindow(){
  imageLabel = new QLabel;
  imageLabel->setBackgroundRole(QPalette::Dark);
  imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  imageLabel->setMaximumWidth(400);
  imageLabel->setMaximumHeight(400);
  imageLabel->setScaledContents(true);  

  scrollArea = new QScrollArea;
  scrollArea->setBackgroundRole(QPalette::Dark);
  scrollArea->setWidget(imageLabel);
  setCentralWidget(scrollArea);

  changeColor = new QPushButton("&Red",this);
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

  connect(changeColor,SIGNAL(released()), this, SLOT(convertToRed()));

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


void ImageWindow::convertToRed(){

  QRgb value;

  for(int y=0;y<image->height();y++){
    for(int x=0;x<image->width();x++){
        QColor clrCurrent( image->pixel(x,y));
        value = qRgb(clrCurrent.red(),0,0);
        image->setPixel(x,y,value);
    }
  }

  imageLabel->setPixmap(QPixmap::fromImage(*image));
  imageLabel->adjustSize();
}
