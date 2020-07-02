// Overview
//
// the preprocessor includes the following four operators which can
// make is easier to create macros
/*
// \
// defined
// #
// ##
*/
// the backslash (\) operator allows for continuation of a macro to 
// the next line when the macro is too long for a single line
// * a macro is always a single, logical line
//
// the defined() operator is used in constant expressions to determine if
// an identifier is defined using #define
//
// the # and ## operators are used for concatenation
// * often useful to merge two tokens into one while expanding
// macros, called token pasting or token concatenation
//
// the ('#') operator is used within a macro definition
// * causes a replacement text token to be converted to a string
// surrounded by quotes
//
// the ('##') operator performs token pasting
// * concatenates two tokens
// * when a macro is expanded, the two tokens on either side of
// each '##' operator are combined into a single token
// (\) operator
/*
// #define MIN(x, y) \
// ((x)<(y) ? (x) : (y))
*/
// backslash must be the last character on the line
// 
// defined() operator
//
// can be used in if statements
// #if defined(DEBUG)
// #endif
//
// same as #ifdef DEBUG
// ...
// #endif

/*
 * #if defined (WINDOWS) || defined (WINDOWSNT)
 * #  define BOOT_DRIVE "C:/"
 * #else
 * #  define BOOT_DRIVE "D:/"
 * #endif 
 */


// # and ## operators
// are often used to merge 2 tokens
// * token pasting or token concatenation
//
// the # operator causes a replacement text token to be converted
// to a string surrounded by quotes (String expansion)
//
// the # operator
//
// if you place a # in front of a parameter in a macro definition
// * creates a constant string out of the macro argument when the macro is invoked
// * literally inserts double quotation marks around the actual macro argument
//
// #define str(x) # x
// causes the subsequent invocation
// str(testing)
//
// to be expanded into testing
//
// printf(str(Programming in C is fun.\n));
// is therefore equivalent to
// printf("Programming in C is fun\n");
// #define HELLO(X) printf("Hello, " #x "\n");
//
// when HELLO(John) appears in a program file, it is expanded to
//
// printf("Hello, " "John" "\n");
// * strings separated by whitespace are concatenated during preprocessing
//
// printf("Hello, John\n");
//
// * the # operator must be used in a macro with arguments because the operand of
// # refers to an argument of the macro
//
// Practical Example
// #define printint(var) printf(# var " = %i\n", var)
//
// printint(count) // becomes
// printf("count" " = %i\n", count);
//
// the ## operator
//
// is used for concatenation to join two tokens together
// * preceded (or followed) by the name of a parameter to the macro
// * takes the actual argument to the macro that is supplied when the macro is invoked and
// creates a single token out of that argument and whatever token follows (or precedes) the ##
//
// the ## operator
//
// #define TOKENCONCAT(x, y) x ## y // TOKENCONCAT(O, K) is replaced by OK in the program
//
// example:
// #define concatenate(x, y) x ## y
// ...
// int xy = 10;
// ...
//
// will make the compiler turn
// printf("%d", concatenate(x, y));
// into
// printf("%d", xy);
// // prints 10
//
// #define make_function ( name ) int my_ ## name (int foo) {}
// make_function(bar)
// * will define a function called my_bar()
//
// #define eat(what) puts("I'm eating " #what " today.")
// eat(fruit)
// turns into:
// puts("I'm eating " "fruit" " today.");
//
// interpretting named commands, there is a table of commands as follows
//
// struct command {
//   char *name;
//   void (*function) {void};
// };
//
// struct command commands[] = {
//   {"quit", quit_command},
//   {"help", help_command},
//   ...
// }
//
//
// #define COMMAND(name) { #name, name ## _command }
// struct command commands[] = {
//   COMMAND(quit);
//   COMMAND(help);
// };
