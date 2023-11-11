// determine if input is whole number or NOT

#include <stdio.h>

int main() {
  float num;
  printf("Enter num: ");
  scanf("%f", &num);

  printf("\nresult: ");
  float temp = num - (int)num;

  if (temp == 0) {
    printf("%f is a whole number", num);
  } else {
    printf("%f is NOT a whole number", num);
  }
}