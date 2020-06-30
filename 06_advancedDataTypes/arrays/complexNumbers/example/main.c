#include <stdio.h>
#include <complex.h>

#define __STDC_WANT_LIB_EXT1__ 1

int main() {

  #ifdef __STDC_NO_COMPLEX__

  #else
    printf("Complex numbers are supported.\n");

    double complex cx = 1.0 + 3.0*I;
    double complex cy = 1.0 - 4.0*I;

    printf("Working with complex numbers:\n");
    printf("Starting values. cx = %.2f%+.2fi cy = %.2f%+.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));

    double complex sum = cx+cy;
    printf("\nThe sum cx + cy = %.2f%+.2fi\n", creal(sum), cimag(sum));

    double complex conjugate = conj(cx);
    printf("\nThe conjugate of cx = %.2f%+.2fi\n", creal(conjugate), cimag(conjugate));


    double complex a = 32.123 + 24.456*I;
    double complex b = 23.123 - 42.456*I;

    double complex pwr = cpow(a,b);
    printf("\na on the bth power is: %.2f%+.2fi\n", creal(pwr), cimag(pwr));

    return 0;
  #endif

}
