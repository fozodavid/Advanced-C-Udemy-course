// Accessing union members of a structure
// * use dot (.) operator
// * to access pointer variables, we use the -> (indirection operator) 
//
// * the dot operator is used with a union name to specify a member of that union
/*
#include <stdio.h>

union {
  int code;
  float cost;
} item, *ptrst;

int main () {
  item.code = 1265;
  ptrst = &item;

  ptrst -> code = 3471;

  return 0;
}

 * following 3 are equivalent
 ptrst -> code
 item.code
 (*ptrst).code
 */

#include <stdio.h>

union mixed {
  char c;
  float f;
  int i;
};

union number {
  int x;
  double y;
};

void foo(union number a) {

}

/*
int main() {
  union mixed x;

  x.c = 'j';
  x.f = 2.2;

  printf("Character = %f\n", x.f);

  union number value2 = {15}; // only the first member can be initialized
  union number value3 = {.x = 16}; 
  union number value;
  value.x = 100;
  value.y = 0.3;
  printf("value: %d, %f\n", value.x, value.y);
  return 0;
}
*/

int main () {
  union number x;
  union number *y = &x;

  y -> x = 20;
  y -> y = 100.0;
  printf("value of integer x: %d\n", y -> x);
  printf("value of double y: %f\n", y -> y);

  return 0;
}
