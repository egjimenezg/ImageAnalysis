#include "image.h"
#include <QMainWindow>
#include <iostream>

using namespace std;

Image::Image(){
  H = 0;
  W = 0;
}

Image::~Image(){

  for(int y=0;y<H;y++){
    delete red[y];
    delete green[y];
    delete blue[y];
    delete auxMatrix[y];
  }

  delete red;
  delete green;
  delete blue;
  delete auxMatrix;

}

void Image::setImage(QImage* image){
  long x,y;

  if(H>0){
    for(y=0;y<H;y++){
      delete red[y];
      delete green[y];
      delete blue[y];
      delete auxMatrix[y];
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
  
  for(y=0;y<H;y++){
    red[y] = new int[W];
    green[y] = new int[W]; 
    blue[y] = new int[W];
    auxMatrix[y] = new int[W];
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

void Image::imageToBinary(){
  long x,y;

  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
      if(green[y][x] > 128){
        red[y][x] = 255;
        green[y][x] = 255;
        blue[y][x] = 255;
      }
      else{
        red[y][x] = 0;
        green[y][x] = 0;
        blue[y][x] = 0;
      }
    }
  }

}

void Image::dilate(){
  int x,y,s,t;
  int e[3][3] = {{0,1,0},
                 {1,1,1},
                 {0,1,0}};

  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
      auxMatrix[y][x] = 255;
      for(s=-1;s<=1;s++){
        for(t=-1;t<=1;t++){
          if(y+s >= 0 && y+s < H && x+t >= 0 && x+t < W){
            if(e[s+1][t+1] == 1 && green[y+s][x+t] == 0){
              auxMatrix[y][x] = 0;
              break;
            }
          }
        }
        if(auxMatrix[y][x] == 0)
          break;
      }
    }
  }

  setRGBMatrices(auxMatrix);

}

void Image::erode(){
  int x,y,s,t;
  int e[3][3] = {{0,1,0},
                 {1,1,1},
                 {0,1,0}};

  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
      auxMatrix[y][x] = 0;
      for(s=-1;s<=1;s++){
        for(t=-1;t<=1;t++){
          if(y+s >= 0 && y+s < H && x+t >= 0 && x+t < W){
            if(e[s+1][t+1] == 1 && green[y+s][x+t] == 255){
              auxMatrix[y][x]=255;
            }
          }
        }
        if(auxMatrix[y][x] == 255)
          break;
      }
    }
  }

  setRGBMatrices(auxMatrix);

}

void Image::setRGBMatrices(int** auxMatrix){
  long x,y;

  for(y=0;y<H;y++){
    for(x=0;x<W;x++){
      red[y][x] = auxMatrix[y][x];
      green[y][x] = auxMatrix[y][x];
      blue[y][x] = auxMatrix[y][x];
    }
  }
}

