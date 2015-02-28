#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "node.h"
#include <vector>

using namespace std;

class HuffmanTree{
  private:    
    vector<Node*> queue;

  public:
    HuffmanTree();
    ~HuffmanTree();
    void insertIntoQueue(Node *);
    Node* getMin();

};

#endif // HUFFMANTREE_H
