#include <stdio.h>

#include <stdio.h>


void swap () {
  short int w1 = 147;
  short int w2 = 61;

  w1 ^= w2;
  w1 ^= w1;
  w1 ^= w2;
}

int main() {
  swap();
  short int w1 = 0b10010011; // 147
  short int w2 = 0b00111101; // 61
  short int w3 = 0;

  w3 = w1 & w2;
  printf("%d\n", w3);

  w3 = w1 | w2;
  printf("%d\n", w3);

  w3 = w1 ^ w2;
  printf("%d\n", w3);

  w3 = w1 - w2;
  printf("%d\n", w3);

  signed int value1 = 154;
  signed int result = 0;
  result = ~(value1);
  printf("%d", result);

  return 0;
}
