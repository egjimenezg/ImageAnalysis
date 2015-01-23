#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::openImage(){
  QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imagen"),QDir::currentPath());
}

void MainWindow::createActions(){
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
}
