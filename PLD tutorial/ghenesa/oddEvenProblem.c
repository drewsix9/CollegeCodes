#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OddCase(int curr) {
  char convertedToString[10];
  sprintf(convertedToString, "%d", curr);
  int nlen = strlen(convertedToString);
  for (int j = 0; j < nlen; j++) {
    int temp = convertedToString[j] - '0';
    printf("%d", temp + 1);
  }
  printf(" ");
}

int main() {
  int arr[100];
  int n = 0, num;
  printf("Enter numbers (0 to stop): ");
  while (scanf("%d", &num) && num != 0) {
    arr[n++] = num;
  }

  printf("Output: ");
  for (int i = 0; i < n; i++) {
    int curr = arr[i];
    if (curr % 2 > 0) { // odd
      OddCase(curr);
    } else { // even
      printf("%d ", curr);
    }
  }

  return 0;
}