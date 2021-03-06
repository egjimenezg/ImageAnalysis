#include "image.h"
#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <stdlib.h>

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

void Image::readCodesFile(string path){

  ifstream codesFile(path.c_str());

  if(codesFile.is_open()){

    setFrequenciesFromFile(&(this)->frequenciesRed,&codesFile,"GREEN");
    setFrequenciesFromFile(&(this)->frequenciesGreen,&codesFile,"BLUE");
    setFrequenciesFromFile(&(this)->frequenciesBlue,&codesFile,"\n");

    codesFile.close();
  }
  else
    cout << "Unable to read file" << endl;

}
void Image::deleteColorMatrices(){
  long x;

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
}

void Image::initializeColorMatrices(){
  long x;

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
}

void Image::createImageFromFile(string pathToImageFile){
  ifstream imageFile(pathToImageFile.c_str());
  deleteColorMatrices();
  string line;

  if(imageFile.is_open()){
    getline(imageFile,line);
    H = atol(line.c_str());
    getline(imageFile,line);
    W = atol(line.c_str());
    initializeColorMatrices();
    fillMatrixWithFile(&frequenciesRed,&imageFile,red);
    getline(imageFile,line);
    fillMatrixWithFile(&frequenciesGreen,&imageFile,green);
    getline(imageFile,line);
    fillMatrixWithFile(&frequenciesBlue,&imageFile,blue);
  }
  imageFile.close();
}

void Image::fillMatrixWithFile(map<string,int>* frequencies,ifstream* imageFile,int** channelMatrix){
  string line;
  string substring = "";
  long x,y=0,i;

  for(x=0;x<H;x++){
    getline(*imageFile,line);
    for(i=0;i<line.size();i++){
      substring += line.at(i);
      if((*frequencies).find(substring) != (*frequencies).end()){
         channelMatrix[x][y] = (*frequencies)[substring];
         substring = "";
         y++;
      }
    }
    y = 0;
  }
}

void Image::setFrequenciesFromFile(map<string,int>* frequencies,ifstream* codesFile,string channel){
  string line,key,value;
  string delimiter = ":";
  size_t indexDelimiter;

  while(line != channel && getline(*codesFile,line)){
    indexDelimiter = line.find(delimiter);

    if(indexDelimiter!=string::npos){
      key = line.substr(0,indexDelimiter);
      value = line.substr(indexDelimiter+1);
      (*frequencies)[value] = atoi(key.c_str());
    }
  }
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

int** Image::getRed(){
  return red;
}

int** Image::getGreen(){
  return green;
}

int** Image::getBlue(){
  return blue;
}
