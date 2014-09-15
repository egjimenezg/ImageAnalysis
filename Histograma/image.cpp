#include "image.h"
#include <QMainWindow>
#include <iostream>

using namespace std;

Image::Image(){  
  H = 0;
  W = 0;
}

Image::~Image(){

  for(int y=0;y<H; y++){
    delete red[y];
    delete green[y];
    delete blue[y];
  }

  delete red;
  delete green;
  delete blue;
  delete maxValues;
  delete minValues;
}

void Image::setImage(QImage* image){
  long x,y;

  if(H>0){
    for(y=0;y<H;y++){
      delete red[y];
      delete green[y];
      delete blue[y];
    }

    delete red;
    delete green;
    delete blue;
    delete maxValues;
    delete minValues;
  }

  H=image->height();
  W=image->width();

  red = new int*[H];
  green = new int*[H];
  blue = new int*[H];

  for(y=0;y<H;y++){
    red[y] = new int[W];
    green[y] = new int[W];
    blue[y] = new int[W];
  }

  initializeMinAndMaxValues();

  for(y=0;y<image->height();y++){
    for(x=0;x<image->width();x++){
      QColor color(image->pixel(x,y));
      maxValues[0] = max(color.red() ,maxValues[0]);
      maxValues[1] = max(color.blue() ,maxValues[1]);
      maxValues[2] = max(color.green() ,maxValues[2]);

      red[y][x] = color.red();
      green[y][x] = color.green();
      blue[y][x] = color.blue();
    }
  }
}

void Image::getImage(QImage *image){
  long x,y;
  QRgb value;
  for(y=0;y<image->height();y++){
    for(x=0;x<image->width();x++){
      value = qRgb(red[y][x],green[y][x],blue[y][x]);
      image->setPixel(x,y,value);
    }
  }
}

void Image::initializeMinAndMaxValues(){
  maxValues = new int[3];
  minValues = new int[3];

  for(int i=0;i<3;i++){
    maxValues[i] = 0;
    minValues[i] = 0;
  }
}

QImage Image::getRGBImage(char option){
  long x,y;
  QImage qimage(W,H,QImage::Format_RGB32);

  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
      switch(option){
        case 'R':
          qimage.setPixel(x,y,qRgb(red[y][x],0,0));
        break;
        case 'G':
          qimage.setPixel(x,y,qRgb(0,green[y][x],0));
        break;
        case 'B':
          qimage.setPixel(x,y,qRgb(0,0,blue[y][x]));
        break;
      }
    }
  }

  return qimage;
}

long Image::getH(){
  return H;
}

long Image::getW(){
  return W;
}

int Image::getRedValue(int y,int x){
  return red[y][x];
}

int Image::getGreenValue(int y,int x){
  return green[y][x];
}

int Image::getBlueValue(int y,int x){
  return blue[y][x];
}
