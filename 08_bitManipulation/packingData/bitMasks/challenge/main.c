#include <stdio.h>

int main() {
  unsigned long input, output;
  int affectedBit;
  scanf("%ld", &input);
  scanf("%d", &affectedBit);

  // check if it is set
  if (input & (1 << affectedBit)) {
    printf("Bit set\n");
  } else {
    printf("Bit is not set\n");
  }

  // set nth bit to one
  output = input | (1 << affectedBit);

  // print number before setting
  printf("Number before setting %ld\n", input);
  printf("Number after setting %ld\n", output);
}
