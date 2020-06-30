#include <stdio.h>

void display() {
  extern int i;
  printf("%d\n", i);
}
