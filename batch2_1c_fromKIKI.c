#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])

{
  float num, x, orig;
  int input, num1, num2, i, j, k, s, array[100], COUNT = 0, rem, newnum1, oct, remain, rev;
  printf("How many numbers:");
  scanf("%d", &input);

  for (i = 1; i <= input; i++) {
    scanf("%f", &num);
    orig = num;
    x = num - (int)num; // for determining whole num

    if (x == 00.00) {
      num1 = (int)num;
      num2 = num1;
      for (j = 1; num1 != 0; j++) // for storing digits
      {
        array[j] = num1 % 10;
        num1 = num1 / 10;
      }
      j--;
      COUNT = 0;
      for (k = 1; k <= j; k++) {
        if (array[k] >= 5) {
          for (s = 1; s <= j; s++) {
            if (array[k] == array[s]) {
              COUNT++;
            }
          }
        }
      }
      if (COUNT > 1) {
        oct = 0;
        newnum1 = 0;
        for (; num2 != 0;) {
          rem = num2 % 8;
          num2 = num2 / 8;
          newnum1 = newnum1 * 10 + rem;
        }
        for (; newnum1 != 0;) {
          remain = newnum1 % 10;
          rev = rev * 10 + remain;
          newnum1 /= 10;
        }
        printf("%d", rev);
      } else {
        printf("%f", orig);
      }
    } else {
      printf("%.2f", orig);
    }
  }
  return 0;
}