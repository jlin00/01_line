#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (x0 > x1){ //if points do not go from left to right
    draw_line(x1, y1, x0, y0, s, c);
  }
  else {
    int x = x0;
    int y = y0;
    int a = y1 - y0;
    int b = x0 - x1;
    int d;
    if (b == 0){ //undefined slope or a single point
      while (y <= y1){
        plot(s, c, x, y);
        y++;
      }
    }
    else {
      double slope = (double)(a) / (-b);
      if (slope > 1){ //octant II & VI
        d = a + 2*b;
        while (y <= y1){
          plot(s, c, x, y);
          if (d < 0){
            x++;
            d += 2*a;
          }
          y++;
          d += 2*b;
        }
      }
      else if (slope > 0){ //octant I & V
        d = 2*a + b;
        while (x <= x1){
          plot(s, c, x, y);
          if (d > 0){
            y++;
            d += 2*b;
          }
          x++;
          d += 2*a;
        }
      }
      else if (slope > -1){ //octant IV & VIII
        d = 2*a - b;
        while (x <= x1){
          plot(s, c, x, y);
          if (d > 0){
            y--;
            d += 2*b;
          }
          x++;
          d -= 2*a;
        }
      }
      else { //octant III & VII
        d = a - 2*b;
        while (y >= y1){
          plot(s, c, x, y);
          if (d < 0){
            x++;
            d -= 2*a;
          }
          y--;
          d += 2*b;
        }
      }
    }
  }
}
