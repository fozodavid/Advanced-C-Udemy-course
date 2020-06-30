// put('\n', stdout); single character to a file
#include <stdio.h>

int with_putc() {
  char ch = '\0';
  FILE *fp = NULL;

  if (fp = fopen("../assets/dummy_file.txt", "rw")) {
    ch = getc(fp);
    while (ch != EOF) {
      printf("%c", ch);
      putc(ch, fp);
      ch = getc(fp);
    }
    fclose(fp);
  }

  return 0;
}

void with_putc_stdout() {
  char ch = 'd';

  putc(ch, stdout);
}

void with_putchar() {
  char string[] = "Hello David. \nLearning C!";
  int i = 0;
  
  while ( string[i] != '\0') {
    if(string[i] != '\0') {
      putchar(string[i]);
      ++i;
    }
  }
}

void with_putchar2() {
  int ch = 0;
  while ((ch = getchar()) != EOF) {
    putchar(ch);
  }
  ungetc(ch, stdin);
  printf("Trank you!\n");
}

void with_fputc() {
  FILE * pFile;
  char c = '\0';

  pFile = fopen("../assets/dummy_file2.txt", "w");

  if (pFile != NULL) {
    for (c = 'A'; c <= 'Z'; c++) {
      fputc(c, pFile);
    }
    fclose(pFile);
  }
}

int main() {
  with_fputc();
  return 0;
}
