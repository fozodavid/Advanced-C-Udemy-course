#include <stdio.h>
#include <malloc.h>

struct myArray {
  int length;
  int array[];
};

int main() {
  size_t size = 0;
  struct myArray *ptr;

  printf("Enter the size of the array:");
  scanf("%zd", &size);

  ptr = malloc( sizeof( struct myArray ) + size * sizeof( int ) );

  int i;
  for (i = 0; i < size; i++) {
    (*ptr).array[i] = 10;
  }

  for (i = 0; i < size; i++) {
    printf("%d ", (*ptr).array[i]);
  }
}
