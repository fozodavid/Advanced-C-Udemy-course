// comma operator
//
// lowest precedence of any c operator
// acts as a sequence point
//
// binary operator that evaluates its first operand and discards the result
// then evaluates the second operand and returns this value (and type)
//
// because all operators in c produce a value, the value of the comma operator is that of the rightmost expression
//
// the comma operator can be used to separate multiple expressions anywhere
// that a valid c expression can be used
//
// the comma operator exists because there are times when you do not want to
// separate expressions with semicolons
//
#include <stdio.h>

int main() {
  while (i < 100)
    sum += data[i], ++i;

  int i(5, 10); // 10 is assigned to i

  int j = (f1(), f2());

  x = (y =3, (z= ++y + 2) + 5);

  for (i = 0, j=100; i!=10; ++i, j-=10) 
    printf("David"),
    printf("Fozo"),
    printf("Done"); // using comma here instead of semi-colon


  houseprice = 249,500; // mistake with the comma notation
  houseprice = 249; // c interprets it as a comma expression
  houseprice = 500;

  houseprice = (249, 500);

  char ch, date; // comma notation can be used as a separator
  int a = 1, b = 2;
  printf("%d:%d", x, y);

  void fun(x, y); // separators are not operators!

  return 0;
}
