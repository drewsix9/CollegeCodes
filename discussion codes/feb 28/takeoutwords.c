#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100];
  gets(str);
  int size = strlen(str);
  int pos_space = 0;
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = i; j < size; j++) {
      if (str[j] != ' ') {
        count++;
        i++;
      } else {
        pos_space = j;
        break;
      }
    }
    printf("read the word it had %d letters\n", count);
  }
  return 0;
}