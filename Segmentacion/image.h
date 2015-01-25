#ifndef IMAGE_H
#define IMAGE_H
#include <QMainWindow>
#include <algorithm>
#include <math.h>

class Image{
  
  private:
    int **red;
    int **green;
    int **blue;
    int **auxMatrix;
    long H;
    long W;
    void setRGBMatrices(int**);

  public:
    Image();
    ~Image();
    void setImage(QImage*);
    QImage getImage();
    long getH();
    long getW();
    int getRedValue(int,int);
    int getGreenValue(int,int);
    int getBlueValue(int,int);
    void imageToBinary();
    void dilate();
    void erode();
};

#endif // IMAGE_H
