#include "image.h"
#include <QMainWindow>
#include <iostream>
#define MASK_SIZE 9

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

  H=10;
  W=10;

  red = new int*[H];
  green = new int*[H];
  blue = new int*[H];

  for(y=0;y<H;y++){
    red[y] = new int[W];
    green[y] = new int[W];
    blue[y] = new int[W];
  }

  initializeMinAndMaxValues();

  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
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

QImage Image::getImage(){
  long x,y;
  QImage qimage(W,H,QImage::Format_RGB32);
  QRgb value;

  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
      value = qRgb(red[y][x],green[y][x],blue[y][x]);
      qimage.setPixel(x,y,value);
    }
  }

  return qimage;
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

int Image::getChannelValue(int y,int x,int channel){
  switch(channel){
    case 0:
      return red[y][x];
    case 1:
      return green[y][x];
    case 2:
      return blue[y][x];
    default:
      return red[y][x];
  }
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

int** Image::getRed(){
  return red;
}

void Image::setChannel(int** matrix,int channel){
  long x,y;

  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
      switch(channel){
        case 0:
          red[y][x] = matrix[y][x];
        break;
        case 1:
          green[y][x] = matrix[y][x];
        break;
        case 2:
          blue[y][x] = matrix[y][x];
        break;
      }
    }
  }

}

int** Image::getGreen(){
  return green;
}

int** Image::getBlue(){
  return blue;
}

int* Image::getMaxVaules(){
  return maxValues;
}

int* Image::getMinValues(){
  return minValues;
}
