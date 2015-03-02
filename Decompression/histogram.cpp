#include "histogram.h"
#include <iostream>

using namespace std;

Histogram::Histogram(QWidget* parent,int x,int y){

  qcustomPlot = new QCustomPlot(parent);
  qcustomPlot->setGeometry(x,y,300,300);
  qcustomPlot->xAxis->setLabel("x");
  qcustomPlot->yAxis->setLabel("y");
  qcustomPlot->xAxis->setBasePen(QPen(Qt::white, 1));
  qcustomPlot->yAxis->setBasePen(QPen(Qt::white, 1));

  qcustomPlot->xAxis->setTickPen(QPen(Qt::white, 1));
  qcustomPlot->yAxis->setTickPen(QPen(Qt::white, 1));
  qcustomPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
  qcustomPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
  qcustomPlot->xAxis->setTickLabelColor(Qt::white);
  qcustomPlot->yAxis->setTickLabelColor(Qt::white);

  qcustomPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
  qcustomPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
  qcustomPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
  qcustomPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
  qcustomPlot->xAxis->grid()->setSubGridVisible(true);
  qcustomPlot->yAxis->grid()->setSubGridVisible(true);
  qcustomPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
  qcustomPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
  qcustomPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
  qcustomPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

  QLinearGradient plotGradient;
  plotGradient.setStart(0, 0);
  plotGradient.setFinalStop(0, 350);
  plotGradient.setColorAt(0, QColor(80, 80, 80));
  plotGradient.setColorAt(1, QColor(50, 50, 50));
  qcustomPlot->setBackground(plotGradient);

  QLinearGradient axisRectGradient;
  axisRectGradient.setStart(0, 0);
  axisRectGradient.setFinalStop(0, 350);
  axisRectGradient.setColorAt(0, QColor(80, 80, 80));
  axisRectGradient.setColorAt(1, QColor(30, 30, 30));

  qcustomPlot->axisRect()->setBackground(axisRectGradient);
  qcustomPlot->setVisible(true);

  this->x = QVector<double>(256);
  this->frequencies = QVector<double>(256);

  initializeVectorValues();

}

Histogram::~Histogram(){}

void Histogram::initializeVectorValues(){

  for(int i=0;i<256;i++){
    x[i] = i;
    frequencies[i] = 0;
  }
}

void Histogram::createHistogramForChanelOfTheImage(Image *image,char channel){
  switch(channel){
    case 'R':
      setFrequencies(image->getRed(),image->getH(),image->getW());
    break;
    case 'G':
      setFrequencies(image->getGreen(),image->getH(),image->getW());
    break;
    case 'B':
      setFrequencies(image->getBlue(),image->getH(),image->getW());
    break;
  }

  bars2 = new QCPBars(qcustomPlot->xAxis, qcustomPlot->yAxis);
  bars2->setWidth(1);
  bars2->setPen(Qt::NoPen);
  bars2->setBrush(QColor(0, 255, 0, 70));
  bars2->setData(x, frequencies);
  qcustomPlot->addPlottable(bars2);
  qcustomPlot->setInteraction(QCP::iRangeDrag,true);
  qcustomPlot->setInteraction(QCP::iRangeZoom,true);
  qcustomPlot->xAxis->setRange(0,255);
  qcustomPlot->yAxis->setRange(0,5000);
  qcustomPlot->replot();

}

void Histogram::setFrequencies(int** matrix,int H,int W){
  long i,j;

  for(i=0;i<H;i++)
    for(j=0;j<W;j++)
      this->frequencies[matrix[i][j]]++;
}
