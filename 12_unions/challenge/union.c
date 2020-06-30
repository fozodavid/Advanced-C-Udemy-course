// UNIONS CHALLENGE
//
// how to define/declare unions
//
// write a program that defines union, use this union to assign and access its members
//
#include <stdio.h>

union student {
  char letterGrade;
  char letterGrade2;
  int roundedGrade;
  float exactGrade;
} var3;

void display(union student s, const char * name) {
  printf("%s union values:\n  letterGrade: %c\n  letterGrade2: %c\n  roundedGrade: %d\n  exactGrade: %f\n\n",
      name,
      s.letterGrade,
      s.letterGrade2,
      s.roundedGrade,
      s.exactGrade);
}

struct class {
  int number;
  union student s;
} myclass;

int main() {
  union student var1, var2, *ptr;

  ptr = &var2;
  var1.exactGrade = 2.45;

  display(var1, "var1");

  ptr -> letterGrade = 'a';
  (*ptr).letterGrade = 'c';
  printf("sizeof var2: %zu\n", sizeof(var2));

  display(var2, "var2");

  union student var4 = {.exactGrade = 3.67};

  display(var4, "var4");

  struct class * ptr2;
  ptr2 = &myclass;

  ptr2 -> s.letterGrade = 'a';
  display(ptr2 -> s, "class pointer");

  return 0;
}

// TASK 2 use option tag in the declaration
//
// TASK 3 use pointers as union variables and practice assigning/accessing members
//
// TASK 4 display total size of the union in bytes
//
// TASK 5 initializing union member by a designated initializer
//
// TASK 6 add a union inside a structure
