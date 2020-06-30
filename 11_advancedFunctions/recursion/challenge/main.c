// CHALLENGE 1
// sum of numbers 1 to n using recursions
// input last number in a range
// input 5
// output 15
//
// CHALLENGE 2
// greatest common denominator of two numbers using recursion
// input 10
// input 50
// the GCD of 10 and 50 is: 10
//
// CHALLENGE 3
// find reverse of the string using recursion
// studytonight
// thginotyduts
// pointer to a character

#include <stdio.h>

int recursive_sum(int n);
int recursive_gcd(int a, int b);
void reverse_str(char * str);

int main() {
  // printf("%d\n", recursive_sum(5));
  // printf("%d\n", recursive_gcd(21, 14));
  reverse_str("studytonight");
  return 0;
}

int recursive_sum(int n) {
  if (n == 1) return 1;
  return n + recursive_sum(n - 1);
}

int worker_gcd(int a, int b, int denom) {
  if (a % denom == 0 && b % denom == 0) {
    return denom;
  } else {
    return worker_gcd(a, b, denom - 1);
  }
}

int recursive_gcd(int a, int b) {
  if (a > b) return worker_gcd(a, b, b);
  else return worker_gcd(a, b, a);
}

void reverse_str(char * str) {
  if (* str == '\0') return;
  reverse_str(str + 1);
  putc(*str, stdout);
}
