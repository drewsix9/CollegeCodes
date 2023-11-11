// swap the first and last digits

#include <stdio.h>

int main() {
  int num;
  printf("Enter num: ");
  scanf("%d", &num);

  printf("\nresult: ");
  while (num > 0) {
    int rem = num % 10;
    printf("%d", rem);
    num /= 10;
  }
}