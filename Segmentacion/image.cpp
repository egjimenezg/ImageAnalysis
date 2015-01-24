#ifndef IMAGE_H
#define IMAGE_H
#include "image.h"
#include <QMainWindow>
#include <iostream>

Image::Image(){
  H = 0;
  W = 0;
}

Image::~Image(){

  for(int y=0;y<H;y++){
    delete red[y];
    delete green[y];
    delete blue[y];
  }

  delete red;
  delete green;
  delete blue;

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
  }

  H = image->height();
  W = image->width();

  red = new int*[H];
  green = new int*[H];
  blue = new int*[H];
  
  for(y=0;y<H;y++){
    red[y] = new int[W];
    green[y] = new int[W]; 
    blue[y] = new int[W];
  }
  
  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
      QColor color(image->pixel(x,y));
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

long Image::getH(){
  return H;
}

long Image::getW(){
  return W;
}

#endif // IMAGE_H
