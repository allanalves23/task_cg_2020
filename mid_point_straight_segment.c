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

// Generates a straight segment with incremental midpoint
void writeLine(int x1, int y1, int x2, int y2){
  int dx,dy, incE, incNE, d, x, y;
  int coords[MAXSCREENX][MAXSCREENY];

  dx = x2 - x1;
  dy = y2 - y1;
  d = 2 * dy - dx;
  incE = 2 * dy;
  incNE = 2 * (dy - dx); 
  x = x1;
  y = y1;
  coords[x][y] = 100;

  while(x < x2) {
    if(d <= 0){
      d = d + incE;
      x = x + 1;
    }else{
      d = d + incNE;
      x = x + 1;
      y = y + 1;
    }
    coords[x][y] = 100;
  }
  
  display(MAXSCREENX,MAXSCREENY,coords);
}

int main(){
  int xmin, xmax, ymin, ymax;

  printf("===MID POINT===\n");

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