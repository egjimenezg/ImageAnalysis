#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
ui(new Ui::MainWindow){
  ui->setupUi(this);
  init();
  bindEvents();
}

MainWindow::~MainWindow(){
  delete ui;
}

void MainWindow::init(){
  image = new Image();
  ui->openImage->setVisible(false);
  ui->image->setVisible(false);
}

void MainWindow::openKeys(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imágen"),QDir::currentPath());
  if(!fileName.isEmpty()){
    image->readCodesFile(fileName.toStdString());
    ui->openImage->setVisible(true);
    ui->image->setVisible(true);
  }
}

void MainWindow::openImageFile(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imágen"),QDir::currentPath());
  if(!fileName.isEmpty())
    image->createImageFromFile(fileName.toStdString());

  ui->image->setPixmap(QPixmap::fromImage(image->getImage()));
  ui->image->adjustSize();
}

void MainWindow::bindEvents(){
  connect(ui->codesButton,SIGNAL(released()),this,SLOT(openKeys()));
  connect(ui->openImage,SIGNAL(released()),this,SLOT(openImageFile()));
}
