// test understanding of variadic functions
//
// create variadic function that will allow a programmer to add any amount of numbers that they would like to be added together
//
// first argument telling how many arguments there will be
//
// invoke the function
// addingNumbers(2, 10, 20);
// addingNumbers(3, 10, 20, 30);
// addingNumbers(4, 10, 20, 30, 40);
//
// Output:
// 30
// 60
// 100
//
// challenge 2: use doubles
//
// challenge 3: average value and sum of unknown numbers, max and min of a list of numbers
//
// challenge 4: create own printf functions

#include <stdio.h>
#include <stdarg.h>

void addingNumbers(int count, ...);
void use_addingNumbers();

void addDoubles(int count, ...);

void abominationFunc(int count, ...);
void own_printf(char * str, ...);

void use_addingNumbers() {
  addingNumbers(2, 10, 20);
  addingNumbers(3, 10, 20, 30);
  addingNumbers(4, 10, 20, 30, 40);
}

void addDoubles(int count, ...) {
  va_list args;
  va_start(args, count);
  double total = 0.0;
  double value;
  for (int i = 0; i < count; i++) {
    value = va_arg(args, double);
    total += value;
  }
  printf("%f\n", total);
  va_end(args);
}

void addingNumbers(int count, ...) {
  va_list args;
  va_start(args, count);

  int total = 0;
  int value;
  for (int i = 0; i < count; i++) {
    value = va_arg(args, int);
    total += value;
  }
  printf("%d\n", total);
  va_end(args);
}

void abominationFunc(int count, ...) {
  va_list args;
  va_list arg_mean;
  va_list arg_max;
  va_list arg_min;

  va_start(args, count);
  va_copy(arg_mean, args);
  va_copy(arg_max, args);
  va_copy(arg_min, args);
  double value, total, mean;
  for (int i = 0; i < count; i++) {
    value = va_arg(arg_mean, double);
    total += value;
  }
  mean = total / count;
  printf("The mean is: %f\n", mean);
  
  double max = va_arg(arg_max, double);
  for (int i = 0; i < count - 1; i++) {
    value = va_arg(arg_max, double);
    if (max < value) max = value;
  }
  printf("The maximum number is: %f\n", max);

  double min = va_arg(arg_min, double);
  for (int i = 0; i < count - 1; i++) {
    value = va_arg(arg_min, double);
    if (min > value) min = value;
  }
  printf("The minimum number is: %f\n", min);
  va_end(args);
  va_end(arg_mean);
  va_end(arg_max);
  va_end(arg_min);
}

void own_printf(char * str, ...) {
  va_list args;
  va_start(args, str);
  char * ptr;
  
  for(ptr = str; *ptr != '\0'; ptr++) {

    if (*ptr == '%' && (*(ptr + 1) == 'd')) {
      int arg = va_arg(args, int);
      printf("%d", arg);
      ptr++;
    } else if (*ptr == '%' && (*(ptr + 1) == 'c')) {
      char arg = va_arg(args, int);
      printf("%c", arg);
      ptr++;
    } else if (*ptr == '%' && (*(ptr + 1) == 's')) {
      const char * arg = va_arg(args, const char *);
      printf("%s", arg);
      ptr++;
    } else {
      putc(*ptr, stdout);
    }
  }
  va_end(args);
}

int main() {
  // abominationFunc(4, 10.0, 20.0, 30.0, 40.0);
  own_printf("Hello World! %d, %d, %c, %s!\n", 33, 55, 'c', "string");
  return 0;
}

