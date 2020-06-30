#include <stdio.h>

int main() {
  size_t size = 0;

  printf("Enter the number of elements you want to store:");
  scanf("%zd", &size);
  int myarray[size];

  int i;
  for (i = 0; i < size; i++) {
    printf("Enter the %dth number of the array:", i);
    scanf("%d", &myarray[i]);
  }

  int sum = 0;
  for (i = 0; i < size; i++) {
    sum += myarray[i];
  }
  printf("%d\n", sum);

  return 0;
}
