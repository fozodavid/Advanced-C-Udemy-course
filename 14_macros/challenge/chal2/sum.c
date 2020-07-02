#include <stdio.h>
#define SUM(x, y) ((x) + (y))
#define SQUARE_AND_CUBE(x) printf("square: %d | cube: %d\n", (x) * (x), (x) * (x) * (x))

int main() {
  int a = 5;
  int b = 10;
  printf("%d\n", SUM(a, b));
  SQUARE_AND_CUBE(a);
  return 0;
}
