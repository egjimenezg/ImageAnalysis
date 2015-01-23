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

  red = new int*[H];
  green = new int*[H];
  blue = new int*[H];
  
  for(y=0;y<H;y++){
    red[y] = new int[W];
    green[y] = new int[W]; 
    blue[y] = new int[W];
  }
}
