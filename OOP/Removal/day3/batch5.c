#include <math.h>
#include <stdio.h>

/*
    Print only if it has 2 or more primes (after breaking)
    digit: 2
    1 1234 12 1415623 121131 397
    1415623 121131
*/
int isPrime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int size, arr[100], digits;
  printf("Enter number of inputs: ");
  scanf("%d", &size);
  printf("Enter inputs: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter number of digits: ");
  scanf("%d", &digits);

  printf("\nEnter output: ");
  for (int i = 0; i < size; i++) {
    int num = arr[i];
    int divisor = pow(10, digits), rem;

    int prime = 0;

    while (num > 0) {
      rem = num % divisor;

      int temp = rem;
      int count = 0;
      while (temp > 0) {
        temp /= 10;
        count++;
      }
      if (count == digits) {
        if (isPrime(rem)) {
          prime++;
        }
      }
      num /= divisor;
    }
    if (prime >= 2) {
      printf("%d ", arr[i]);
    }
  }
}