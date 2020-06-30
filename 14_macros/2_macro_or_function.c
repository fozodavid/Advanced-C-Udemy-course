// many tasks can be done by using a macro with arguments or by using a function
//
// as we have learned in the last lecture, macros are essentially functions, but,
// with different syntax
// * behave just like a function
//
// however, there are some huge differences (under the hood) and without understanding
// these differences, you might be using either one when you should not be
//
// macros are preprocessed
// meaning they are all processed before the program compiles
// * functions are not preprocessed, they are compiled
//
// the main consideration becomes a trade off between time and space
//
// a macro is faster than a function
// * program control must shift to where the function is and then return to the calling program
// * takes longer than inline code
//
// * a macro that is used once in a program probably will not have any noticeable improvement
// in running time
//
// a macro inside a nested loop is a much better candidate for speed improvements
// * many systems offer program profiles to help you pin down where a program
// spends the most time
//
// SPACE
//
// when you call a function, it has to allocate some data (a newly allocated stack frame)
// * macros do not have this overhead
// * macros insert code directly into the program (textual substitution)
//
// a macro produces inline code ( a statement in your program)
// * if you use the same macro 20 times, you get 20 lines of code inserted
// into your program
//
// * if you use a function 20 times, you have just one copy of the function
// statements in your program (less space is used)
//
// functions are preferred to use in a program when running large chunks of code
//
//
// macros do not have to worry about variable types
// deal with character strings, not with actual values
// a macro can be used equally well with an int or float
// * just substitute the argument you pass them
//
// functions give you type checking
// * if a function expects a string, but you give it an int, you will get an error
//
// macros can have weird side effects if you are not careful
//
// much harder to debug a macro
// a function can be stepped through by the debugger, a macro cannot
//
// * you can tell gcc to tell you how everything expands using gcc -E source_file.c
//
// alternative to macros
// * inline functions are the best alternative to macros
//
// whne you add the inline keyword in front of a function, you are hinting to the compiler
// to embed the function body inside the caller (just like a macro)
//
// * inline functions can be debugged
// * inline functions also have type checking
//
// however, the inline keyword is merely a hint to the compiler, it is not a strict rule and the
// compiler can decide to ignore the hint
