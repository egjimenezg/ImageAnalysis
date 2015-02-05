#include<iostream>
#include<stack>
#define HEIGHT 10
#define WIDTH 10

using namespace std;

class Pixel{
  private:
    long x;
    long y;

  public:
    Pixel(long,long);
    long getX();
    long getY();
};

Pixel::Pixel(long x,long y){
  this->x=x;
  this->y=y;
}

class Image{
  private:
    static const int dx[4];
    static const int dy[4];
    static const int image[HEIGHT][WIDTH];
    int **aux; 
    int H;
    int W;
    stack<Pixel> pixels;
    void depth_search(long,long,long); 
  public:
    Image();
    ~Image();
    void printAuxMatrix();
    void segmentation();
    void findConnections(long,long,long);
    
};

const int Image::dx[4] = {1,0,-1,0};
const int Image::dy[4] = {0,+1,0,-1}; 
const int Image::image[HEIGHT][WIDTH] = {{1,1,1,1,1,1,1,1,1,1},
                                         {1,0,0,0,1,1,1,1,1,1},
                                         {1,0,0,0,1,1,1,1,1,1},
                                         {1,1,1,0,1,1,1,1,1,1},
                                         {1,1,1,0,0,1,1,1,1,1},
                                         {1,1,1,1,1,1,0,0,1,1},
                                         {1,1,1,1,1,1,0,0,1,1},
                                         {1,0,0,1,0,0,1,1,1,1},
                                         {1,0,0,0,0,0,1,1,1,1},
                                         {1,1,1,1,1,1,1,1,1,1}};


Image::Image(){
  int i,j;
  H = HEIGHT;
  W = WIDTH;
  aux = new int*[H];

  for(i=0;i<H;i++)
    aux[i] = new int[W];
  
  for(i=0;i<H;i++)
    for(j=0;j<W;j++)
      aux[i][j] = 0;
}

Image::~Image(){
  for(int i=0;i<H;i++)
    delete[] aux[i];
  
  delete[] aux;
}

void Image::depth_search(long x,long y,long label){
  if(x<0 || x==H)
    return;    
  if(y<0 || y==W)
    return;
  if(aux[x][y] || image[x][y])
    return;       
  aux[x][y] = label;

  for(int i=0;i<4;i++) 
    depth_search(x+dx[i],y+dy[i],label);

}

void Image::findConnections(long x,long y,long label){
  if(x<0 || x==H)
    return;    
  if(y<0 || y==W)
    return;
  if(aux[x][y] || image[x][y])
    return;       
  aux[x][y] = label;

 for(int i=0;i<4;i++) 
    //if(!image[x+dx[i]][y+dy[i]])    

}

void Image::printAuxMatrix(){
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << aux[i][j] << " ";
    }
    cout<<endl;
  }
}

void Image::segmentation(){
  int i,j;
  long label = 1000;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(!aux[i][j] && !image[i][j]){
        //depth_search(i,j,++label); 
      }
    } 
  }
}

int main() {
  long label = 1000;
  Image *image = new Image();
  image->printAuxMatrix();
  image->segmentation();
  cout << endl;
  image->printAuxMatrix();
  return 0;
}


