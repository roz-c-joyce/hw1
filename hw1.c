#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){

  char buff[256];
  int i = 0;
  while(i < 256){
    buff[i] = 0;
    i++;
  }

  int xr = 500;
  int yr = 500;
  int c = 255;

  int r = 0;
  int g = 0;
  int b = 0;

  FILE *f1 = fopen("pic.ppm", "w");
  fprintf(f1, "P3\n%d %d %d\n", xr, yr, c);

  int x = 0;
  int y = 0;
    
  while(y < yr){
    while(x < xr){
      printf("xres: %d\nyres: %d\n[XVAL: %d]\n[YVAL: %d]\n\n", xr, yr, x, y);
      r = ((x * x) + x + 5) % c;
      g = ((y * y * y) + (y * y) + y -3) % c;
      b = (y * y * x) % c;

      fprintf(f1, " %d %d %d \n", r, g, b);
      x++;
    }
    x = 0;
    y++;
  }
  fclose(f1);
  return 0;
}
