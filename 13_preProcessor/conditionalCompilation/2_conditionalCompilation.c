// Conditional Compilation
//
// often used to create one program that can be compiled to run on
// different computer systems
//
// large program that had many dependencies on specific hardware or software
// you could have too many define value
// these can be improved by having conditional compilation
//
// only include this define in a specific situation
// used to switch on or off various statements in the program
// very useful in debugging
// trace the flow of program execution
//
// only include certain code based on certain conditions to compile
//
// ~ enables you to control the execution of preporcessor directives and the compilation of program code
// * each of the conditional preprocessor directives evaluates an identifier or a constant integer expression
// * cast expressions, sizeof expressions and enumeration constants cannot be evaluated in preprocessor directives
//
// ~ Commands
//
// accept or ignore blocks of information or code according to conditions at the time of compilation
//
// the conditional preprocessor construct is much like the if selection statement
// every #if construct ends with an #endif
//
// #ifdef and #ifndef are shorthand for #if defined(name) #if !defined(name)
// multiple-part conditional preprocessor constructs
// may be tested with directives #elif and #else
//
// #ifdef checks if an identifier is currently defined
// * identifiers can be defined by a #define directive or on the command line
// #define UNIX 1 OR #define UNIX
//
// set identifiers in the command line
// gcc -D UNIX program.c

#include <stdio.h>

// #define JUST_CHECKING  // main reason to do stuff like this is
// debugging
#define LIMIT 4

int main() {
  int i;
  int total = 0;

  for (i = 1; i <= LIMIT; i++) {
    total += 2*i*i + 1;

    #ifdef JUST_CHECKING
      printf("i-%d, running total - %d\n", i, total);
    #endif
  }

  printf("Grand total = %d\n", total);
  return 0;
}

// #ifndef
// if an identifier is not defined, if not def is a negative of ifdef
// common case
// #ifndef SIZE
//   #define SIZE 100
// #endif
//
// #if
// test the value of a constant expression
// #if constant_expression
// the operand must be a constant integer expression that does 
// not contain an increment(++), decrement(--)
// sizeof, pointer(*), address(&) and cast operators
// also use relational and logical operator with the #if directive
//
// #else
// 
// they can be nested
//
// #ifdef UNIX
//   #define DATADIR "/uxn1/data"
// #else
//   #define DATADIR "\usr\data"
// #endif
//
// #define UK 1
// #define France 2
// #define Germany 3
// #define Country US
//
// int main() {
//   #if Country == US || Country == UK
//     #define Greeting "Hello."
//   #elif Country == France
//     #define Greeting "Bonjour."
//   #elif Country == Germany
//     #define Greeting "Guten Tag."
//   #endif
//
// #ifndef directive is commonly used to prevent multiple inclusions of a file
// prevents multiple definitions of the same variable/function/macro
// standard c header files uses the #ifndef technique to avoid multiple inclusions
//
// #undef undefine something you have previously defined
