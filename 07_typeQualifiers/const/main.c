#include <stdio.h>
#include "header.h"

int main() {
  printf("%f\n", pi);

  const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31 };

  typedef const int zip;

  zip q = 8;

  const float *pf; // pf points to a constant float value

  float * const pt; // pt is a const pointer address can't change

  const float * const ptr; // ptr address can't change, value can't change

  float const *pfc; // same as const float *pfc;

  return 0;
}

void display(const int array[], int limit) { // data to which the array points cannot be changed
  // const int array[] is same as const int *array

}

char *strcat(char *restrict s1, const char * restrict s2);
