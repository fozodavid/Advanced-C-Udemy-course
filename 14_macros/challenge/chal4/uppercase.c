// check if a character is uppercase or lowercase using macros

#include <stdio.h>
#include <ctype.h>

#define MY_VAR(name) #name
#define UPPERC(c) isupper(c)
#define LOWERC(c) islower(c)
#define LOWER_UPPERC_CHECK() \
  char ch = '\0'; \
  printf("Enter a character: "); ch = getchar(); \
  if (UPPERC(ch)) { printf("%c is uppercase", ch); } \
  else if (LOWERC(ch)) { printf("%c is lower case", ch); } \
  else { printf("%c is not in the alphabet", ch); }

#define MY_TOKEN 1
#define TOKEN_FUNC(a) a ## _TOKEN

  

int main() {
  // LOWER_UPPERC_CHECK();
  if (TOKEN_FUNC(MY)) printf("It works");

  return 0;
}
