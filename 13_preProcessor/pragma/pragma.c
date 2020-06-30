// #pragma
// the #pragma directive lets you place compiler instructions in your source code
// * lets you request special behavior from the compiler
//
// most useful for programs that are unusually large or that need to take advantage of the 
// capabilities of a particular compiler
//
// #pragmas can be used
// * to control the amount of memory set aside for automatic variables
// * to set the strictness of error checking
// * to enable nonstandard language features
//
// the pragma (pragmatic information) directive is part of the standard
// * the meaning of any pragma depends on the software implementation of the standard that is used
// * generally, each compiler has its own set of pragmas
//
// example: while C99 was being developed, it was referred to as C9X, and one compiler used the
// following pragma to turn on C9X support
//
// #pragma c9x on
//
// syntax is #pragma token_name
// * represents a command for the compiler to obey
//
// there are only a limited list of supported tokens for each standard/compiler
// * the set of commands that can appear in #pragma directives is different each compiler
// need to reference the compiler documentation
// a pragma not recognized by the implementation is ignored
//
// pragmas for the gcc compiler:
// #pragma GCC dependency
// #pragma GCC poison
// #pragma GCC system_header
// #pragma GCC once
// #pragma GCC warning
// #pragma GCC error
// #pragma message
//
// #pragma GCC dependency
// * allows you to check the relative dates of the current file and another file
// * if the other file is more recent that the current file, a warning is issued
//
// * this pragma is useful if the current file is derived from the other file,
// and should be regenerated
//
// #pragma GCC dependency "parse.y"
// #pragma GCC dependency "/usr/include/time.h" rerun fixincludes
//
// #pragma GCC poison
//
// this directive is used to remove an identifier completely from the program
//
// sometimes, there is an identifier that you want to remove completely from your program,
// and make sure that it is never used
//
// if any of those identifiers appear anywhere in the source after the directive, an error will be displayed by the compiler
//
// example
// #pragma GCC poison printf sprintf fprintf
// sprintf(some_string, "hello"); // will produce an error
/*
#include <stdio.h>

#pragma GCC poison printf

int main() {
  printf("Hello");
  return 0;
}
*/

// #pragma GCC system_header
// the #pragma GCC system_header tells the compiler to consider the rest of the current include file
// as a system header
// * code that comes before the '#pragma' in the file is not affected
// this pragma takes no arguments
//
// this pragma can affect the severity of some diagnostic messages
// * all warnings are suppressed while GCC is processing a system header
// * macros defined in a system header are immune to a few warnings wherever they are expanded
//
// #pragma once
// * header file containing this directive is included only once even if the programmer
// includes it multiple times during a compilation
// * works similar to using include guards
// * a less-portable alternative to using '#ifndef' to guard the contents
// of header files against multiple inclusions
//
// #pragma GCC warning "message"
// * causes the preprocessor to issue a warning diagnostic with the text 'message'
// * message contained in the pragma must be single string literal
//
// #pragma GCC error "message"
// * prints string as a compiler message on compilation
// * the message is informational only (not a warning or an error)
/*
#include <stdio.h>

#pragma GCC warning "hello"
#pragma GCC error "what"
#pragma message "ok"

int main() {
  return 0;
}
*/

// #error directive
//
// one of the least used but potentially most useful features of the C preprocessor is the
// ANSI-specified #error directive
//
// the #error directive causes the preprocessor to issue an error message that includes any text
// in the directive
// * error message is a sequence of characters separated by spaces
// * you do not have to enclose the text in quotes
// * the message is optional
/*
#if __STDC_VERSION__ != 201112L // should fail if compiler used is an older standard and succeed when it uses C11
#error Not C11
#endif
*/
// the code compiles, but it is still incorrect
//
// Useful when:
// incomplete code: #error *** Jason - Function incomplete
//
// Compiler-dependent code: 
// #include <float.h>
// #include <limits.h>
// #if (INT_MAX != 32767)
// #error *** This file only works with 16-bit int.
// DO not use this compiler! ***
//
// Conditionally-compiled code:
// #ifdef OPT_1
// /* Do option 1*/
// #elif defined OPT_2
// /* Do option 2*/
// #else
// #error *** You must define one of OPT_1 or OPT_2
// #endif
//

