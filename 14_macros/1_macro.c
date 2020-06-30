// piece of code based on the #define directive
// 
// macros are a text processing feature and are "expanded" and replaced by macro definitions
//
// today, macros are considered outdated, but it is still widely used
// it makes things easier to the programmer
//
// #define MACRO macro_body
//
// each #define line has 3 parts:
// * the first part is the #define directive itself
// * the second part is your chosen abbreviation, known as a macro name
// * the third part (the remainder of the line) is termed the replacement list of body
//   * preprocessor replaces macro name with the macro body
//
//   #define           PX    printf("x is %d.\n", x)
//   |                 |     |
//   preproc_directive macro body
//
//   Convention
//   should always use uppercase
//   to remind yourself to be alert of the possible macro side effects
//
//   there are no spaces in the macro name, however, spaces can appear
//   in the replacement string (macro_value)
//
//   macros are also not terminated by a semicolon
//
//   macros run until the first newline following the #
//   * limited by one line in length by default unless you use the backslash operator (\)
//   for continuation
//
#include <stdio.h>
#define PI 3.14

#define PRNT(a, b) \
  printf("value a = %d\n", a); \
  printf("value b = %d\n", b);

int main() {
  int x = 2;
  int y = 3;
  PRNT(x, y);
  return 0;
}
