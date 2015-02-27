#ifndef IMAGE_H
#define IMAGE_H
#include <QMainWindow>
#include <map>

using namespace std;

class Image{

  private:
    int **red;
    int **green;
    int **blue;
    int **auxMatrix;
    long H;
    long W;
    static const int testImage[8][8];
    map<int,int> frequencies;
   
  public:
    Image();
    ~Image();
    //void setImage(QImage*);
    void setImage();
    QImage getImage();
    long getH();
    long getW();
    int getRedValue(int,int);
    int getGreenValue(int,int);
    int getBlueValue(int,int);
    void setImageFrequencies();
    void initCompression();
};
#endif // IMAGE_H
