#ifndef IMAGE_H
#define IMAGE_H
#include <QMainWindow>
#include <map>
#include <string>

using namespace std;

class Image{

  private:
    int **red;
    int **green;
    int **blue;
    int **auxMatrix;
    long H;
    long W;
    map<int,long> frequencies;


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
    void readCodesFile(string path);
    void setImageFrequenciesRed();
    void setImageFrequenciesGreen();
    void setImageFrequenciesBlue();

};
#endif // IMAGE_H
