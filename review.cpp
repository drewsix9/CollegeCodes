#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 123.345
// 12.45

int main() {
  char str[100];
  printf("Enter input: ");
  fgets(str, 100, stdin);
  int size = strlen(str);

  int freq[10];
  for (int i = 0; i < 10; i++) {
    freq[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    if (isdigit(str[i])) {
      int num = str[i] - '0';
      freq[num]++;
    }
  }

  for (int i = 0; i < size; i++) {
    if (isdigit(str[i])) {
      int num = str[i] - '0';
      if (freq[num] <= 1) {
        printf("%c", str[i]);
      }
    } else {
      printf("%c", str[i]);
    }
  }
}