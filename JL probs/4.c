// swap the first and last digits

#include <stdio.h>

int main() {
  int num;
  printf("Enter number (base 10): ");
  scanf("%d", &num);

  printf("\nresult (base 2): ");

  int sum = 0, prod = 0, pow = 1;
  while (num > 0) {
    prod = (num % 2) * pow;
    pow *= 10;
    sum += prod;
    num /= 2;
  }
  printf("%d", sum);
}