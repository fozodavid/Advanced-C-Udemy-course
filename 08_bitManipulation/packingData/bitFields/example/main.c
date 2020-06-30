#include <stdio.h>

struct packed_struct {
  unsigned int :3;
  unsigned int f1:1;
  unsigned int f2:1;
  unsigned int f3:1;
  unsigned int type:8;
  unsigned int index:18;
};

int main() {
  struct packed_struct packed_data = {1,1,1,7,9};

  unsigned int bit = packed_data.type = 7;

  unsigned i = packed_data.index / 5 + 1;

  if (packed_data.f2) {

  }

  return 0;
}
