#include <stdio.h>

int main(void) {
  int n;
  printf("Enter the number of inputs: ");
  scanf("%d", &n);

  while (n-- > 0) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if there are any repeating digits in the number
    int digits[10] = {0};
    while (num > 0) {
      int digit = num % 10;
      if (digits[digit]++ > 0) {
        printf("%d\n", num);
        break;
      }
      num /= 10;
    }
  }

  return 0;
}