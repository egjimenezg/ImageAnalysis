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
};

#endif // HISTOGRAM_H
