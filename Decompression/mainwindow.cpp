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
}

void MainWindow::openKeys(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imágen"),QDir::currentPath());
  image->readCodesFile(fileName.toStdString());
}

void MainWindow::bindEvents(){
  connect(ui->codesButton,SIGNAL(released()),this,SLOT(openKeys()));
}
