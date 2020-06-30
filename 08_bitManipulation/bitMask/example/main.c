#include <stdio.h>

int main() {
  int flags = 15;
  int mask = 182;

  // turning on certain bits
  flags |= mask;
  printf("%d\n", flags);

  // clearing certain bits
  flags = flags & ~mask;
  printf("%d\n", flags);

  // toggling certain bits
  flags = flags  ^ mask;
  printf("%d\n", flags);

  // are bits set?
  // if ((flags & mask) == mask)

  return 0;
}
