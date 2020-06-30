#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void func();

void func(void) {
  printf("In func()...\n");
} /* Undefined behavior as func() returns */

int main() {
  func();
  return 0;
}

// compiler error/warning
