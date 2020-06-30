#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double average(double v1, double v2, ...);

double sample_stddev (int count, ...);

void using_va_copy();
void using_variadic();

int main() {
  using_va_copy();
  return 0;
}

double average(double v1, double v2, ...) {
  va_list parg;
  double sum = v1 + v2;
  double value = 0.0;

  int count = 2;
  va_start(parg, v2);

  while ((value = va_arg(parg, double)) != 0.0) {
    sum += value;
    ++count;
  }

  va_end(parg);

  return sum/count;
}

void using_va_copy() {
  printf("%f\n", sample_stddev(4, 25.0, 27.3, 26.9, 25.7));
}

double sample_stddev (int count, ...) {
  double sum = 0;

  va_list args1;
  va_start(args1, count);

  va_list args2;
  va_copy(args2, args1);

  for (int i = 0; i < count; ++i) {
    double num = va_arg(args1, double);
    sum += num;
  }

  va_end(args1);

  double mean = sum / count;
  double sum_sq_diff = 0;

  for (int i = 0; i < count; ++i) {
    double num = va_arg(args2, double);
    sum_sq_diff += (num - mean) * (num - mean);
  }

  va_end(args2);

  return sqrt(sum_sq_diff / count);
  
}

void using_variadic() {
  double v1 = 10.5, v2 = 2.5;
  int num1 = 6, num2 = 5;
  long num3 = 12L, num4 = 20L;

  printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0));
  printf("Average = %.2lf\n", average(1.0, 2.0, 0.0));
  printf("Average = %.2lf\n", average((double)num2, v2, (double)num1, (double)num4,(double)num3, 0.0));
}
