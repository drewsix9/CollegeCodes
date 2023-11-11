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

int main() {

  float num, temp = 0;
  int quot = 0, rem = 0;

  printf("Enter number:\t");
  scanf("%f", &num);

  temp = num - (int)num;

  if (temp == 0) {
    printf("\n");
    printf("%d is an integer", (int)num);
    printf("\n");

    for (;;) {
      quot = (int)num / 10;
      rem = (int)num % 10;
      printf("%d", rem);
      num = quot;
      if (quot == 0) {
        break;
      }
    }
    printf(" is the reverse form of the given number");
  } else {
    printf("\n%f is not an integer.", num);
  }
  return 0;
}
