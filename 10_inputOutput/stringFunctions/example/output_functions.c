// puts
// puts() function is used to write a line to the output screen
// most convenient function for printing a simple message on standard output
// automatically appends a newline
//
// puts does not give us the function of formatting our string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int with_puts () {
  char string[40];

  strcpy(string, "Hello, how are you");
  puts(string);
  return 0;
}

// int fputs(const char *buffer, FILE *filePtr); does not add newline write to file

int main () {
  FILE *fp = NULL;

  fp = fopen("somefile.txt", "w");
  if (fp == NULL) {
    exit(1);
  }

  fputs("Hello there, I hope this article will help!", fp);
  fclose(fp);
  return 0;
}
