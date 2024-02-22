#include <stdio.h>

int main() {
  int size;
  printf("Input the sisze of array: ");
  scanf("%d", &size);
  int arr[size];
  for (int i = 0; i < size; i++) {
    printf("element - %d : ", i);
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      arr[i] = 0;
    } else {
      arr[i] = 1;
    }
  }

  printf("\nElements of array after replacement:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}