// sprintf
// string print formatted
//
// several data variables into a character array
// instead of printing on the console, you store output data to a char buffer (convert)
// conversion
//
// int sprintf(char *string, const char *format, ...);
// sprintf (string, "%d %c %f", value, char, float);
// 
// unsafe, doesn't check the length of the destination buffer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

void with_sprintf() {
  char string1[100];
  char string2[100];
  int a = 10, b = 20, c = 0;
  c = a + b;
  sprintf(string1, "Hello, this is the number: %d", 55);
  sprintf(string2, "The sum of %d and %d is %d", a, b , c);
  puts(string2);
}

// fprintf
// performs the same operation as printf(), but on a file
// * takes an additional argument
//   * the FILE pointer that identifies the file to which the data is to be written to
//
// int fprintf(FILE *stream, const char *format, ...);
//
// fprintf(outFile, "Hello, how are you?\n");
// fprintf(outFile, "my number is: %d\n", 555);
//
void with_fprintf() {
  FILE *f = NULL;
  char ch[100];

  if((f = fopen("notes.txt", "r+")) == NULL) {
    printf("Cannot open the file...");
    exit(1);
  }

  for (int i = 0; i < 10; i++) {
    fprintf(f, "The count number is %d\n", i+1);
  }

  fclose(f);
  if((f = fopen("notes.txt", "r+")) == NULL) {
    printf("Cannot open the file...");
    exit(1);
  }

  while (!feof(f)) {
    fgets(ch, 100, f);
    printf("%s", ch);
  }

  fclose(f);
}

// fprintf and stderr
// the reason stderr exists is so that error messages can be logged to a device or file other
// than where the normal output is written
// * particularly desirable when the program's output is redirected to a file
//   * the normal output is written into the file, but any system error messages still appear
//   in your window
//     * you might want to write your own error messages to stderr for this reason
//
//     if ((inFile = fopen("data", "r")) == NULL) {
//       fprintf(stderr, "Can't open data for reading\n");
//       ...
//     }

// fscanf
//
// fscanf() is to perform the same operations as the scanf() function, but, on a file
// * used to read formatted input (set of characters) from a file
// * most of the arguments of this function are same as scanf() function
//   * takes an additional argument, which is the FILE pointer that identifies the file
//   to which the data is to be read

void with_fscanf() {
  FILE *fp = NULL;
  char buff[255];

  fp = fopen("notes.txt", "r");

  while (fscanf(fp, "%s", buff) != EOF) {
    printf("%s ", buff);
  }
}

void with_fscanf2() {
  FILE *fp = NULL;
  char words[MAX];

  if ((fp = fopen("notes.txt", "a+")) == NULL) {
    fprintf(stdout, "Can't open file.\n");
    exit(EXIT_FAILURE);
  }

  puts("Enter words to add to the file; press the #");
  puts("key at the beginning of a line to terminate.");

  while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    fprintf(fp, "%s\n", words);

  puts("File contents");
  rewind(fp);
  while(fscanf(fp, "%s", words) == 1)
    puts(words);

  puts("Done!");
  if (fclose(fp) != 0)
    fprintf(stderr, "Error closing file\n");
}

// sscanf
//
// allows you to read formatted data from a string rather than standard input or keyboard
// int sscanf(const char * str, const char * control_string [arg_1, arg_2, ...]);
// sscanf(buffer, "%s %d", name, &age);

void with_sscanf() {
  char *str = "David Prog 33";
  char name[10], title[10];
  int age = 0, ret = 0;

  ret = sscanf(str, "%s %s %d", name, title, &age);

  printf("Name: %s\n", name);
  printf("Title: %s\n", title);
  printf("Age: %d\n", age);

}

// using fscanf vs. fgets()/sscanf
//
// if you use fgets() + sscanf(), you must enter both values on the same line
//
// if you only use fscanf() on stdin, it will read them off different lines if it does not
// find the second value on the first line you entered
//
// if you read a line that you are unable to parse with sscanf() after having read it using
// fgets() your program can simply discard the line and move on
//
// if you read a line using fscanf(), when it fails to convert fields, it leaves all the input 
// on the stream
// * so, if you failed to read the input you wanted, you would have to go and read all the data 
//   you want to ignore yourself
//
// You can use fscanf() by itself, however, you may be able to avoid some
// headaches by using fgets() + sscanf()
//
// there is no difference between fscanf() vs. fgets/sscanf() when
// * input data is well-formed
// * two types of errors occur
//   * I/O and format
//   * fscanf() simultaneously handles these two error types in one function but offer few recovery options
//   * fgets() and sscanf() allow logical separation of I/O issues from format ones and thus better recovery
// * only 1 parsing path
// * separating I/O from scanning allows multiple sscanf() options
//   * if a given scanning of a buffer does not produce the desired results, other sscanf() calls with different formats are available
//   no embedded '\0'
//   * rarely does '\0' occur, but should one occur, sscanf() will not see it as scanning stops with its occurence, whereas fscanf() continues

// fflush
// the fflush function is used to flush/clean a file or buffer
// * causes any unwritten data in the output buffer to be sent to the output file
//   * causes any unwritten data in the output buffer to be sent to the output file
//     * this process is called flushing a buffer
//   * cleans the buffer (making empty) if it has been loaded with any other data already
//
//   int fflush(FILE *fp);
//   fflush(buffer);
//
//   using fflush on an input stream is undefined


int main() {
  with_sscanf();
  return 0;
}
