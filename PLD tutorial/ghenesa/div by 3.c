#include <stdio.h>

int main() {
  while (1) {
    int a, b, c;
    printf("\n\nEnter num1: ");
    scanf("%d", &a);
    printf("\nEnter num2: ");
    scanf("%d", &b);
    printf("\nEnter num3: ");
    scanf("%d", &c);

    (!(a % 3) && !(b % 3) && !(a % 3)) ? printf("\nTrue") : printf("\nFalse");

    // pwede sad ni vvv
    // if (a % 3 == 0 && b % 3 == 0 && c % 3 == 0) {
    //   printf("\nTrue");
    // } else {
    //   printf("\nFalse");
    // }
  }
  return 0;
}