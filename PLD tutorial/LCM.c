#include <stdio.h>

int main() {

  int num, sum = 0, prod = 0, pow = 1, temp;
  printf("\nEnter num: ");
  scanf("%d", &num);

  temp = num;
  while (temp > 0) {
    prod = (temp % 10) * pow;
    pow *= 2;
    sum += prod;
    temp /= 10;
  }

  printf("\nBinary: %d\nDecimal: %d", num, sum);

  return 0;
}