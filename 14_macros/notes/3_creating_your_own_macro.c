// non functional macro
// #define NONFMAC some text here
//
// * defines a macro and some replacement text
// after definition the macro can be used like so
// NONFMAC
// /* some text here */
// leading and trailing white space around the replacement text is discarded
//
// its name is simply replaced by its replacement text
//
// function macros look more like a function
// #define FMAC(a,b) a here, then b
//
// #define macro_name(list_of_identifiers) substitution_string
//
// defines a macro and some replacement text
// * the list of identifiers separated by commas(a, b) appears between parentheses following
// the macro_name (FMAC)
// * each of these identifiers can appear one or more times in the substitution string
//
// after the definition, the macro can be used as follows
//
// FMAC(first text, some more)
// /* first text here, then some more */
//
// leading or trailing white space around the replacement is discarded
//
// it gets a bit trickier with the function macro because of the (identifiers) or formal parameters
//
// macros with arguments
// * you can create function-like macros that look and act much like functions when you pass data to them
// * looks very similar to a function because the arguments are enclosed within parentheses
//
// function-like macro definitions have one or more arguments in parentheses, and these arguments
// then appear in the replacement portion
//
// to create a macro with arguments, put them in parentheses separated by commas after the macro name
//
// #define SQUARE(X) X * X
//
// can be used in program like below
//
// z = SQUARE(2);
//
// looks like a function call, but it does not necessarily behave identically
//
// #define macro_name(list_of_identifiers) substitution_string
//
// a macro that contains arguments has its arguments substituted in the replacement text when the macro is expanded
// * the replacement text for a macro is any text on the line after the identifier in the #define directive
// * the replacement-text replaces the identifier and argument list in the program
//
// * you should use parenthesis around each argument and around the definition as a whole
// * ensures that the enclosed terms are grouped properly in an expression (avoid operator precedence)
/*
#include <stdio.h>
#define PI 3.14
#define CIRCLE_AREA(X) (PI * (X) * (X))

int main () {
  int c = 2;
  double area = CIRCLE_AREA(c + 2);
  printf("%f\n", area);
  return 0;
}
*/

// variadic macro
/*
#include <stdio.h>
#define WARNING(format, ...) fprintf(stderr, format, __VA_ARGS__)

int main() {
  WARNING("%s: this program is here\n", "LOL");
  return 0;
}
*/

// functional macro side effects

/*
#define SQUARE(x) ((x++) * (x++))
#define MISC(x) (puts("incrementing", (x)++)

#define MAX(a,b) ((a) > (b) ? (a) : (b))

#include <stdio.h>
#define UP_TO(i, n) for ((i) = 0; (i) < (n); (i)++)

int main() {
  int i;
  UP_TO(i, 10) 
  {
     printf("%d\n", i);
  };

  return 0;
}
*/
