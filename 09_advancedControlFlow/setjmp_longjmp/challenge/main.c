/*
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void error_recovery () {
  printf("Error\n");
  longjmp(buf, 1);
}

int main() {
  if(setjmp(buf)) {
    printf("gracefully handled\n");
  } else {
    error_recovery();
    printf("normal program flow\n");
  }
  return 0;
}
*/

#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery() {
  printf("detected an error\n");
  longjmp(buf, 1);
}

int main () {
  while(1) {
    if (setjmp(buf)) {
      printf("back in main\n");
      break;
    } else {
      error_recovery();
    }
  }

  return 0;
}
