#include <stdio.h>

static double myDouble = 2.0;
float myFloat = 2.1;
static float MyStaticFloat = 2.2;

static void myfunc () {
  printf("static func\n");
}

void permanentStorage() {
  static float y = 0;
  y++;
  printf("%f\n", y);
}

void mainmain() {
  for (int x = 0; x < 5; x++) {
    printf("%d\n", x);
  }
  register int r;
  r = 25;
  printf("myRegisterVar%d\n", r);
  myfunc();
  printf("myStaticFloat: %f\n", MyStaticFloat);
  printf("myGlobalFloat: %f\n", myFloat);
  printf("myStaticDouble: %f\n", myDouble);
  permanentStorage();
  permanentStorage();
  permanentStorage();
}
