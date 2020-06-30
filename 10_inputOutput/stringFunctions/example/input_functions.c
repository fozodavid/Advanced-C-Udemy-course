//char *gets(char *str): NEVER USE IT!

//fgets entire lines of data
//
//char *fgets(char *buffer, int n, FILE *stream);
//fgets also deprecated, cannot tell if the null character is included
//only use fgets if you are certain your data cannot contain a null character
//otherwise, use getline
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_MAX 10

int with_fgets() {
  char buf[LINE_MAX];
  int ch = '\0';
  char *p = NULL;

  if (fgets(buf, sizeof(buf), stdin)) { // QUESTION: Where is the LOOP????
    p = strchr(buf, '\n');
    if (p) {
      *p = '\0';
    } else {
      while (((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin));
    }

  } else {
    printf("ERROR!");
  }
  printf("%s", buf);
  return 0;
}

// using getline latest around 2010
// ssize_t getline(char **buffer, size_t *size, FILE *stream);
//
// the first parameter is a pointer to a block allocated with malloc or calloc (type char **)
// the address of the first character position where the input string will be stored
// this pointer type ( a pointer-pointer) causes massive confusion
// will automatically enlarge the block of memory as needed(realloc)
// there is never a shortage of space (why getline is so safe)
// will contain the line read by getline when it returns
//
// the second parameter is a pointer to a variable of type size_t
// specifies the size in bytes of the block of memory pointed to by the first parameter
// the address of the variables that holds the size of the input buffer, another pointer
int with_getline() {
  char * buffer = NULL; // can be char buffer[32]; char *b = buffer;
  size_t bufsize = 32;
  size_t characters;

  buffer  = (char *)malloc(bufsize * sizeof(char)); // no need in the alternative
  if (buffer == NULL) {
    exit(1);
  }

  characters = getline(&buffer, &bufsize, stdin);
  printf("You typed %zu characters.", characters);
  return 0;
}
