#include "huffmantree.h"
#include <iostream>

HuffmanTree::HuffmanTree(){}

HuffmanTree::~HuffmanTree(){}

void HuffmanTree::insertIntoQueue(Node *node){
  Node *auxNode = node;
  queue.push_back(node);

  if(queue.size()>1){
    vector<Node*>::iterator last = queue.end()-1;
    vector<Node*>::iterator previous = last-1;

    while(previous >= queue.begin() && (*previous)->getFrequency() > (*last)->getFrequency()){
      auxNode = (*previous);
      (*previous) = (*last);
      (*last) = auxNode;
      previous--;
      last--;
    }
  }
}

Node* HuffmanTree::getMin(){
  Node *min = (*(queue.begin()));
  queue.erase(queue.begin());
  return min;
}

void HuffmanTree::setRoot(Node* root){
  this->root = root;
}

Node* HuffmanTree::getRoot(){
  return root;
}

void HuffmanTree::preOrden(Node* root,string codeword){

  if(root->getLeft() != 0){
    codeword += "0";
    preOrden(root->getLeft(),codeword);
  }

  if(root->getRight() != 0){
    if(!codeword.empty())
      codeword = codeword.substr(0,codeword.size()-1);
    codeword += "1";

    preOrden(root->getRight(),codeword);
  }
  else
    codewords[root->getPixelValue()] = codeword;
}

map<int,string> HuffmanTree::getCodewords(){
  return codewords;
}
