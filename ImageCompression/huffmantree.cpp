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
  Node* min = queue.back();
  queue.pop_back();
  return min;
}
