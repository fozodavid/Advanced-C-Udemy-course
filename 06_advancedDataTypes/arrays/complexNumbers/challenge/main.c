#include <stdio.h>
#include <complex.h>
#include <math.h>

#define __STDC_WANT_LIB_EXT1__ 1

void display(double complex a) {
  printf("%.2f%+.2fi\n", creal(a), cimag(a));
}

int main() {
  double complex a = I * I;
  display(a);

  double complex b = cpow(I, 2);
  display(b);

  double complex c = I * acos(-1); // maybe messed up Euler's formula
  display(c);

  double complex d = 1 + 2 * I;
  double complex conjugate = conj(d);
  display(conjugate);
}
