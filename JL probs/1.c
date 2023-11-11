// swap the first and last digits

#include <stdio.h>

int main() {
  int num, div = 1;
  printf("Enter num: ");
  scanf("%d", &num);

  while (div * 10 <= num) {
    div *= 10;
  }
  int left = num / div;
  int right = num % 10;
  num %= div;
  num -= right;
  num += (right * div) + left;
  printf("\nresult: %d", num);
} 