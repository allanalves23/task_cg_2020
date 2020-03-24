#include <stdio.h>
#include <stdlib.h>

#define MAXSCREENX 10 // Max Width of fake screen
#define MAXSCREENY 10 // Max height of fake screen

// Display a fake screen
void display(int x, int y, int line[MAXSCREENX][MAXSCREENY]){
  int xq, yq;
  
  for(xq = 1; xq <= x; xq++){
    for (yq = 1; yq <= y; yq++){
      int color = line[yq][xq] == 100 ? 1 : 0;
      printf("%d", color);
    }
    printf("\n");
  }
}

// Generates a straight through its generation equation
void writeLine(int x1, int y1, int x2, int y2){
  int x,y;
  float a;
  int coords[MAXSCREENX][MAXSCREENY];

  a = (y2-y1)/(x2-x1);

  for (x = x1; x <= x2; x++){
    y = (y1 + a * (x - x1)); // Straight equation
    coords[x][y] = 100;
  }
  
  display(MAXSCREENX,MAXSCREENY,coords);
}

int main(){
  int xmin, xmax, ymin, ymax;

  printf("===STRAIGHT EQUATION===\n");

  printf("Define xmin in cartesian plane: ");
  scanf("%d", &xmin);
  printf("Define xmax in cartesian plane: ");
  scanf("%d", &xmax);
  printf("Define ymin in cartesian plane: ");
  scanf("%d", &ymin);
  printf("Define ymax in cartesian plane: ");
  scanf("%d", &ymax);

  writeLine(xmin, ymin, xmax, ymax);
  
  return 0;
}