// there are many standard preprocessing macros defined by the compiler (defined in the documentation)
//
// standard C provides predefined symbolic constants
// * begin and end with two underscores
// * cannot be used in #define or #undef directives
//
// __FILE__
// * represents the current file name (string)
//
// __LINE__
// * represents the current line number of the current source code ( an integer constant )
//
// __func__
// * the name of any function when placed inside a function of the current file
//   * not part of the standard
//
// __DATE__
// * the date the source file was compiled ( a string of the form MMM DD YYYY as Jul 02 2020 )
//
// __TIME__
// * the time the source file was compiled ( a string literal of the form "hh:mm:ss" )
//
// __STDC__
// * used to indicate if the compiler supports standard C by returning the value 1
//
// __FILE__ and __LINE__
// the __FILE__ macro represents the name of the current source file as a string literal
// * typically a string literal comprising the entire file path
//   * "C:\\Projects\\Test\\MyFile.c"
//
// __LINE__ and __FILE__ can be used together to see where the error occured in the source code
//
// if(fopen(&pfile, filename, "rb"))
// {
//   fprintf(stderr, "Failed to open file in %s line %d\n", __FILE__, __LINE__);
//   return -1;
// }
//
// __func__
//
// #include <stdio.h>
//
// void my_function_name(void) {
//   printf("%s was called.\n", __func__);
// }
//
// this function just outputs its own name within the format string
// 
// my_function_name was called
//
// __TIME__ and __DATE__
//
// printf("Program last compiled at %s on %s\n", __TIME__, __DATE__);
//
// __STDC__
//
// * this macro expands to the constant 1 if the current compiler being used conforms to the ISO
// standard C compiler
//
// #include <stdio.h>
//
// int main(void) {
//   #if (__STDC__ == 1)
//     printf("Implementation is ISO-conforming.\n");
//   #else
//     printf("Implementation is not ISO-conforming.\n");
//   #endif
//   /* ... */
//
//   return 0;
// }
