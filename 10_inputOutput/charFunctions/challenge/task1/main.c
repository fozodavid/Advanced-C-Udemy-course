// count the number of words and characters from file or standard input
// 0 or 1 command line argument
// * if there is one argument it is the name of the file
// * if there is no argument stdin is used
#include <stdio.h>
#include <stdlib.h>

int isword(char lc, char ch) {
  int is_white_space(char ch) { 
    return ch == '\n' || ch == ' ' || ch == '!' || ch == '.' || ch == ',';
  }
  return is_white_space(lc) && !is_white_space(ch);
}

int main(int argc, char *argv[]) {
  FILE * fp = NULL;

  if( argc == 2 ) {
     if ((fp = fopen(argv[1], "r")) == NULL) {
       fprintf(stderr, "Can't open %s\n", argv[1]);
       exit(EXIT_FAILURE);
     }
  } else if (argc == 1) {
     fp = stdin;
  } else {
    fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char ch = '\0';
  char lastchar = ' ';
  int words = 0;
  int characters = 0;

  while ((ch = getc(fp)) != EOF) {
    if (isword(lastchar, ch)) {
      words += 1;
    }
    characters += 1;
    lastchar = ch;
  }
  fclose(fp);

  printf("This text has %d words and %d characters.\n", words, characters);
}
