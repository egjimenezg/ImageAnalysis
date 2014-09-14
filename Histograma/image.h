#ifndef IMAGE_H
#define IMAGE_H
#include <QMainWindow>
#include <algorithm>

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
    void getImage(QImage*);
    void initializeMinAndMaxValues();


};

#endif // IMAGE_H