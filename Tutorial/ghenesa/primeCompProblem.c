#include <stdio.h>
#include <string.h>

int deciToBin(int n) {
  int pow = 1, sum = 0;
  while (n > 0) {
    sum += (n % 2) * pow;
    pow *= 10;
    n /= 2;
  }
  return sum;
}

int binToDeci(int n) {
  int pow = 1, sum = 0;
  while (n > 0) {
    sum += (n % 10) * pow;
    pow *= 2;
    n /= 10;
  }
  return sum;
}

int isBinary(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int num = arr[i];
    while (num > 0) {
      if (num % 10 > 1) {
        return 0;
      }
      num /= 10;
    }
  }
  return 1;
}

void printBinary(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", deciToBin(arr[i]));
  }
}

void printDecimal(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", binToDeci(arr[i]));
  }
}

int main() {
  int arr[100], num;
  int n = 0;
  printf("Enter numbers: ");
  while (scanf("%d", &num) && !(num == 1 || num == 0)) {
    arr[n++] = num;
  }
  printf("Output: ");
  if (num == 1) { // expect all inputs to be decimal
    if (isBinary(arr, n)) {
      printf("Invalid Inputs");
      return 0;
    }
    printBinary(arr, n);
  } else if (num == 0) { // expect all inputs to be binary
    if (!isBinary(arr, n)) {
      printf("Invalid Inputs");
      return 0;
    }
    printDecimal(arr, n);
  }
}