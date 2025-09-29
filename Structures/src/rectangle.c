#include "rectangle.h"
#include <stdio.h>

int area(Rectangle r) {
  if (r.h < 0 || r.w < 0)
    return -1;
  return r.w * r.h;
}

void grow(Rectangle *r, int dw, int dh) {
  
  if (r != NULL) {
    
    int n_h = r->h + dh;
    int n_w = r->w + dw;
    if (n_h >= 0)
      r->h = n_h;
    else {
      puts("You can't do this mutation\n");
      return;
    }
    if (n_w >= 0)
      r->w = n_w;
    else {
      puts("You can't do this mutation\n");
      return;
    }
  }
}