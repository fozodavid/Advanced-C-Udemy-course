#include <stdio.h>


int main2 () {
  unsigned int w1 = 4151832098;
  int result = 0;
  result = w1 >> 1;
  return result;
}

int main() {
  int w1 = 138;         // 0000 0000 0000 0000 0000 1000 1010
  int result = w1 << 2; // 0000 0000 0000 0000 0010 0010 1000

  printf("%d\n", result);
  printf("%d\n", main2());
  return 0;
}
