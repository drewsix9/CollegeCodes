#include <stdio.h>

int isBinary(char *str) {
  char *token = strtok(str, " ");
  while (token != NULL) {
    for (int i = 0; i < strlen(token); i++) {
      if (token[i] > '1') {
        return 0;
      }
    }
    token = strtok(NULL, " ");
  }
  return 1;
}

int deciToBin(int n) {
  int pow = 1, sum = 0;
  while (n > 0) {
    sum += (n % 2) * pow;
    pow *= 10;
    n /= 2;
  }
  return sum;
}

int main() {
  char str[100];
  int arr[100], num;
  int n = 0;
  printf("Enter numbers: ");
  fgets(str, 100, stdin);
  if (isBinary(str)) {
    printf("Binary inputs\n");
  } else {
    printf("Decimal inputs\n");
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}