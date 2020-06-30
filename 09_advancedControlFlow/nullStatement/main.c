// expression statement with the expression is missing
/*

while ((*test++ = getchar ()) != '\n')
;  // substituting the body of the loop
// {} empty body is the same thing
//
// the following for statement copies characters from the standard input to the standard
// output until the end of file is encountered
for (; (c=getchar ()) != EOF; putchar(c))
;

// the next for statement counts the number of characters that appear in the standard output
//
for (count = 0; getchar () != EOF; ++count)
;

// the following loop copies the character string pointed to by from to the one pointed to by to
while ((*to++ = *from++) != '\0')

// in this case the inner else and null statement keeps the outer else from binding to the inner if
//
if (condition1)
  if (condition2)
    dosomething;
  else
    ;
else
  dosomethingelse();
*/
#include <stdio.h>

int main() {
  if (1)
    if (0)
      printf("inner if");
    else;
  else
    printf("outer else");
}
