#include <stdio.h>

int main() {
  printf("%d\n", __LINE__);
  printf("%s\n", __FILE__);
  printf("Compiled on: %s at %s\n", __DATE__, __TIME__);

  __STDC__ ? 
  printf("C Implementation is ISO conforming") :
  printf("C Implementation is not ISO conforming");

  return 0;
}
