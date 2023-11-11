#include <stdio.h>

// Function to find GCF of two integers using Euclidean Algorithm
int find_gcf(int a, int b) {
  int rem;
  while (1) {
    rem = a % b;
    if (rem == 0) {
      return b;
    }
    a = b;
    b = rem;
  }
}

int GCF(int a, int b) {
  int min = (a < b) ? a : b;
  for (int i = 2; i <= min; i++) {
    if (a % i == 0 && b % i == 0) {
      return i;
    }
  }
  return 1;
}

// Main function to test the find_gcf function
int main() {
  int num1, num2, gcf;
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  gcf = find_gcf(num1, num2);
  printf("The GCF of %d and %d is %d\n", num1, num2, gcf);
  printf("The LCM of %d and %d is %d\n", num1, num2, (num1 * num2) / gcf);

  return 0;
}
