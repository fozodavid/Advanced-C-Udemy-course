#include <stdio.h>

extern float myFloat;
void mainmain();

int main() {
  mainmain();
  printf("other.c, myFloat: %f\n", myFloat);
}
