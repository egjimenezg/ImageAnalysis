#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#include "qcustomplot.h"
#include "image.h"

class Histogram{
  private:
     QVector<double> x;
     QVector<double> frequencies;
     void initializeVectorValues();
     void setFrequencies(int**,int,int);


  public:
    Histogram(QWidget* parent,int,int);
    ~Histogram();
    QCustomPlot* qcustomPlot;
    QCPBars* bars2;
    void createHistogramForChanelOfTheImage(Image*,char);
    void expandHistogram(int,int,Image*,Image*,int);
    void reduceHistogram(int,int,Image*,Image*,int);
};

#endif // HISTOGRAM_H
