// two command line arguments
// * first is a character
// * second is a filename
//
// print only those line containing the given character
// assume no line is more than 256 characters long
//
// use fgets or getline or both
// use puts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
  FILE * fp = NULL;
  char * buffer = NULL;
  size_t bufsize = 256;
  int line_buf_size = 0;
  char ch = '\0';

  buffer = (char *)malloc(bufsize * sizeof(char));
  if (buffer == NULL) {
    puts("Malloc Error");
    exit(EXIT_FAILURE);
  }

  if( argc != 3 ) {
    fprintf(stderr, "Usage: %s [character] [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  ch = *argv[1];

  if ((fp = fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while (line_buf_size >= 0) {
    line_buf_size = getline(&buffer, &bufsize, fp);
    int i = 0;
    while (buffer[i] != '\0') {
      if (buffer[i] == ch) {
        puts(buffer);
        break;
      }
      i++;
    }
  }

  free(buffer);
  buffer = NULL;

  fclose(fp);

  return EXIT_SUCCESS;

}
