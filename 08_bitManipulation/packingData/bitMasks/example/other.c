#define BYTE_MASK 0xff
unsigned long color = 0x002a162f;
unsigned char blue, green, red;

red = color & BYTE_MASK;
green = (color >> 8) & BYTE_MASK;
blue = (color >> 16) & BYTE_MASK;
