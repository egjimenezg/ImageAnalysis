#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "node.h"
#include <map>
#include <vector>
#include <string>

using namespace std;

class HuffmanTree{
  private:    
    vector<Node*> queue;
    map<int,string> codewords;
    Node* root;

  public:
    HuffmanTree();
    ~HuffmanTree();
    void insertIntoQueue(Node *);
    void setRoot(Node*);
    void preOrden(Node*,string);
    Node* getRoot();
    Node* getMin();
    map<int,string> getCodewords();
};

#endif // HUFFMANTREE_H
