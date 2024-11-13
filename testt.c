#include <ctype.h>
#include <stdio.h>

int main() {
  printf("Enter input: ");
  char str[100];
  fgets(str, 100, stdin);

  int i = 0;
  while (str[i] != '\0') {
    if (isdigit(str[i])) {
      int num = str[i] - '0';
      if (i % 2 == 0) {
        printf("%d", num + 1);
      } else {
        printf("%d", num);
      }
    } else {
      printf("\nWrong input!");
      return 1;
    }
    i++;
  }
  return 0;
}