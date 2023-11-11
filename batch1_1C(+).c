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
/*input kag 4 ka numbers nya dapat 2 ka composite ug 2 ka prime
nya sunod kay ma fraction dapat ang smallest prime / smallest composite
 ug largest prime / largest composite nya imo i add.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a1, a2, b1, b2, x, y, nume = 0, deno = 0;

  printf("Enter 2 prime numbers:");
  printf("\nEnter 1st prime number:\t");
  scanf("%d", &a1);

  int factor = 0;
  for (int i = 2; i < a1; i++) {
    if (a1 % i == 0) {
      factor++;
    }
  }
  if (factor == 0) {
    printf("\nEnter 2nd prime number:\t");
    scanf("%d", &b1);
    factor = 0;
    for (int j = 2; j < b1; j++) {
      if (b1 % j == 0) {
        factor++;
      }
    }
    if (factor == 0) {
      printf("\nEnter 2 composite numbers:");
      printf("\nEnter 1st composite number:\t");
      scanf("%d", &a2);
      factor = 0;
      for (int k = 2; k < a2; k++) {
        if (a2 % k == 0) {
          factor++;
        }
      }
      if (factor != 0) {
        printf("\nEnter 2nd composite number:\t");
        scanf("%d", &b2);
        factor = 0;
        for (int l = 2; l < b2; l++) {
          if (b2 % l == 0) {
            factor++;
          }
        }
        if (factor != 0) {
          int temp1, temp2;
          if (a1 > b1) { // swaps value if a1 > b1
            temp1 = a1;
            a1 = b1;
            b1 = temp1;
          }
          if (a2 > b2) { // swaps value if a2 > b2
            temp2 = a2;
            a2 = b2;
            b2 = temp2;
          }

          printf("\n%d/%d + %d/%d", a1, a2, b1, b2);

          if (a2 == b2) {

            nume = a1 + b1;
            deno = a2;
            printf("\n\nsum = %d/%d", nume, deno);

            if (nume == deno) {
              printf("\n1");
            }
          }
          if (a2 != b2) {
            int n1, m1;
            n1 = a2, m1 = b2;

            while (m1 != n1) { // loop to get the lcm, source: stackoverflow :)
              if (m1 > n1) {
                n1 += a2;
              } else {
                m1 += b2;
              }
            }
            int a3, b3;
            deno = m1;
            a3 = deno / a2;
            x = a3 * a1;
            b3 = deno / b2;
            y = b3 * b1;
            nume = x + y;

            printf("\nLCM is %d", m1);
            printf("\n\nsum = %d/%d", nume, deno);
          }

        } else if (factor == 0) {
          printf("\n%d is not a composite number", b2);
        }
      } else if (factor == 0) {
        printf("\n%d is not a composite number", a2);
      }
    } else if (factor != 0) {
      printf("\n%d is not a prime number", b1);
    }

  } else if (factor != 0) {
    printf("\n%d is not a prime number", a1);
  }

  return 0;
}
