#include <stdio.h>
#include <string.h>

/*
    print only the non-repeating number
    input: 123 3614517 2378164 261
    output: 123 2378164 261
*/

int main() {
  char str[100];
  printf("Enter string: ");
  gets(str);

  char *word = strtok(str, " ");
  while (word != NULL) {
    int isUnique = 1;
    int size = strlen(word);

    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (word[i] == word[j]) {
          isUnique = 0;
          break;
        }
      }
    }
    if (isUnique == 1) {
      printf("%s ", word);
    }
    word = strtok(NULL, " ");
  }
  return 0;
}