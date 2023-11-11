#include <stdio.h>
#include <string.h>

/*
    sort the non-repeating numbers

    input: 5 10 2 7 5 2 2 8 10 12
    non-rep: 10 7 8 1 12
    output:5 10 2 7 5 2 2 8 10 12
*/

int main() {
  int size, arr[100], pos[100], n = 0;
  printf("Enter # of inputs: ");
  scanf("%d", &size);

  printf("Enter inputs: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  int freq[size];
  // sets all the values of freq[] to -1
  memset(freq, -1, size * sizeof(int));

  // frequency algorithm
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] == arr[j]) {
        // if naay ka pareha, matic zero ang value sa ila freq
        freq[i] = 0;
        freq[j] = 0;
      }
    }
    if (freq[i] != 0) {
      // if walay ka pareha, gi store iyang index sa pos[] array
      pos[n++] = i;
    }
  }

  // bubble sort non-repeating num with their respective positions
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[pos[i]] > arr[pos[j]]) {
        int temp = arr[pos[i]];
        arr[pos[i]] = arr[pos[j]];
        arr[pos[j]] = temp;
      }
    }
  }

  printf("\nOutput: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}