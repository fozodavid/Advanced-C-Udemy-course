#include <stdio.h>
#include <math.h>


typedef long long ll;

int binToDec (int a) {
  int curr, i;
  int total = 0;
  for (i = 0; i < 16; i++) {
    curr = fmod(a, pow(10, i + 1));
    if (curr) {
      total += pow(2, i);
      a -= curr;
    }
  }
  return total;
}

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
  int binary;

  printf("Enter a binary number: ");
  scanf("%d", &binary);
  printf("%d\n", binToDec(binary));

  int inputDecimal;
  printf("Enter a decimal number: ");
  scanf("%d", &inputDecimal);
  printf("%d\n", decToBin(inputDecimal));
}
