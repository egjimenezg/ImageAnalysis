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

  createActions();
  createMenuBar();

  setWindowTitle(tr("Image Analysis Application"));
  resize(800,600);
}

ImageWindow::~ImageWindow(){
}

void ImageWindow::createActions(){
  openAction = new QAction(tr("Abrir"),this);
  openAction->setShortcut(tr("Ctrl+A"));
  connect(openAction, SIGNAL(triggered()), this, SLOT(openImage()));
}

void ImageWindow::createMenuBar(){
  fileMenu = new QMenu(tr("&Archivo"),this);
  fileMenu->addAction(openAction);
  menuBar()->addMenu(fileMenu);
}

void ImageWindow::openImage(){
   QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir Archivo"),QDir::currentPath());

   if(!fileName.isEmpty()){
     QImage image(fileName);
     if(image.isNull()){
         QMessageBox::information(this,tr("Image"),tr("Cannot load %1.").arg(fileName));
         return;
     }
     imageLabel->setPixmap(QPixmap::fromImage(image));
     imageLabel->adjustSize();
   }

}
