#include <stdio.h>
#include <math.h>

int decToBin (int a) {
  int curr, i;
  int total = 0;
  for (i = 0; i < 16; i++) {
    curr = fmod(a, pow(2, i + 1));
    if (curr) {
      total += pow(10, i);
      a -= curr;
    }
  }
  return total;
}

int main() {
  signed int w1;
  signed int w2;

  scanf("%d", &w1);
  scanf("%d", &w2);

  printf("%d\n", decToBin(w1));
  printf("%d\n", decToBin(w2));
  printf("test: %d\n", ~(w1));
  printf("%d\n", decToBin(~(w2)));
  printf("%d\n", decToBin(w1 & w2));
  printf("%d\n", decToBin(w1 | w2));
  printf("%d\n", decToBin(w1 ^ w2));
  return 0;
}
