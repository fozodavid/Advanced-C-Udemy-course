#include <stdio.h>
#include <malloc.h>

struct s {
  int arraySize;
  int array[]; // can be declared only as the last member
};

int main() {
  int desiredSize = 5;
  struct s *ptr;

  ptr = malloc( sizeof( struct s) + desiredSize * sizeof( int ) );
  return 0;
}
