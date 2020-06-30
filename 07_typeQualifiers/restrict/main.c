// restrict type qualifier is an optimization hint for the compiler
// the compiler can choose to ignore it
//
// used in pointer declarations as a type qualifier for pointers
// * tells the compiler that a particular pointer is the only reference to the
// value it points to throughout its scope
//  * the same value is not referenced by any other pointer or variable within that scope
//  * the pointer is the sole initial means of accessing a data object
// * tells the compiler it does not need to add any additional checks
//
// without the restrict keyword, the compiler has to assume the worst case
// that some other identifier might have changed the data in between two uses of a pointer
//
// with the restrict keyword used, the compiler is free to look for computational shortcuts
//
// not supported by c++
//
// Syntax
//
// int * restrict intPtrA;
// int * restrict intPtrB;
//
// tells the compiler that, for the duration of the scope in which intPtrA
// and intPtrB are defined
// they will never access the same value
//
// their use for pointing to integers inside an array is mutually exclusive
#include <stdio.h>
#include <malloc.h>

int main() {
  int n;
  int array[10];
  int * restrict restar = (int *) malloc(10*sizeof(int));
  int *par = array;

  for(n = 0; n < 10; n++) {
    par[n] += 5;
    restar[n] += 5;
    array[n] *= 2;
    par[n] += 3;
    restar[n] += 3;
  }

  restar[n] += 8;
}

void f1(int n, float * restrict a1, const float * restrict a2){
  int i;
  for (i = 0; i < n; i++) {
    a1[i] += a2[i];
  }
}

int main2(void) {
  return 0;
}
