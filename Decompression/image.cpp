#include "image.h"
#include <QMainWindow>s
#include <iostream>
#include <fstream>

using namespace std;

Image::Image(){
  H = 0;
  W = 0;
}

Image::~Image(){

  for(int x=0;x<H;x++){
    delete red[x];
    delete green[x];
    delete blue[x];
    delete auxMatrix[x];
  }

  delete red;
  delete green;
  delete blue;
  delete auxMatrix;

}

void Image::setImageFrequenciesRed(){
  int x,y;
  frequencies.clear();

  for(x=0;x<H;x++){
    for(y=0;y<W;y++){
      frequencies[red[x][y]]++;
    }
  }

}

void Image::setImageFrequenciesGreen(){
  int x,y;
  frequencies.clear();

  for(x=0;x<H;x++){
    for(y=0;y<W;y++){
      frequencies[green[x][y]]++;
    }
  }
}

void Image::setImageFrequenciesBlue(){
  int x,y;
  frequencies.clear();

  for(x=0;x<H;x++){
    for(y=0;y<W;y++){
      frequencies[blue[x][y]]++;
    }
  }
}

void Image::setImage(QImage *image){
  long x,y;

  if(H > 0){
    for(x=0;x<H;x++){
      delete red[x];
      delete green[x];
      delete blue[x];
      delete auxMatrix[x];
    }

    delete red;
    delete green;
    delete blue;
    delete auxMatrix;
  }

  H = image->height();
  W = image->width();

  red = new int*[H];
  green = new int*[H];
  blue = new int*[H];
  auxMatrix = new int*[H];

  for(x=0;x<H;x++){
    red[x] = new int[W];
    green[x] = new int[W];
    blue[x] = new int[W];
    auxMatrix[x] = new int[W];
  }

  for(x=0;x<H;x++){
    for(y=0;y<W;y++){
      QColor color(image->pixel(y,x));

      red[x][y] = color.red();
      green[x][y] = color.green();
      blue[x][y] = color.blue();
    }
  }

}


QImage Image::getImage(){
  long x,y;
  QImage qImage(W,H,QImage::Format_RGB32);
  QRgb value;

  for(x=0;x<H;x++){
    for(y=0;y<W;y++){
      value = qRgb(red[x][y],green[x][y],blue[x][y]);
      qImage.setPixel(y,x,value);
    }
  }

  return qImage;
}

long Image::getH(){
  return H;
}

long Image::getW(){
  return W;
}

int Image::getRedValue(int x,int y){
  return red[x][y];
}

int Image::getGreenValue(int x,int y){
  return green[x][y];
}

int Image::getBlueValue(int x,int y){
  return blue[x][y];
}

