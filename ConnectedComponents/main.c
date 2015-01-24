#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 20
#define WIDTH 20

typedef struct node{
  int imageValue;
  char label;
  struct node *next;
} Node;


void initializeList(Node*);

void initializeList(Node *head){
  head = (Node*)malloc(sizeof(Node));
  head->imageValue = 0;
  head->next = NULL;
}

void printMatrix(int matrix[20][20]){
  long i,j;
  i=j=0;
  for(i=0;i<HEIGHT;i++){
    for(j=0;j<WIDTH;j++)
      printf("%d ",matrix[i][j]);
  
    printf("\n");
  }
}

int main(){
  int i,j;
  i=j=0;
  Node *head; 
  initializeList(head);

  int image[20][20] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0}};


  printMatrix(image);

  return 0;
}


