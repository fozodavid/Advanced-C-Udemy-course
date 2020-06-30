#include <stdio.h>

int sum (int sum) {
  static int realSum = 0;
  realSum = realSum + sum;
  return realSum;
}

int main () {
  printf("%d ", sum(25));
  printf("%d ", sum(15));
  printf("%d ", sum(30));
  return 0;
}
