#ifndef NODE_H
#define NODE_H

class Node{

  private:
     int pixelValue;
     int frequency;
     float probability;

  public:
    Node(int,int);
    ~Node();
    void setPixelValue(int);
    void setFrequency(int);
    int getPixelValue();
    int getFrequency();

};

#endif // NODE_H
