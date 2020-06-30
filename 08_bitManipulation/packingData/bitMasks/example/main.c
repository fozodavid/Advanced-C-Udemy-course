#include <stdio.h>

int main() {
  unsigned long packed_data;
 
  packed_data |= 7 << 18;


  // packed_data &= ~(0xff << 18);
  // packed_data = (packed_data & ~(0xff << 18)) | ((n & 0xff) << 18);
  //
  // to extract the type field of packed_data and assingn it to n
  // n = (packed_data >> 18) & 0xff);
}
