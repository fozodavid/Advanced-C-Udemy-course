// factorial
//
// 5! = 5 * 4 * 3 * 2 * 1 = 120;
// 
#include <stdio.h>

int factorial(int n);

int main() {
  printf("%d\n", factorial(5));
}

int factorial(int n) {
  //Factorial of 0 is 1 (base case is 0, return 1)
  if (n == 0) return (1);

  return (n * factorial(n - 1));
}
