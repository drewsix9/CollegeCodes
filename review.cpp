#include <stdio.h>
int main() {

  // declare variables and array
  int n, i;
  float num[100], sum = 0.0;

  // input number of elements
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  while (n > 100 || n < 1) {
    printf("ERROR! The number should in range of (1 to 100). \n");
    printf("Enter the number of elements again: ");
    scanf("%d", &n);
  }

  // input values per array element
  for (i = 0; i < n; i++) {
    printf("Enter value for element %d: ", i);
    scanf("%f", &num[i]);
    sum += num[i]; // sum = sum + num[i]|
  }

  // Sum of all values entered
  printf("The sum of array is: %.2f", sum);

  // Average of all values entered
  printf("\nThe average of array is: %.2f ", sum / n);
  return 0;
}