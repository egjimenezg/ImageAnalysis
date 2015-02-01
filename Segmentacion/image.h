#ifndef IMAGE_H
#define IMAGE_H
#include <QMainWindow>
#include <algorithm>
#include <math.h>
using namespace std;

class Image{
  
  private:
    int **red;
    int **green;
    int **blue;
    int **auxMatrix;
    long H;
    long W;   
    void setRGBMatrices(int**);
    static const long dy[4];
    static const long dx[4];
    vector<long> tags;
    void depth_first_search(long,long,long);

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
    int getObjectsNumber();
    void imageToBinary();
    void dilate();
    void erode();
    void segmentation();

};

#endif // IMAGE_H
