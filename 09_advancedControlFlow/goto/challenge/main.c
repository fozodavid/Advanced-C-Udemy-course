#include <stdio.h>

int main () {
  int value = 5;
  int i = 1, j, k = 0;

  outerLoop:
    if (i < value) {
      j = i;

      innerLoop: 
        if (j < value) {
          printf(" ");
          j++;
          goto innerLoop;

      } else {
        innerLoop2: 
          if (k != ((2 * i))) {
            if (k == 0 || k == (2 * i) - 3) {
              printf("*");
            }
            printf(" ");
            k++;
            goto innerLoop2;
          }
          k = 0;
          printf("\n");
          i++;
          goto outerLoop;
      }
    } else {
      i = 0;
      loop:

      if (i < (2 * value) - 1) {
        printf("*");
        i++;
        goto loop;
      }
    }
  return 0;
}

/*
int main() {
  // printf("____*____\n\n");
  // printf("___*_*___\n\n");
  // printf("__*___*__\n\n");
  // printf("_*_____*_\n\n");
  // printf("*********\n\n");

  int i;
  for (i = 4; i > -1; --i) {
    int spaces;
    for (spaces = i; spaces > 0; spaces--) {
      printf("_");
    }
    printf("*");
    for (spaces = 4 - i; spaces > 0; spaces--) {
      printf("_");
    }
    printf("*");
    for (spaces = i; spaces > 0; spaces--) {
      printf("_");
    }
    printf("\n\n");
  }
  return 0;
}
*/
