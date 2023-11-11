#include <math.h>
#include <stdio.h>

/*
    print only if the sum of the breakdowns is prime (do not add up if the rem is less than given digit size)
    digit: 2
    1 1234 12 14156 1211
    14156 1211
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

  printf("Enter how many digits: ");
  scanf("%d", &digits);

  printf("\nOutput: ");
  for (int i = 0; i < size; i++) {
    int num = arr[i];
    int rem, sum = 0;
    int divisor = pow(10, digits);

    while (num > 0) {
      rem = num % divisor;

      int temp = rem;
      int count = 0;
      while (temp > 0) {
        temp /= 10;
        count++;
      }
      if (count == digits) // i check if ang current rem does have the same number of digit sa imo gi input na digits, before siya ma apil ug add
      {
        sum += rem;
      }
      num /= divisor;
    }
    if (isPrime(sum)) {
      printf("%d ", arr[i]);
    }
  }

  return 0;
}