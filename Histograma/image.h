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
    long H;
    long W;
    /*Array with the greater values of each channel*/
    int* maxValues;
    /*Array with the lower values of each channel*/
    int* minValues;

  public:
    Image();
    ~Image();
    void setImage(QImage*);
    QImage getImage();
    void initializeMinAndMaxValues();
    long getH();
    long getW();
    int* getMaxVaules();
    int* getMinValues();
    void setChannel(int**,int);
    int** getRed();
    int** getGreen();    
    int** getBlue();    
    int getChannelValue(int,int,int);
    int getRedValue(int,int);
    int getGreenValue(int,int);
    int getBlueValue(int,int);
    QImage getRGBImage(char);

};

#endif // IMAGE_H
