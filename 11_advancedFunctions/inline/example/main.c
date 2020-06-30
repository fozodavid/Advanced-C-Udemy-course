// Inline functions
//
// normally a function has overhead
//
// compiler replaces every call to an inline function with the code body of a function
// inline declaration is only a hint to the compiler: not a guarantee
//
// can increase the size of a program
// only declare functions as inline if they are short and called frequently
//
// for a long function, the time consumed in calling the function is short compared to the
// time spent executing the body of the function
//
// declare inline functions
inline void randomFunction();

inline static void foo() {

// inline function definition has to be in the same file as the function call (internal linkage)
//
// inline function is an exception to the rule of not placing executable code in the header file
//
// _Noreturn
//
// informing the compiler that a particular program will not return control to the calling program
// when it completes execution
//
// informing the user helps to prevent misuse of the function
// informint the compiler may enable it to make some code optimizations
//
// exit() is a good example
// * once exit() is called, the calling function never resumes
//
// if a _Noreturn function specifier violates its promise and everntually returns to its caller
// the behavior is undefined
//
// provided by <stdnoreturn.h>
// _Noreturn or noreturn is the same
//
_Noreturn void f() {
 abort();
}

_Noreturn void g(int) {
  // causes undefined behavior if i <= 0
  if (i > 0) abort();
}
