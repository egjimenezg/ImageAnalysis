#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "node.h"
#include <vector>

using namespace std;

class HuffmanTree{
  private:    
    vector<Node*> queue;
    Node* root;

  public:
    HuffmanTree();
    ~HuffmanTree();
    void insertIntoQueue(Node *);
    void setRoot(Node*);
    Node* getRoot();
    Node* getMin();
};

#endif // HUFFMANTREE_H
