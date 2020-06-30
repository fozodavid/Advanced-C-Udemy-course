#include <stdio.h>

void array(int size) {
  char alpha[size];
  int x = 0;

  while (x < size) {
    alpha[x] = 'A' + x;
    printf("alpha is: %c: \n", alpha[x]);
    x++;
  }
}

int sum2d(int rows, int cols, int array[rows][cols]) {
  int r;
  int c;
  int tot = 0;

  for (r = 0; r < rows; r++)
    for (c = 0; c < cols; c++)
      tot += array[r][c];
  return tot;
}


int main() {
  array(5);
  array(20);
  array(9);
  return 0;
}
