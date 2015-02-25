#ifndef IMAGE_H
#define IMAGE_H
#include <QMainWindow>
class Image{

  private:
    int **red;
    int **green;
    int **blue;
    int **auxMatrix;
    long H;
    long W;

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
};
#endif // IMAGE_H
