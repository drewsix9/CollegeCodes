// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
// Alt + up/down - to move the line of code up or down
//--------------------------------
#include <stdio.h>
#include <stdlib.h>

int reversed(int n);

int main() {

  float num, temp = 0;
  int rem = 0, rev = 0;

  printf("Enter number:\t");
  scanf("%f", &num);

  temp = num - (int)num;

  if (temp == 0) {
    printf("\n %d is an integer\n ", (int)num);

    //		while(num>0) {
    //			rem=(int)num%10;
    //			rev=rev*10+rem;
    //			num=(int)num/10;
    //		}

    rev = reversed(num);

    printf("%d is the reverse form of the given number", rev);
  } else {
    printf("\n%f is not an integer.", num);
  }
  return 0;
}

int reversed(int n) {
  int rem = 0, rev = 0;
  while (n > 0) {
    rem = (int)n % 10;
    rev = rev * 10 + rem;
    n = (int)n / 10;
  }
  return rev;
}