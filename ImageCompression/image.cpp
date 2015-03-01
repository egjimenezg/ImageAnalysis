#include "image.h"
#include  "huffmantree.h"
#include <QMainWindow>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int Image::testImage[8][8] = {{15,20,15,15,20,25,15,20},
                                    {30,25,25,30,20,20,30,30},
                                    {35,30,35,40,40,30,25,30},
                                    {40,35,40,50,50,40,35,35},
                                    {40,40,50,45,45,55,50,40},
                                    {45,50,55,50,55,60,55,45},
                                    {40,45,40,45,50,60,45,40},
                                    {30,35,25,25,30,35,30,20}};


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

void Image::setImageFrequencies(){
  int x,y; 
   
  for(x=0;x<H;x++){
    for(y=0;y<W;y++){
      frequencies[red[x][y]]++;
    }
  }

}

void Image::setImage(QImage *image){
//void Image::setImage(){
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
  /*H = HEIGHT;
  W = WIDTH;*/

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
      /*red[x][y] = testImage[x][y];
      green[x][y] = testImage[x][y];
      blue[x][y] = testImage[x][y];*/
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

void Image::initCompression(){
  HuffmanTree *tree = new HuffmanTree;
  string codeword = "";
  for(map<int,long>::iterator it=frequencies.begin();it!= frequencies.end();++it){
    Node *node = new Node(it->first,it->second);
    tree->insertIntoQueue(node);
  }

  for(unsigned i=0;i<frequencies.size()-1;i++){
    Node* node = new Node();
    node->setLeft(tree->getMin());
    node->setRight(tree->getMin());
    node->setFrequency(node->getRight()->getFrequency()+node->getLeft()->getFrequency());
    tree->insertIntoQueue(node);
  }
  tree->setRoot(tree->getMin());
  tree->preOrden(tree->getRoot(),codeword);
  map<int,string> codewords = tree->getCodewords();
  ofstream file("/Users/gamaliel/Desktop/keys.txt");

  for(map<int,string>::iterator it=codewords.begin();it!=codewords.end();it++){
    file << (*it).first << ":"<< (*it).second << "\n";
  }
  file.close();

}

