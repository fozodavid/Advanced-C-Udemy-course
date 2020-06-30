// input: set of numbers from a file and write even, odd and prime numbers output
//
// you can use either fscanf or (fgets and sscanf) to accomplish the above
//
// numbers.txt
//
// output:
// even number found: 4
// prime number found: 3
// odd number found: 9
//
#include <stdio.h>

enum labels{PRIME, EVEN, ODD, UNSET};

int set_label(long num) {
  long divider;
  if (num == 1) return PRIME;
  if (num == 2) return PRIME;
  if (num % 2 == 0) return EVEN;
  if (num <= 0) return ODD;


  for(divider = 3; divider <= num; divider += 2 ) {
    if ((num % divider == 0) && (num != divider))
      return ODD;
  }
  return PRIME;
}

int main() {
  FILE * fp = NULL;
  long number;
  int label;

  fp = fopen("numbers2.txt", "r");

  while (fscanf(fp, "%ld", &number) != EOF) {
    label = set_label(number);

    switch (label) {
      case PRIME:
        printf("Prime number found: %ld\n", number);
        break;
      case EVEN:
        printf("Even  number found: %ld\n", number);
        break;
      case ODD:
        printf("Odd   number found: %ld\n", number);
        break;
      default:
        printf("This shouldn't happen %ld\n", number);
    }
  }
  fclose(fp);

  return 0;
}
