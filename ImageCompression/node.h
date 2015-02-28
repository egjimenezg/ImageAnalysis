#ifndef NODE_H
#define NODE_H

class Node{

  private:
     int pixelValue;
     int frequency;
     float probability;
     Node* left;
     Node* right;

  public:
    Node(int,int);
    Node();
    ~Node();
    void setLeft(Node*);
    void setRight(Node*);
    Node* getLeft();
    Node* getRight();
    void setPixelValue(int);
    void setFrequency(int);
    int getPixelValue();
    int getFrequency();


};

#endif // NODE_H
