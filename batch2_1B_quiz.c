// ask for float n numbers, 1,3,6,7
// get prime and comp
// if prime print in binary

#include <stdio.h>
#include <stdlib.h>

int main() {

  float num;
  int input;
  int factor = 0;

  printf("Enter how many inputs:\t");
  scanf("%d", &input);
  for (int i = 1; i <= input; i++) {

    factor = 0;
    printf("Enter num:\t");
    scanf("%f", &num);

    for (int j = 2; j < (int)num; j++) {

      if ((int)num % j == 0) {
        factor++;
      }
    }

    float temp = num - (int)num;

    if (factor == 0) { // PRIME

      if (temp != 0) {

        printf("\n%.2f\n\n", num);
      }
      int quot, rem;

      if (temp == 0) {
        int temp1 = (int)num;
        int binary[32];
        int count = 0;

        while (temp1 > 0) {
          binary[count] = temp1 % 2;
          temp1 /= 2;
          count++;
        }

        for (int i = count - 1; i >= 0; i--) {
          printf("%d", binary[i]);
        }
        printf("\n");
      }
    } else { // COMPOSITE
      printf("\n%.2f\n\n", num);
    }
  }
  return 0;
}
