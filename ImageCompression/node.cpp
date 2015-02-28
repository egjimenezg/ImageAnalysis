#include "node.h"

Node::Node(int pixelValue,int frequency){
  this->pixelValue = pixelValue;
  this->frequency = frequency;
}

Node::Node(){}

void Node::setLeft(Node* left){
  this->left = left;
}

void Node::setRight(Node* right){
  this->right = right;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}

Node::~Node(){}

void Node::setPixelValue(int pixelValue){
  this->pixelValue = pixelValue;
}

void Node::setFrequency(int frequency){
  this->frequency = frequency;
}

int Node::getPixelValue(){
  return pixelValue;
}

int Node::getFrequency(){
  return frequency;
}
