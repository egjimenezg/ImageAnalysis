#include "huffmantree.h"

HuffmanTree::HuffmanTree(){}

HuffmanTree::~HuffmanTree(){}

void HuffmanTree::insertIntoQueue(Node* node){
  int index;
  while(queue.at(index)){
   index++;
  }
  queue.insert(index,node);
}

Node* HuffmanTree::getMin(){
  return queue.at(0);
}
