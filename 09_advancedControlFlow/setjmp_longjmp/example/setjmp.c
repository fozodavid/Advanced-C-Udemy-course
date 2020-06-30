// setjump and longjmp
// implementing exception handling similar to try catch
//
// setjump is try
// longjmp is throw
//
// suppose there is an error deep down in a function nested in many other functions and error handling makes sense only in the top level function
//
// would be very tedious and awkward if all the functions in between had to return normally
// and evaluate return values
//
// would be very tedious if you used a global error variable to determine that further
// processing doesn't make sense or even would be bad
//
// similar to goto, but goto can only jump in the same function
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void myFunction () {
  printf("in myfunction() \n");
  longjmp(buf, 1);

  /* NOT REACHED */
  printf("you will never see this, because I longjmp's");

}

int main() {
  if (setjmp(buf)) {
    printf("back in main\n");
  } else {
    printf("first time through\n");
    myFunction();
  }
  return 0;
}

int main2() {
  int i = setjmp(buf);
  printf("i=%d\n", i);
  if (i != 0) exit(0);
  longjmp(buf, 42);
  printf("Does this line get printed?\n");
  return 0;
}

/*
switch (setjmp(jbuf)) {
  case 0:
    apple = *suspicious;
    break;
  case 1:
    printf("suspicious is indeed a bad pointer\n");
    break;
  default:
    die("unexpected value returned by setjmp");
}
*/

// usually bad idea
// only use it when you have total control of your environment
// some embedded platforms
// just like goto much harder understand
