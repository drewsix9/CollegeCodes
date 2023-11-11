// Write a program that tells if 3 cards is a Blackjack or not.
// if sum of the 3 cards is 21, it is a blackjack.
// card values: 1 to 10
// 1 or 11:	1 is 11 if and only if the total of the cards is less than 21; 1 is 1 if and only if the total of the cards is greater than 21
#include <stdio.h>
#include <stdlib.h>

int main() {

  int num1, num2, num3, total;

  printf("Enter 3 Card Numbers\n\nEnter 1st Card:\t");
  scanf("%d", &num1);
  printf("Enter 2nd Card:\t");
  scanf("%d", &num2);
  printf("Enter 3rd Card:\t");
  scanf("%d", &num3);

  if ((num1 >= 1 && num1 <= 10) || (num2 >= 1 && num3 <= 10) || (num3 >= 1 && num3 <= 10)) {

    if (num1 + num2 + num3 >= 21) {
      if (num1 == 1) {
        num1 = 1;
      }
      if (num2 == 1) {
        num2 = 1;
      }
      if (num3 == 1) {
        num3 = 1;
      }
    }
    if (num1 + num2 + num3 < 21) {
      if (num1 == 1) {
        num1 = 11;
      }
      if (num2 == 1) {
        num2 = 11;
      }
      if (num3 == 1) {
        num3 = 11;
      }
    }
    total = num1 + num2 + num3;
    if (total == 21) {
      printf("\n BLACKJACK!!! \n");
    } else {
      printf("\n%d Not a blackjack\n", total);
    }

  } else {
    printf("\n Error \n");
  }

  return 0;
}