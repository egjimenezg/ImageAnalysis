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
    map<string,int> frequenciesRed;
    map<string,int> frequenciesGreen;
    map<string,int> frequenciesBlue;
    void setFrequenciesFromFile(map<string,int>*,ifstream*,string);
    void deleteColorMatrices();
    void initializeColorMatrices();
    void fillMatrixWithFile(map<string,int>*,ifstream*,int**);

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
    int** getRed();
    int** getGreen();
    int** getBlue();
    void readCodesFile(string);
    void createImageFromFile(string);


};
#endif // IMAGE_H

