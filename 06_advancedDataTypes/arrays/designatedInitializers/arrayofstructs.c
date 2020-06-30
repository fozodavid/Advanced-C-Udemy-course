#include <stdio.h>

struct point { int x, y; };

int main() {

  struct point pts[5] = { [2].y = 5, [2].x = 6, [0].x = 2};

  for (int i = 0; i < 5; i++) {
    printf("%d %d\n", pts[i].x, pts[i].y);
  }

}
