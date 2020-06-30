#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void my_exit(void);

void my_exit(void) {
  printf("Exiting...\n");
  exit(0);
}

int main() {
  my_exit(); // my exit doesn't return anything
  return 0;
}
