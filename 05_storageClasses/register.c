#include <stdio.h>

int main() {
  register int x;  // register variable

  for (x = 1; x <= 15; x++) {
    printf("\n%d", x);
  }

  return 1;
}
