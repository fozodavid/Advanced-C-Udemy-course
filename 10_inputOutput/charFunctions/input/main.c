#include <stdio.h>

int with_getc_file();
int with_getc_stdin();
int with_getchar();
int with_ungetc();

// int ungetc(int ch, FILE* stream); push characters back into the input stream

int main () {
  with_ungetc();
}

int with_getc_file() {
  char ch = '\0';
  FILE *fp;
  
  if (fp = fopen("dummy_file.txt", "rw")) {
    ch = getc(fp);

    while (ch != EOF) {
      ch = getc(fp);
    }
    fclose(fp);
  }

  return 0;
}

int with_getc_stdin() {
  char ch = '\0';

  ch = getc(stdin);
  printf("read in character %c", ch);

  return 0;
}

int with_getchar() {
  char ch = 0; // if you use EOF store charactere in integers

  while ((ch = getchar()) != EOF) {
    printf("%c\n", ch);

  }

  return 0;
}

int with_fgetc() {
  FILE *fp = NULL;
  char c = '\0';
  
  fp = fopen("dummy_file.txt", "r"); // opening an existing file

  if (fp == NULL) {
    printf("Could not open file dummy_file.txt\n\n");
    return 1;
  }

  printf("Reading the file dummy_file.txt\n\n");
  while (c != EOF) {
    c = fgetc(fp);
    printf("%c", c);
  }
  fclose(fp);

  return 0;
}

int with_ungetc() {
  char ch = 0;
  while(' ' == (ch = (char)getchar()));
  ungetc(ch, stdin);

  printf("char is '%c'\n", getchar());
  return 0;
}


