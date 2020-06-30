// fgetc and fputc functions
//
// write a c program to convert uppercase to lowercase and vice versa in a file
//
// command line argument to take a file or ask a user to provide the name
//
// create temporary file to store the result and
// then rename the temporary file back to the original file
// use isupper(ch) toupper(ch);
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define DATA_SIZE 1000

int main(int argc, char * argv[]) {
  FILE * fp;
  FILE * fwp;
  char filename[20];
  char ch = '\0';
  char data[DATA_SIZE];

  if( argc == 2 ) {
     fp = fopen(argv[1], "r");
  } else {
     printf("please provide file name: ");
     scanf("%s", filename);
     fp = fopen(filename, "r");
  }

  if (fp == NULL) {
    printf("Unable to create file.\n");
    exit(1);
  }

  fwp = fopen("tempfile.txt", "w");

  int counter = 0;
  while ((ch = fgetc(fp)) != EOF) {
    if (isupper(ch)) {
      data[counter] = tolower(ch);
    } else if (islower(ch)) {
      data[counter] = toupper(ch);
    } else {
      data[counter] = ch;
    }
    counter++;
  }
  fputs(data, fwp);
  fclose(fwp);

  fclose(fp);
  rename("tempfile.txt", "inputfile.txt");
  return 0;
}
