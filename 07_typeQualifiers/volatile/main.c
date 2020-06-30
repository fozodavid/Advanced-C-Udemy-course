// volatile type qualifier
// optimizer must be careful to reload the variable every time it is used
// value can change unexpectantly
// only 3 types of variables should use volatile
//
// memory-mapped peripheral registers
// global variables (non stack variables) modified by an interrupt service routine
// global variables accessed by multiple tasks within a multi-threaded application

#include <stdio.h>

int main() {
  volatile int loc1; /* loc1 is a volatile location */
  volatile int * ploc; /* ploc points to a volatile location */
}

void example () {
  int x = 0;
  int val1 = x;
  
  /* some code not using x */

  int val2 = x;
  // smart optimizing compiler might notice that you use x twice without changing it's value
  // would temporarily store the x value in a register
  // when x is needed for val2, it can save time by reading the value from a register instead
  // of from the original memory location
  //
  // this optimization is not desired if x is changed between the two statements by some other agency
  // like interrupts
  //
  // you would use the volatile keyword to ensure that the compiler does not optimize and instead
  // has a stored value for each variable

}

void outPortExample() {

  volatile char *outPort;

  *outPort = 'O';
  *outPort = 'N';

}

// using volatile with const
// value can be both const and volatile
// * something should not be changed by the program
// * something should not be changed by an agency other than the program
// volatile const int loc;
// const volatile int * ploc;
